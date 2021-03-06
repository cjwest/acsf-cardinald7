<?php
/**
 * @file
 * stanford_paragraph_types_textarea_simple.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function stanford_paragraph_types_textarea_simple_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_paragraphs_info().
 */
function stanford_paragraph_types_textarea_simple_paragraphs_info() {
  $items = array(
    'p_wysiwyg_simple' => array(
      'name' => 'Textarea Simple',
      'bundle' => 'p_wysiwyg_simple',
      'locked' => '1',
    ),
  );
  return $items;
}
