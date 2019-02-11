<?php
/**
 * @file
 * stanford_opportunity.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function stanford_opportunity_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer default image node:stanford_opportunity:field_s_opp_image'.
  $permissions['administer default image node:stanford_opportunity:field_s_opp_image'] = array(
    'name' => 'administer default image node:stanford_opportunity:field_s_opp_image',
    'roles' => array(),
    'module' => 'default_image_ft',
  );

  // Exported permission: 'create stanford_opportunity content'.
  $permissions['create stanford_opportunity content'] = array(
    'name' => 'create stanford_opportunity content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any stanford_opportunity content'.
  $permissions['delete any stanford_opportunity content'] = array(
    'name' => 'delete any stanford_opportunity content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own stanford_opportunity content'.
  $permissions['delete own stanford_opportunity content'] = array(
    'name' => 'delete own stanford_opportunity content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in stanford_opp_city'.
  $permissions['delete terms in stanford_opp_city'] = array(
    'name' => 'delete terms in stanford_opp_city',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in stanford_opp_location'.
  $permissions['delete terms in stanford_opp_location'] = array(
    'name' => 'delete terms in stanford_opp_location',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in stanford_opp_major'.
  $permissions['delete terms in stanford_opp_major'] = array(
    'name' => 'delete terms in stanford_opp_major',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in stanford_opp_open_to'.
  $permissions['delete terms in stanford_opp_open_to'] = array(
    'name' => 'delete terms in stanford_opp_open_to',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in stanford_opp_sponsor'.
  $permissions['delete terms in stanford_opp_sponsor'] = array(
    'name' => 'delete terms in stanford_opp_sponsor',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in stanford_opp_time_of_year'.
  $permissions['delete terms in stanford_opp_time_of_year'] = array(
    'name' => 'delete terms in stanford_opp_time_of_year',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in stanford_opp_type'.
  $permissions['delete terms in stanford_opp_type'] = array(
    'name' => 'delete terms in stanford_opp_type',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit any stanford_opportunity content'.
  $permissions['edit any stanford_opportunity content'] = array(
    'name' => 'edit any stanford_opportunity content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own stanford_opportunity content'.
  $permissions['edit own stanford_opportunity content'] = array(
    'name' => 'edit own stanford_opportunity content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in stanford_opp_city'.
  $permissions['edit terms in stanford_opp_city'] = array(
    'name' => 'edit terms in stanford_opp_city',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in stanford_opp_location'.
  $permissions['edit terms in stanford_opp_location'] = array(
    'name' => 'edit terms in stanford_opp_location',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in stanford_opp_major'.
  $permissions['edit terms in stanford_opp_major'] = array(
    'name' => 'edit terms in stanford_opp_major',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in stanford_opp_open_to'.
  $permissions['edit terms in stanford_opp_open_to'] = array(
    'name' => 'edit terms in stanford_opp_open_to',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in stanford_opp_sponsor'.
  $permissions['edit terms in stanford_opp_sponsor'] = array(
    'name' => 'edit terms in stanford_opp_sponsor',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in stanford_opp_time_of_year'.
  $permissions['edit terms in stanford_opp_time_of_year'] = array(
    'name' => 'edit terms in stanford_opp_time_of_year',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in stanford_opp_type'.
  $permissions['edit terms in stanford_opp_type'] = array(
    'name' => 'edit terms in stanford_opp_type',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  return $permissions;
}
