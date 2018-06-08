<?php

/**
 * @file
 * Drush integration for the paranoia module.
 */

/**
 * Implements hook_drush_sql_sync_sanitize().
 */
function paranoia_drush_sql_sync_sanitize($site) {
  // Don't use DBTNG here so this mostly workis across old versions of Drupal.
  drush_sql_register_post_sync_op('flood',
    dt('Delete all flood table entries (contains IP address and event).'),
    "TRUNCATE flood;");
  drush_sql_register_post_sync_op('sessions',
    dt('Delete all sessions table entries (contains IP address and potentially sensitive arbitrary session data).'),
    "TRUNCATE sessions;");
  // This next one is a bit harsh.
  // The intent is to remove things like API keys or credentials for services.
  drush_sql_register_post_sync_op('variable_keys',
    dt('Remove variables that contain names that indicate potential sensitive data.'),
    "DELETE FROM variable WHERE name LIKE '%key%' OR name LIKE '%token%';");
  drush_sql_register_post_sync_op('history',
    dt('Remove history, which contains info on where users have browsed on a site.'),
    "TRUNCATE history;");
  // Since people may not enable the dblog module, ensure it exists first.
  drupal_bootstrap(DRUPAL_BOOTSTRAP_VARIABLES);
  if (db_table_exists('watchdog')) {
    drush_sql_register_post_sync_op('watchdog',
      dt('Watchdog usually contains user id, IP, e-mail addresses, filesystem paths.'),
      "TRUNCATE watchdog;");
  }
  drush_sql_register_post_sync_op('authmap',
    dt('Authmap correlates Drupal accounts to external services. The map may contain private data like emails.'),
    "TRUNCATE authmap;");
  drush_sql_register_post_sync_op('users_data',
    dt('The magical fairy puts a lot of junk into users.data. We cannot trust it to be only non-sensitive data. Dang magic.'),
    "UPDATE users SET data = '';");
  // Make the purging inactive users optional.
  if (variable_get('paranoia_delete_blocked_users', 1)) {
    drush_sql_register_post_sync_op('users_blocked',
      dt('Blocked user accounts may contain inappropriate information and are not accessible to the public in general.'),
      "DELETE FROM users WHERE status <> 1 AND uid NOT IN (0, 1);");
    drush_sql_register_post_sync_op('users_blocked_roles',
      dt('Blocked users were deleted, now lets delete their associated roles.'),
      "DELETE users_roles FROM users_roles LEFT JOIN users ON users_roles.uid = users.uid WHERE users.uid IS NULL;");
  }
  drush_sql_register_post_sync_op('email-in-username',
    dt('Sanitize email-based names in user table'),
    "UPDATE users SET name = uid WHERE name LIKE '%@%';");
  drush_sql_register_post_sync_op('cron-key',
    dt('Reset cron key'),
    "UPDATE variable SET value = NULL WHERE name = 'cron_key';");

  // Truncate core cache tables.
  $cache_tables = array(
    'cache',
    'cache_page',
    'cache_bootstrap',
    'cache_field',
    'cache_filter',
    'cache_form',
    'cache_menu',
    'cache_path',
  );
  if (db_table_exists('cache_block')) {
    $cache_tables[] = 'cache_block';
  }
  if (db_table_exists('cache_update')) {
    $cache_tables[] = 'cache_update';
  }
  $trucate_caches_query = implode(';', preg_filter('/^/', 'TRUNCATE ', $cache_tables)) . ';';
  drush_sql_register_post_sync_op('core_cache_tables',
    dt('Truncate core cache tables.'),
    $trucate_caches_query);
}

/**
 * Implements hook_drush_help().
 */
function paranoia_drush_help($command) {
  switch ($command) {
    case 'drush:paranoia-reset-stale-accounts':
      return dt('Queue accounts to have their passwords reset if they have not logged in recently.');
  }
}

/**
 * Implements hook_drush_command().
 */
function paranoia_drush_command() {
  return array(
    'paranoia-reset-stale-accounts' => array(
      'description' => dt('Queue accounts to have their passwords reset if they have not logged in recently.'),
      'options' => array(
        'limit' => dt('Limit the number of accounts to queue in one run.'),
      ),
    ),
    'paranoia-list-projects-to-delete' => array(
      'description' => 'Prints out unused project (module and theme) directories so they can be deleted.',
      'options' => array(
        'remove-lots-risky-htaccess' => 'Remove a lot of extra files including some that might be important like the .htacccess.',
      ),
    )
  );
}

/**
 * Drush callback to queue stale accounts to have their passwords reset.
 */
