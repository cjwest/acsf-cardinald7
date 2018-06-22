<?php

include_once(DRUPAL_ROOT . '/profiles/stanford/stanford.profile');

/*
 * Implementation of hook_install_tasks().
 */

function stanford_dept_install_tasks($install_state) {
  $tasks = stanford_install_tasks($install_state);
  return $tasks;
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
  stanford_system_info_alter($info, $file, $type);

  // Allow a few themes from being enabled by hiding them from the UI.
  if (
    isset($info['project']) &&
    $info['project'] == 'cube' ||
    $info['project'] == 'rubik' ||
    $info['project'] == 'tao')
  ) {
    $info['hidden'] = FALSE;
    return;
  }
}
