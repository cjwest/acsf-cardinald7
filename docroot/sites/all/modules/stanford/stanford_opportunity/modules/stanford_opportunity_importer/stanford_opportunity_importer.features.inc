<?php
/**
 * @file
 * stanford_opportunity_importer.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function stanford_opportunity_importer_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "feeds_tamper" && $api == "feeds_tamper_default") {
    return array("version" => "2");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function stanford_opportunity_importer_node_info() {
  $items = array(
    'stanford_opportunity_importer' => array(
      'name' => t('Opportunity Importer'),
      'base' => 'node_content',
      'description' => t('Importer for Stanford\'s Off-Campus Learning Opportunities: https://solo.stanford.edu/. '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
