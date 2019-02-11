<?php
/**
 * @file
 * stanford_opportunity_importer.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function stanford_opportunity_importer_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'clear stanford_opportunity_helper feeds'.
  $permissions['clear stanford_opportunity_helper feeds'] = array(
    'name' => 'clear stanford_opportunity_helper feeds',
    'roles' => array(),
    'module' => 'stanford_opportunity_importer',
  );

  // Exported permission: 'create stanford_opportunity_importer content'.
  $permissions['create stanford_opportunity_importer content'] = array(
    'name' => 'create stanford_opportunity_importer content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any stanford_opportunity_importer content'.
  $permissions['delete any stanford_opportunity_importer content'] = array(
    'name' => 'delete any stanford_opportunity_importer content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own stanford_opportunity_importer content'.
  $permissions['delete own stanford_opportunity_importer content'] = array(
    'name' => 'delete own stanford_opportunity_importer content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any stanford_opportunity_importer content'.
  $permissions['edit any stanford_opportunity_importer content'] = array(
    'name' => 'edit any stanford_opportunity_importer content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own stanford_opportunity_importer content'.
  $permissions['edit own stanford_opportunity_importer content'] = array(
    'name' => 'edit own stanford_opportunity_importer content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'import stanford_opportunity_helper feeds'.
  $permissions['import stanford_opportunity_helper feeds'] = array(
    'name' => 'import stanford_opportunity_helper feeds',
    'roles' => array(),
    'module' => 'stanford_opportunity_importer',
  );

  // Exported permission: 'tamper stanford_opportunity_helper'.
  $permissions['tamper stanford_opportunity_helper'] = array(
    'name' => 'tamper stanford_opportunity_helper',
    'roles' => array(),
    'module' => 'stanford_opportunity_importer',
  );

  // Exported permission: 'unlock stanford_opportunity_helper feeds'.
  $permissions['unlock stanford_opportunity_helper feeds'] = array(
    'name' => 'unlock stanford_opportunity_helper feeds',
    'roles' => array(),
    'module' => 'stanford_opportunity_importer',
  );

  return $permissions;
}
