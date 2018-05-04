<?php
/**
 * @file
 * stanford_conference.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function stanford_conference_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function stanford_conference_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function stanford_conference_node_info() {
  $items = array(
    'stanford_conference_overview' => array(
      'name' => t('Conference Overview'),
      'base' => 'node_content',
      'description' => t('<em>Conference Overview</em> is used to create a page detailing an small conference. It can be used in conjunction with <em>Conference Session</em>.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'stanford_conference_session' => array(
      'name' => t('Conference Session'),
      'base' => 'node_content',
      'description' => t('<em>Conference Session</em> is used to create a page detailing session details. It can be used in conjunction with <em>Conference Overview</em>.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
