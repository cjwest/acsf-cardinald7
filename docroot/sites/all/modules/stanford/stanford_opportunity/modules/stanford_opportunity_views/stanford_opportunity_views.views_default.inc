<?php
/**
 * @file
 * stanford_opportunity_views.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function stanford_opportunity_views_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'stanford_opportunity_grid';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Opportunity Grid';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Opportunities';
  $handler->display->display_options['display_comment'] = 'CJW';
  $handler->display->display_options['css_class'] = 'views-grid-three';
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['use_more_text'] = 'See more opportunities';
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Go';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'Opportunities - No Results';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No opportunities items listed.';
  $handler->display->display_options['empty']['area']['format'] = 'content_editor_text_format';
  /* Relationship: Feeds item: Owner feed */
  $handler->display->display_options['relationships']['feed_nid']['id'] = 'feed_nid';
  $handler->display->display_options['relationships']['feed_nid']['table'] = 'feeds_item';
  $handler->display->display_options['relationships']['feed_nid']['field'] = 'feed_nid';
  /* Field: Content: ID */
  $handler->display->display_options['fields']['field_s_opp_id']['id'] = 'field_s_opp_id';
  $handler->display->display_options['fields']['field_s_opp_id']['table'] = 'field_data_field_s_opp_id';
  $handler->display->display_options['fields']['field_s_opp_id']['field'] = 'field_s_opp_id';
  $handler->display->display_options['fields']['field_s_opp_id']['label'] = '';
  $handler->display->display_options['fields']['field_s_opp_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_opp_id']['element_label_colon'] = FALSE;
  /* Field: Content: Site URL */
  $handler->display->display_options['fields']['field_s_opp_importer_site_url']['id'] = 'field_s_opp_importer_site_url';
  $handler->display->display_options['fields']['field_s_opp_importer_site_url']['table'] = 'field_data_field_s_opp_importer_site_url';
  $handler->display->display_options['fields']['field_s_opp_importer_site_url']['field'] = 'field_s_opp_importer_site_url';
  $handler->display->display_options['fields']['field_s_opp_importer_site_url']['relationship'] = 'feed_nid';
  $handler->display->display_options['fields']['field_s_opp_importer_site_url']['label'] = '';
  $handler->display->display_options['fields']['field_s_opp_importer_site_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_opp_importer_site_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_opp_importer_site_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_s_opp_importer_site_url']['type'] = 'link_plain';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_s_opp_image']['id'] = 'field_s_opp_image';
  $handler->display->display_options['fields']['field_s_opp_image']['table'] = 'field_data_field_s_opp_image';
  $handler->display->display_options['fields']['field_s_opp_image']['field'] = 'field_s_opp_image';
  $handler->display->display_options['fields']['field_s_opp_image']['label'] = '';
  $handler->display->display_options['fields']['field_s_opp_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_opp_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_opp_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_s_opp_image']['settings'] = array(
    'image_style' => '4-col-header',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'normal-link';
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Global: Image and title link */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Global: Image and title link';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="[field_s_opp_importer_site_url]/node/[field_s_opp_id]">[field_s_opp_image]</a>
<h3 class="opp_title"><a href="[field_s_opp_importer_site_url]/node/[field_s_opp_id]">[title]</a></h3>
';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Duration */
  $handler->display->display_options['fields']['field_s_opp_duration']['id'] = 'field_s_opp_duration';
  $handler->display->display_options['fields']['field_s_opp_duration']['table'] = 'field_data_field_s_opp_duration';
  $handler->display->display_options['fields']['field_s_opp_duration']['field'] = 'field_s_opp_duration';
  $handler->display->display_options['fields']['field_s_opp_duration']['ui_name'] = 'Content: Duration';
  $handler->display->display_options['fields']['field_s_opp_duration']['label'] = '';
  $handler->display->display_options['fields']['field_s_opp_duration']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_s_opp_duration']['element_label_type'] = 'div';
  $handler->display->display_options['fields']['field_s_opp_duration']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_opp_duration']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_s_opp_duration']['element_wrapper_class'] = 'descriptor';
  $handler->display->display_options['fields']['field_s_opp_duration']['settings'] = array(
    'format_type' => 'stanford_month_date_year',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_s_opp_location']['id'] = 'field_s_opp_location';
  $handler->display->display_options['fields']['field_s_opp_location']['table'] = 'field_data_field_s_opp_location';
  $handler->display->display_options['fields']['field_s_opp_location']['field'] = 'field_s_opp_location';
  $handler->display->display_options['fields']['field_s_opp_location']['label'] = '';
  $handler->display->display_options['fields']['field_s_opp_location']['alter']['text'] = '[field_s_opp_location] | ';
  $handler->display->display_options['fields']['field_s_opp_location']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_s_opp_location']['element_label_type'] = 'div';
  $handler->display->display_options['fields']['field_s_opp_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_opp_location']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_s_opp_location']['element_wrapper_class'] = 'descriptor';
  $handler->display->display_options['fields']['field_s_opp_location']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_opp_location']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_s_opp_location']['delta_offset'] = '0';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['edit_node']['element_wrapper_class'] = 'edit-link';
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Sort criterion: Content: Date (field_s_news_date) */
  $handler->display->display_options['sorts']['field_s_news_date_value']['id'] = 'field_s_news_date_value';
  $handler->display->display_options['sorts']['field_s_news_date_value']['table'] = 'field_data_field_s_news_date';
  $handler->display->display_options['sorts']['field_s_news_date_value']['field'] = 'field_s_news_date_value';
  $handler->display->display_options['sorts']['field_s_news_date_value']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['required'] = TRUE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'stanford_opportunity' => 'stanford_opportunity',
  );
  /* Filter criterion: Content: Location (field_s_opp_location) */
  $handler->display->display_options['filters']['field_s_opp_location_tid']['id'] = 'field_s_opp_location_tid';
  $handler->display->display_options['filters']['field_s_opp_location_tid']['table'] = 'field_data_field_s_opp_location';
  $handler->display->display_options['filters']['field_s_opp_location_tid']['field'] = 'field_s_opp_location_tid';
  $handler->display->display_options['filters']['field_s_opp_location_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_s_opp_location_tid']['expose']['operator_id'] = 'field_s_opp_location_tid_op';
  $handler->display->display_options['filters']['field_s_opp_location_tid']['expose']['label'] = 'Location ';
  $handler->display->display_options['filters']['field_s_opp_location_tid']['expose']['operator'] = 'field_s_opp_location_tid_op';
  $handler->display->display_options['filters']['field_s_opp_location_tid']['expose']['identifier'] = 'field_s_opp_location_tid';
  $handler->display->display_options['filters']['field_s_opp_location_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_s_opp_location_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_s_opp_location_tid']['vocabulary'] = 'stanford_opp_location';
  /* Filter criterion: Content: Major (field_s_opp_major) */
  $handler->display->display_options['filters']['field_s_opp_major_tid']['id'] = 'field_s_opp_major_tid';
  $handler->display->display_options['filters']['field_s_opp_major_tid']['table'] = 'field_data_field_s_opp_major';
  $handler->display->display_options['filters']['field_s_opp_major_tid']['field'] = 'field_s_opp_major_tid';
  $handler->display->display_options['filters']['field_s_opp_major_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_s_opp_major_tid']['expose']['operator_id'] = 'field_s_opp_major_tid_op';
  $handler->display->display_options['filters']['field_s_opp_major_tid']['expose']['label'] = 'Major';
  $handler->display->display_options['filters']['field_s_opp_major_tid']['expose']['operator'] = 'field_s_opp_major_tid_op';
  $handler->display->display_options['filters']['field_s_opp_major_tid']['expose']['identifier'] = 'field_s_opp_major_tid';
  $handler->display->display_options['filters']['field_s_opp_major_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_s_opp_major_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_s_opp_major_tid']['vocabulary'] = 'stanford_opp_major';
  /* Filter criterion: Content: Open To (field_s_opp_open_to) */
  $handler->display->display_options['filters']['field_s_opp_open_to_tid']['id'] = 'field_s_opp_open_to_tid';
  $handler->display->display_options['filters']['field_s_opp_open_to_tid']['table'] = 'field_data_field_s_opp_open_to';
  $handler->display->display_options['filters']['field_s_opp_open_to_tid']['field'] = 'field_s_opp_open_to_tid';
  $handler->display->display_options['filters']['field_s_opp_open_to_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_s_opp_open_to_tid']['expose']['operator_id'] = 'field_s_opp_open_to_tid_op';
  $handler->display->display_options['filters']['field_s_opp_open_to_tid']['expose']['label'] = 'Open To';
  $handler->display->display_options['filters']['field_s_opp_open_to_tid']['expose']['operator'] = 'field_s_opp_open_to_tid_op';
  $handler->display->display_options['filters']['field_s_opp_open_to_tid']['expose']['identifier'] = 'field_s_opp_open_to_tid';
  $handler->display->display_options['filters']['field_s_opp_open_to_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_s_opp_open_to_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_s_opp_open_to_tid']['vocabulary'] = 'stanford_opp_open_to';
  /* Filter criterion: Content: Opportunity Type (field_s_opp_type) */
  $handler->display->display_options['filters']['field_s_opp_type_tid']['id'] = 'field_s_opp_type_tid';
  $handler->display->display_options['filters']['field_s_opp_type_tid']['table'] = 'field_data_field_s_opp_type';
  $handler->display->display_options['filters']['field_s_opp_type_tid']['field'] = 'field_s_opp_type_tid';
  $handler->display->display_options['filters']['field_s_opp_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_s_opp_type_tid']['expose']['operator_id'] = 'field_s_opp_type_tid_op';
  $handler->display->display_options['filters']['field_s_opp_type_tid']['expose']['label'] = 'Opportunity Type';
  $handler->display->display_options['filters']['field_s_opp_type_tid']['expose']['operator'] = 'field_s_opp_type_tid_op';
  $handler->display->display_options['filters']['field_s_opp_type_tid']['expose']['identifier'] = 'field_s_opp_type_tid';
  $handler->display->display_options['filters']['field_s_opp_type_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_s_opp_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_s_opp_type_tid']['vocabulary'] = 'stanford_opp_type';
  /* Filter criterion: Content: Time of Year (field_s_opp_time_of_year) */
  $handler->display->display_options['filters']['field_s_opp_time_of_year_tid']['id'] = 'field_s_opp_time_of_year_tid';
  $handler->display->display_options['filters']['field_s_opp_time_of_year_tid']['table'] = 'field_data_field_s_opp_time_of_year';
  $handler->display->display_options['filters']['field_s_opp_time_of_year_tid']['field'] = 'field_s_opp_time_of_year_tid';
  $handler->display->display_options['filters']['field_s_opp_time_of_year_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_s_opp_time_of_year_tid']['expose']['operator_id'] = 'field_s_opp_time_of_year_tid_op';
  $handler->display->display_options['filters']['field_s_opp_time_of_year_tid']['expose']['label'] = 'Time of Year ';
  $handler->display->display_options['filters']['field_s_opp_time_of_year_tid']['expose']['operator'] = 'field_s_opp_time_of_year_tid_op';
  $handler->display->display_options['filters']['field_s_opp_time_of_year_tid']['expose']['identifier'] = 'field_s_opp_time_of_year_tid';
  $handler->display->display_options['filters']['field_s_opp_time_of_year_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_s_opp_time_of_year_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_s_opp_time_of_year_tid']['vocabulary'] = 'stanford_opp_time_of_year';

  /* Display: 2 Item Grid Block with Details */
  $handler = $view->new_display('block', '2 Item Grid Block with Details', 'grid_block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Recent News';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'views-grid-two';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'grid_3_page';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'stanford_opportunity' => 'stanford_opportunity',
  );

  /* Display: Page grid three */
  $handler = $view->new_display('page', 'Page grid three', 'grid_3_page');
  $handler->display->display_options['display_comment'] = 'CJW';
  $handler->display->display_options['path'] = 'opportunities/grid-three';

  /* Display: Page grid two */
  $handler = $view->new_display('page', 'Page grid two', 'page_grid_two');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'views-grid-two';
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'opportunities';

  /* Display: Page grid three filtered */
  $handler = $view->new_display('page', 'Page grid three filtered', 'page_grid_3_filtered');
  $handler->display->display_options['display_comment'] = 'CJW';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Opportunity Type (field_s_opp_type) */
  $handler->display->display_options['arguments']['field_s_opp_type_tid']['id'] = 'field_s_opp_type_tid';
  $handler->display->display_options['arguments']['field_s_opp_type_tid']['table'] = 'field_data_field_s_opp_type';
  $handler->display->display_options['arguments']['field_s_opp_type_tid']['field'] = 'field_s_opp_type_tid';
  $handler->display->display_options['arguments']['field_s_opp_type_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_s_opp_type_tid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_s_opp_type_tid']['title'] = '%1';
  $handler->display->display_options['arguments']['field_s_opp_type_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_s_opp_type_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_s_opp_type_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_s_opp_type_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_s_opp_type_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_s_opp_type_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_s_opp_type_tid']['validate_options']['vocabularies'] = array(
    'stanford_opp_type' => 'stanford_opp_type',
  );
  $handler->display->display_options['arguments']['field_s_opp_type_tid']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['field_s_opp_type_tid']['validate_options']['transform'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['required'] = TRUE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'stanford_opportunity' => 'stanford_opportunity',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Location (field_s_opp_location) */
  $handler->display->display_options['filters']['field_s_opp_location_tid']['id'] = 'field_s_opp_location_tid';
  $handler->display->display_options['filters']['field_s_opp_location_tid']['table'] = 'field_data_field_s_opp_location';
  $handler->display->display_options['filters']['field_s_opp_location_tid']['field'] = 'field_s_opp_location_tid';
  $handler->display->display_options['filters']['field_s_opp_location_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_s_opp_location_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_s_opp_location_tid']['expose']['operator_id'] = 'field_s_opp_location_tid_op';
  $handler->display->display_options['filters']['field_s_opp_location_tid']['expose']['label'] = 'Location ';
  $handler->display->display_options['filters']['field_s_opp_location_tid']['expose']['operator'] = 'field_s_opp_location_tid_op';
  $handler->display->display_options['filters']['field_s_opp_location_tid']['expose']['identifier'] = 'field_s_opp_location_tid';
  $handler->display->display_options['filters']['field_s_opp_location_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_s_opp_location_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_s_opp_location_tid']['vocabulary'] = 'stanford_opp_location';
  /* Filter criterion: Content: Major (field_s_opp_major) */
  $handler->display->display_options['filters']['field_s_opp_major_tid']['id'] = 'field_s_opp_major_tid';
  $handler->display->display_options['filters']['field_s_opp_major_tid']['table'] = 'field_data_field_s_opp_major';
  $handler->display->display_options['filters']['field_s_opp_major_tid']['field'] = 'field_s_opp_major_tid';
  $handler->display->display_options['filters']['field_s_opp_major_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_s_opp_major_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_s_opp_major_tid']['expose']['operator_id'] = 'field_s_opp_major_tid_op';
  $handler->display->display_options['filters']['field_s_opp_major_tid']['expose']['label'] = 'Major';
  $handler->display->display_options['filters']['field_s_opp_major_tid']['expose']['operator'] = 'field_s_opp_major_tid_op';
  $handler->display->display_options['filters']['field_s_opp_major_tid']['expose']['identifier'] = 'field_s_opp_major_tid';
  $handler->display->display_options['filters']['field_s_opp_major_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_s_opp_major_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_s_opp_major_tid']['vocabulary'] = 'stanford_opp_major';
  /* Filter criterion: Content: Open To (field_s_opp_open_to) */
  $handler->display->display_options['filters']['field_s_opp_open_to_tid']['id'] = 'field_s_opp_open_to_tid';
  $handler->display->display_options['filters']['field_s_opp_open_to_tid']['table'] = 'field_data_field_s_opp_open_to';
  $handler->display->display_options['filters']['field_s_opp_open_to_tid']['field'] = 'field_s_opp_open_to_tid';
  $handler->display->display_options['filters']['field_s_opp_open_to_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_s_opp_open_to_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_s_opp_open_to_tid']['expose']['operator_id'] = 'field_s_opp_open_to_tid_op';
  $handler->display->display_options['filters']['field_s_opp_open_to_tid']['expose']['label'] = 'Open To';
  $handler->display->display_options['filters']['field_s_opp_open_to_tid']['expose']['operator'] = 'field_s_opp_open_to_tid_op';
  $handler->display->display_options['filters']['field_s_opp_open_to_tid']['expose']['identifier'] = 'field_s_opp_open_to_tid';
  $handler->display->display_options['filters']['field_s_opp_open_to_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_s_opp_open_to_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_s_opp_open_to_tid']['vocabulary'] = 'stanford_opp_open_to';
  /* Filter criterion: Content: Time of Year (field_s_opp_time_of_year) */
  $handler->display->display_options['filters']['field_s_opp_time_of_year_tid']['id'] = 'field_s_opp_time_of_year_tid';
  $handler->display->display_options['filters']['field_s_opp_time_of_year_tid']['table'] = 'field_data_field_s_opp_time_of_year';
  $handler->display->display_options['filters']['field_s_opp_time_of_year_tid']['field'] = 'field_s_opp_time_of_year_tid';
  $handler->display->display_options['filters']['field_s_opp_time_of_year_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_s_opp_time_of_year_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_s_opp_time_of_year_tid']['expose']['operator_id'] = 'field_s_opp_time_of_year_tid_op';
  $handler->display->display_options['filters']['field_s_opp_time_of_year_tid']['expose']['label'] = 'Time of Year ';
  $handler->display->display_options['filters']['field_s_opp_time_of_year_tid']['expose']['operator'] = 'field_s_opp_time_of_year_tid_op';
  $handler->display->display_options['filters']['field_s_opp_time_of_year_tid']['expose']['identifier'] = 'field_s_opp_time_of_year_tid';
  $handler->display->display_options['filters']['field_s_opp_time_of_year_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_s_opp_time_of_year_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_s_opp_time_of_year_tid']['vocabulary'] = 'stanford_opp_time_of_year';
  $handler->display->display_options['path'] = 'opportunities/filtered/grid-three/%';

  /* Display: Page grid two filtered */
  $handler = $view->new_display('page', 'Page grid two filtered', 'page_grid_2_filtered');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'views-grid-two';
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Opportunity Type (field_s_opp_type) */
  $handler->display->display_options['arguments']['field_s_opp_type_tid']['id'] = 'field_s_opp_type_tid';
  $handler->display->display_options['arguments']['field_s_opp_type_tid']['table'] = 'field_data_field_s_opp_type';
  $handler->display->display_options['arguments']['field_s_opp_type_tid']['field'] = 'field_s_opp_type_tid';
  $handler->display->display_options['arguments']['field_s_opp_type_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_s_opp_type_tid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_s_opp_type_tid']['title'] = '%1';
  $handler->display->display_options['arguments']['field_s_opp_type_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_s_opp_type_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_s_opp_type_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_s_opp_type_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_s_opp_type_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_s_opp_type_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_s_opp_type_tid']['validate_options']['vocabularies'] = array(
    'stanford_opp_type' => 'stanford_opp_type',
  );
  $handler->display->display_options['arguments']['field_s_opp_type_tid']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['field_s_opp_type_tid']['validate_options']['transform'] = TRUE;
  $handler->display->display_options['arguments']['field_s_opp_type_tid']['validate']['fail'] = 'empty';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['required'] = TRUE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'stanford_opportunity' => 'stanford_opportunity',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Location (field_s_opp_location) */
  $handler->display->display_options['filters']['field_s_opp_location_tid']['id'] = 'field_s_opp_location_tid';
  $handler->display->display_options['filters']['field_s_opp_location_tid']['table'] = 'field_data_field_s_opp_location';
  $handler->display->display_options['filters']['field_s_opp_location_tid']['field'] = 'field_s_opp_location_tid';
  $handler->display->display_options['filters']['field_s_opp_location_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_s_opp_location_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_s_opp_location_tid']['expose']['operator_id'] = 'field_s_opp_location_tid_op';
  $handler->display->display_options['filters']['field_s_opp_location_tid']['expose']['label'] = 'Location ';
  $handler->display->display_options['filters']['field_s_opp_location_tid']['expose']['operator'] = 'field_s_opp_location_tid_op';
  $handler->display->display_options['filters']['field_s_opp_location_tid']['expose']['identifier'] = 'field_s_opp_location_tid';
  $handler->display->display_options['filters']['field_s_opp_location_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_s_opp_location_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_s_opp_location_tid']['vocabulary'] = 'stanford_opp_location';
  /* Filter criterion: Content: Major (field_s_opp_major) */
  $handler->display->display_options['filters']['field_s_opp_major_tid']['id'] = 'field_s_opp_major_tid';
  $handler->display->display_options['filters']['field_s_opp_major_tid']['table'] = 'field_data_field_s_opp_major';
  $handler->display->display_options['filters']['field_s_opp_major_tid']['field'] = 'field_s_opp_major_tid';
  $handler->display->display_options['filters']['field_s_opp_major_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_s_opp_major_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_s_opp_major_tid']['expose']['operator_id'] = 'field_s_opp_major_tid_op';
  $handler->display->display_options['filters']['field_s_opp_major_tid']['expose']['label'] = 'Major';
  $handler->display->display_options['filters']['field_s_opp_major_tid']['expose']['operator'] = 'field_s_opp_major_tid_op';
  $handler->display->display_options['filters']['field_s_opp_major_tid']['expose']['identifier'] = 'field_s_opp_major_tid';
  $handler->display->display_options['filters']['field_s_opp_major_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_s_opp_major_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_s_opp_major_tid']['vocabulary'] = 'stanford_opp_major';
  /* Filter criterion: Content: Open To (field_s_opp_open_to) */
  $handler->display->display_options['filters']['field_s_opp_open_to_tid']['id'] = 'field_s_opp_open_to_tid';
  $handler->display->display_options['filters']['field_s_opp_open_to_tid']['table'] = 'field_data_field_s_opp_open_to';
  $handler->display->display_options['filters']['field_s_opp_open_to_tid']['field'] = 'field_s_opp_open_to_tid';
  $handler->display->display_options['filters']['field_s_opp_open_to_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_s_opp_open_to_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_s_opp_open_to_tid']['expose']['operator_id'] = 'field_s_opp_open_to_tid_op';
  $handler->display->display_options['filters']['field_s_opp_open_to_tid']['expose']['label'] = 'Open To';
  $handler->display->display_options['filters']['field_s_opp_open_to_tid']['expose']['operator'] = 'field_s_opp_open_to_tid_op';
  $handler->display->display_options['filters']['field_s_opp_open_to_tid']['expose']['identifier'] = 'field_s_opp_open_to_tid';
  $handler->display->display_options['filters']['field_s_opp_open_to_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_s_opp_open_to_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_s_opp_open_to_tid']['vocabulary'] = 'stanford_opp_open_to';
  /* Filter criterion: Content: Time of Year (field_s_opp_time_of_year) */
  $handler->display->display_options['filters']['field_s_opp_time_of_year_tid']['id'] = 'field_s_opp_time_of_year_tid';
  $handler->display->display_options['filters']['field_s_opp_time_of_year_tid']['table'] = 'field_data_field_s_opp_time_of_year';
  $handler->display->display_options['filters']['field_s_opp_time_of_year_tid']['field'] = 'field_s_opp_time_of_year_tid';
  $handler->display->display_options['filters']['field_s_opp_time_of_year_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_s_opp_time_of_year_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_s_opp_time_of_year_tid']['expose']['operator_id'] = 'field_s_opp_time_of_year_tid_op';
  $handler->display->display_options['filters']['field_s_opp_time_of_year_tid']['expose']['label'] = 'Time of Year ';
  $handler->display->display_options['filters']['field_s_opp_time_of_year_tid']['expose']['operator'] = 'field_s_opp_time_of_year_tid_op';
  $handler->display->display_options['filters']['field_s_opp_time_of_year_tid']['expose']['identifier'] = 'field_s_opp_time_of_year_tid';
  $handler->display->display_options['filters']['field_s_opp_time_of_year_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_s_opp_time_of_year_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_s_opp_time_of_year_tid']['vocabulary'] = 'stanford_opp_time_of_year';
  $handler->display->display_options['path'] = 'opportunities/filtered/grid-two/%';
  $export['stanford_opportunity_grid'] = $view;

  return $export;
}
