<?php

include_once(DRUPAL_ROOT . '/profiles/stanford/stanford.profile');

/*
 * Implementation of hook_install_tasks().
 */

function stanford_dept_install_tasks($install_state) {
  $tasks = stanford_install_tasks($install_state);

  // Any and all environment tasks go here.
  $tasks['stanford_dept_profile_theme'] = array(
    'display_name' => st('Do theme tasks for dept after stanford.'),
    'display' => FALSE,
    'type' => 'normal',
    'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
  );

  return $tasks;
}

/**
 * Install the stanford_framework theme
 * @param  [type] $install_state [description]
 * @return [type]                [description]
 */
function stanford_dept_profile_theme(&$install_state) {
  theme_enable(['stanford_framework']);
  variable_set("theme_default", "stanford_framework");
}

/**
 * Final installation task.
 */
function stanford_dept_install_finished() {
  stanford_install_finished();
}

/**
 * Implements hook_system_info_alter().
 *
 * @param array $info
 *   The .info file contents, passed by reference so that it can be altered.
 * @param array $file
 *   Full information about the module or theme, including $file->name, and
 *   $file->filename.
 * @param string $type
 *   Either 'module' or 'theme', depending on the type of .info file that was
 *   passed.
 */
function stanford_dept_system_info_alter(&$info, $file, $type) {
  // Run everything that we alter in "stanford".
  stanford_system_info_alter($info, $file, $type);

  // Allow a few themes to be enabled by revealing them in the UI.
  if (
    isset($info['project']) &&
    ($info['project'] == 'stanford_framework' ||
    $info['project'] == 'stanford_jordan' ||
    $info['project'] == 'stanford_wilbur')
  ) {
    $info['hidden'] = FALSE;
    return;
  }
}
