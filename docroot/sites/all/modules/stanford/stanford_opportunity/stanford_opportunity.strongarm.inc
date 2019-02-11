<?php
/**
 * @file
 * stanford_opportunity.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function stanford_opportunity_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_stanford_opportunity_importer';
  $strongarm->value = 'edit-auto-nodetitle';
  $export['additional_settings__active_tab_stanford_opportunity_importer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_enable_revisions_page_node_stanford_opportunity_importer';
  $strongarm->value = 1;
  $export['diff_enable_revisions_page_node_stanford_opportunity_importer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_show_preview_changes_node_stanford_opportunity_importer';
  $strongarm->value = 1;
  $export['diff_show_preview_changes_node_stanford_opportunity_importer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_view_mode_preview_node_stanford_opportunity_importer';
  $strongarm->value = 'full';
  $export['diff_view_mode_preview_node_stanford_opportunity_importer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__stanford_opportunity';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '23',
        ),
        'title' => array(
          'weight' => '1',
        ),
        'path' => array(
          'weight' => '21',
        ),
        'redirect' => array(
          'weight' => '22',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__stanford_opportunity'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_stanford_opportunity';
  $strongarm->value = array();
  $export['menu_options_stanford_opportunity'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_stanford_opportunity';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_stanford_opportunity'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_stanford_opportunity';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_stanford_opportunity'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_stanford_opportunity';
  $strongarm->value = '1';
  $export['node_preview_stanford_opportunity'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_stanford_opportunity';
  $strongarm->value = 0;
  $export['node_submitted_stanford_opportunity'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_stanford_opportunity_pattern';
  $strongarm->value = 'opportunities/[node:title]';
  $export['pathauto_node_stanford_opportunity_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_stanford_opp_city_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_stanford_opp_city_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_stanford_opp_location_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_stanford_opp_location_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_stanford_opp_major_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_stanford_opp_major_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_stanford_opp_open_to_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_stanford_opp_open_to_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_stanford_opp_sponsor_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_stanford_opp_sponsor_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_stanford_opp_time_of_year_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_stanford_opp_time_of_year_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_stanford_opp_type_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_stanford_opp_type_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'save_continue_stanford_opportunity_importer';
  $strongarm->value = 'Save and add fields';
  $export['save_continue_stanford_opportunity_importer'] = $strongarm;

  return $export;
}