function drush_paranoia_reset_stale_accounts() {
  $queue = DrupalQueue::get('paranoia_stale_expirations');
  $limit = drush_get_option('limit', FALSE);

  // Don't add to the queue if there are remaining items to be processed, to
  // avoid duplicate queue items if the cron queue iterator from a previous
  // cron run has not gotten through all of its queued items.
  if ($queue->numberOfItems() > 0) {
    watchdog('paranoia', 'Skipping adding items to the queue as stale expiration items already exist.');
    return;
  }

  // Check for accounts whose last access time is older than the threshold,
  // which defaults to 2 years (365 * 2 = 730 days).
  $offset = REQUEST_TIME - (variable_get('paranoia_access_threshold', 730) * 60 * 60 * 24);
  $query = db_select('users', 'u')
    ->fields('u', ['uid'])
    ->condition('uid', 0, '>')
    ->condition('created', $offset, '<')
    ->condition('access', $offset, '<')
    ->condition('login', $offset, '<')
    ->condition('pass', 'ZZZ%', 'NOT LIKE');
  if ($limit !== FALSE) {
    $query->range(0, $limit);
  }
  $result = $query->execute();

  $count = 0;
  foreach ($result as $record) {
    $count++;
    $queue->createItem($record->uid);
  }
  drush_log(dt('Queued @count users to have their password reset', array('@count' => $count)), 'ok');
  watchdog('paranoia', 'Queued @count users to have their password reset', array('@count' => $count));
}

/**
 * Callback for paranoia-list-projects-to-delete.
 *
 * Deletes directories and files for unused projects.
 */
function drush_paranoia_list_projects_to_delete() {
  // TODO: also handle profiles?
  // Get a list of all projects that are not profiles.
  $all_projects = db_query("SELECT name, filename, status, type FROM {system} WHERE filename not like '%.profile' ORDER BY filename ASC")->fetchAllAssoc('name');
  $enabled_parent_dirs = $disabled_projects = array();
  $themes = list_themes();

  // Allow a site to declare modules to keep. Handy if the site disables
  // modules in a backup process.
  $modules_to_keep = module_invoke_all('paranoia_get_required_modules');

  // Get a list of directories that are the parent for enabled projects.
  foreach ($all_projects as $project) {
    // Themes list their .info file.
    $file_type = $project->type == 'module' ? 'module' : 'info';
    $project->directory = str_replace($project->name . '.' . $file_type, '', $project->filename);
    if ($project->status
      || ($project->type == 'theme' && drupal_theme_access($project->name))
      || in_array($project->name, $modules_to_keep)) {
      $enabled_parent_dirs[$project->name] = $project->directory;
    }
    else {
      $disabled_projects[$project->name] = $project->directory;
    }
  }

  // Include base themes on enabled themes in list dirs in use.
  foreach ($all_projects as $project) {
    if ($project->type == 'theme' && isset($themes[$project->name]) && drupal_theme_access($project->name) && !empty($themes[$project->name]->base_theme)) {
      // Mark it enabled for sure.
      $enabled_parent_dirs[$themes[$project->name]->base_theme] = $all_projects[$themes[$project->name]->base_theme]->directory;
      // Unset it from disabled in case it is.
      unset($disabled_projects[$themes[$project->name]->base_theme]);
    }
  }

  $dirs_to_delete = array();
  $common_types = array('inc', 'admin.inc', 'module', 'info', 'install');

  foreach ($disabled_projects as $disabled_project_name => $disabled_project_dir) {
    // Only remove a directory if it's not the beginning (strpos) of an enabled dir.
    if (!_paranoia_dir_is_beginning_of_dirs($disabled_project_dir, $enabled_parent_dirs)) {
      // Make a list. Use the dir as key to remove dups.
      $dirs_to_delete[$disabled_project_dir] = $disabled_project_dir;
    }
    else {
      // For disabled projects that *do* match the parent directory, at least
      // some files can be deleted. Print those.
      foreach ($common_types as $type) {
        if (file_exists("$disabled_project_dir$disabled_project_name.$type")) {
          echo "rm -f $disabled_project_dir$disabled_project_name.$type" . PHP_EOL;
        }
      }
    }
  }

  // Print an 'rm -rf' for the parent directory of disabled projects.
  foreach ($dirs_to_delete as $dir_to_delete) {
    echo 'rm -rf ' . $dir_to_delete . PHP_EOL;
  }

  // A few bonus things that might break a site.
  $risky = drush_get_option('remove-lots-risky-htaccess', FALSE);
  if ($risky) {
    echo "rm -f scripts/" . PHP_EOL;
    echo "rm -f profiles/testing" . PHP_EOL;
    echo "rm CHANGELOG.txt COPYRIGHT.txt INSTALL.mysql.txt INSTALL.pgsql.txt INSTALL.sqlite.txt INSTALL.txt LICENSE.txt MAINTAINERS.txt README.txt UPGRADE.txt authorize.php cron.php install.php update.php web.config xmlrpc.php .htaccess .gitignore" . PHP_EOL;
  }

}

/**
 * Checks to see which dirs are the beginning of an enabled dir.
 *
 * @param string $disabled_project_dir
 *   The disabled project directory.
 * @param array $enabled_parent_dirs
 *   An array of strings listing directories with enabled projects.
 *
 * @return bool
 *   True if the disabled dir is the beginning of any of the enabled dirs.
 */
function _paranoia_dir_is_beginning_of_dirs($disabled_project_dir, $enabled_parent_dirs) {
  foreach ($enabled_parent_dirs as $enabled_parent_dir) {
    if (strpos($enabled_parent_dir, $disabled_project_dir) === 0) {
      return TRUE;
    }
  }
  return FALSE;
}
