<?php
/**
 * @file
 * stanford_opportunity.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function stanford_opportunity_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function stanford_opportunity_node_info() {
  $items = array(
    'stanford_opportunity' => array(
      'name' => t('Opportunity'),
      'base' => 'node_content',
      'description' => t('Supports content for opportunities from Stanford\'s Off-Campus Learning Opportunities: https://solo.stanford.edu/.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
