<?php
/**
 * @file
 * stanford_conference.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function stanford_conference_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'conference_contact_info';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Conference: Contact Info';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Contact';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Phone */
  $handler->display->display_options['fields']['field_s_conference_phone']['id'] = 'field_s_conference_phone';
  $handler->display->display_options['fields']['field_s_conference_phone']['table'] = 'field_data_field_s_conference_phone';
  $handler->display->display_options['fields']['field_s_conference_phone']['field'] = 'field_s_conference_phone';
  $handler->display->display_options['fields']['field_s_conference_phone']['label'] = '';
  $handler->display->display_options['fields']['field_s_conference_phone']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_conference_phone']['alter']['text'] = '<strong>Phone:</strong> [field_s_conference_phone]';
  $handler->display->display_options['fields']['field_s_conference_phone']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_conference_phone']['hide_empty'] = TRUE;
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_s_conference_email']['id'] = 'field_s_conference_email';
  $handler->display->display_options['fields']['field_s_conference_email']['table'] = 'field_data_field_s_conference_email';
  $handler->display->display_options['fields']['field_s_conference_email']['field'] = 'field_s_conference_email';
  $handler->display->display_options['fields']['field_s_conference_email']['label'] = '';
  $handler->display->display_options['fields']['field_s_conference_email']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_conference_email']['alter']['text'] = '<strong>Email:</strong> <a href="mailto:[field_s_conference_email]">[field_s_conference_email]</a>';
  $handler->display->display_options['fields']['field_s_conference_email']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_conference_email']['hide_empty'] = TRUE;
  /* Field: Content: Contact URL */
  $handler->display->display_options['fields']['field_s_conference_contact_url']['id'] = 'field_s_conference_contact_url';
  $handler->display->display_options['fields']['field_s_conference_contact_url']['table'] = 'field_data_field_s_conference_contact_url';
  $handler->display->display_options['fields']['field_s_conference_contact_url']['field'] = 'field_s_conference_contact_url';
  $handler->display->display_options['fields']['field_s_conference_contact_url']['label'] = '';
  $handler->display->display_options['fields']['field_s_conference_contact_url']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_s_conference_contact_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_conference_contact_url']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_s_conference_contact_url']['element_wrapper_class'] = 'more-link';
  $handler->display->display_options['fields']['field_s_conference_contact_url']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_conference_contact_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_s_conference_contact_url']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_s_conference_contact_url']['separator'] = '<br />';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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
    'stanford_conference_overview' => 'stanford_conference_overview',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['conference_contact_info'] = $view;

  $view = new view();
  $view->name = 'conference_image';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Conference: Image';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Conference Image */
  $handler->display->display_options['fields']['field_s_conference_image']['id'] = 'field_s_conference_image';
  $handler->display->display_options['fields']['field_s_conference_image']['table'] = 'field_data_field_s_conference_image';
  $handler->display->display_options['fields']['field_s_conference_image']['field'] = 'field_s_conference_image';
  $handler->display->display_options['fields']['field_s_conference_image']['label'] = '';
  $handler->display->display_options['fields']['field_s_conference_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_conference_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_s_conference_image']['settings'] = array(
    'image_style' => 'large-scaled',
    'image_link' => '',
  );
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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
    'stanford_conference_overview' => 'stanford_conference_overview',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['conference_image'] = $view;

  $view = new view();
  $view->name = 'conference_link_to_overview';
  $view->description = 'Link to the agenda for any given conference, depends on the existence of an entity reference from session';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Conference: Link to Overview';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Conference Image */
  $handler->display->display_options['fields']['field_s_conference_image']['id'] = 'field_s_conference_image';
  $handler->display->display_options['fields']['field_s_conference_image']['table'] = 'field_data_field_s_conference_image';
  $handler->display->display_options['fields']['field_s_conference_image']['field'] = 'field_s_conference_image';
  $handler->display->display_options['fields']['field_s_conference_image']['label'] = '';
  $handler->display->display_options['fields']['field_s_conference_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_conference_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_s_conference_image']['settings'] = array(
    'image_style' => 'large-scaled',
    'image_link' => 'content',
  );
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_type'] = 'div';
  $handler->display->display_options['fields']['view_node']['element_class'] = 'more-link';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'View conference overview';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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
    'stanford_conference_overview' => 'stanford_conference_overview',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['conference_link_to_overview'] = $view;

  $view = new view();
  $view->name = 'conference_session_agenda';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Conference: Agenda';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Agenda: [field_s_session_conference]';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_s_session_date_time',
      'rendered' => 1,
      'rendered_strip' => 1,
    ),
  );
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_s_session_conference_target_id']['id'] = 'field_s_session_conference_target_id';
  $handler->display->display_options['relationships']['field_s_session_conference_target_id']['table'] = 'field_data_field_s_session_conference';
  $handler->display->display_options['relationships']['field_s_session_conference_target_id']['field'] = 'field_s_session_conference_target_id';
  /* Field: Content: Conference */
  $handler->display->display_options['fields']['field_s_session_conference']['id'] = 'field_s_session_conference';
  $handler->display->display_options['fields']['field_s_session_conference']['table'] = 'field_data_field_s_session_conference';
  $handler->display->display_options['fields']['field_s_session_conference']['field'] = 'field_s_session_conference';
  $handler->display->display_options['fields']['field_s_session_conference']['label'] = '';
  $handler->display->display_options['fields']['field_s_session_conference']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_session_conference']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_session_conference']['settings'] = array(
    'link' => 0,
  );
  /* Field: Session Date */
  $handler->display->display_options['fields']['field_s_session_date_time']['id'] = 'field_s_session_date_time';
  $handler->display->display_options['fields']['field_s_session_date_time']['table'] = 'field_data_field_s_session_date_time';
  $handler->display->display_options['fields']['field_s_session_date_time']['field'] = 'field_s_session_date_time';
  $handler->display->display_options['fields']['field_s_session_date_time']['ui_name'] = 'Session Date';
  $handler->display->display_options['fields']['field_s_session_date_time']['label'] = '';
  $handler->display->display_options['fields']['field_s_session_date_time']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_session_date_time']['alter']['text'] = '<h2>[field_s_session_date_time]</h2>';
  $handler->display->display_options['fields']['field_s_session_date_time']['element_type'] = 'h2';
  $handler->display->display_options['fields']['field_s_session_date_time']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_session_date_time']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_session_date_time']['settings'] = array(
    'format_type' => 'stanford_month_date_year',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Session Start and End Time */
  $handler->display->display_options['fields']['field_s_session_date_time_1']['id'] = 'field_s_session_date_time_1';
  $handler->display->display_options['fields']['field_s_session_date_time_1']['table'] = 'field_data_field_s_session_date_time';
  $handler->display->display_options['fields']['field_s_session_date_time_1']['field'] = 'field_s_session_date_time';
  $handler->display->display_options['fields']['field_s_session_date_time_1']['ui_name'] = 'Session Start and End Time';
  $handler->display->display_options['fields']['field_s_session_date_time_1']['label'] = '';
  $handler->display->display_options['fields']['field_s_session_date_time_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_session_date_time_1']['alter']['text'] = '<h3>[field_s_session_date_time_1] - [title]</h3>';
  $handler->display->display_options['fields']['field_s_session_date_time_1']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_s_session_date_time_1']['alter']['preserve_tags'] = '<h3>';
  $handler->display->display_options['fields']['field_s_session_date_time_1']['element_type'] = '0';
  $handler->display->display_options['fields']['field_s_session_date_time_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_session_date_time_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_session_date_time_1']['settings'] = array(
    'format_type' => 'stanford_time',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Speaker */
  $handler->display->display_options['fields']['field_s_session_speaker']['id'] = 'field_s_session_speaker';
  $handler->display->display_options['fields']['field_s_session_speaker']['table'] = 'field_data_field_s_session_speaker';
  $handler->display->display_options['fields']['field_s_session_speaker']['field'] = 'field_s_session_speaker';
  $handler->display->display_options['fields']['field_s_session_speaker']['label'] = '';
  $handler->display->display_options['fields']['field_s_session_speaker']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_session_speaker']['settings'] = array(
    'edit' => '',
    'delete' => '',
    'add' => '',
    'description' => 0,
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_s_session_speaker']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_s_session_speaker']['separator'] = ' ';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_type'] = 'div';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['edit_node']['element_wrapper_class'] = 'edit-link';
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit Session';
  /* Sort criterion: Content: Date and Time -  start date (field_s_session_date_time) */
  $handler->display->display_options['sorts']['field_s_session_date_time_value']['id'] = 'field_s_session_date_time_value';
  $handler->display->display_options['sorts']['field_s_session_date_time_value']['table'] = 'field_data_field_s_session_date_time';
  $handler->display->display_options['sorts']['field_s_session_date_time_value']['field'] = 'field_s_session_date_time_value';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_s_session_conference_target_id';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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
    'stanford_conference_session' => 'stanford_conference_session',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'node/%/agenda';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Agenda';
  $export['conference_session_agenda'] = $view;

  $view = new view();
  $view->name = 'conference_sponsors';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Conference: Sponsors';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Sponsors';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Field: Content: Sponsors */
  $handler->display->display_options['fields']['field_s_conference_sponsors']['id'] = 'field_s_conference_sponsors';
  $handler->display->display_options['fields']['field_s_conference_sponsors']['table'] = 'field_data_field_s_conference_sponsors';
  $handler->display->display_options['fields']['field_s_conference_sponsors']['field'] = 'field_s_conference_sponsors';
  $handler->display->display_options['fields']['field_s_conference_sponsors']['label'] = '';
  $handler->display->display_options['fields']['field_s_conference_sponsors']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_conference_sponsors']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_s_conference_sponsors']['settings'] = array(
    'edit' => '',
    'delete' => '',
    'add' => '',
    'description' => 0,
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_s_conference_sponsors']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_s_conference_sponsors']['delta_offset'] = '0';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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
    'stanford_conference_overview' => 'stanford_conference_overview',
  );
  /* Filter criterion: Content: Sponsors (field_s_conference_sponsors) */
  $handler->display->display_options['filters']['field_s_conference_sponsors_value']['id'] = 'field_s_conference_sponsors_value';
  $handler->display->display_options['filters']['field_s_conference_sponsors_value']['table'] = 'field_data_field_s_conference_sponsors';
  $handler->display->display_options['filters']['field_s_conference_sponsors_value']['field'] = 'field_s_conference_sponsors_value';
  $handler->display->display_options['filters']['field_s_conference_sponsors_value']['operator'] = 'not empty';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['conference_sponsors'] = $view;

  $view = new view();
  $view->name = 'conferences';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Conferences';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Conferences';
  $handler->display->display_options['css_class'] = 'views-row-lines';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Conference Image */
  $handler->display->display_options['fields']['field_s_conference_image']['id'] = 'field_s_conference_image';
  $handler->display->display_options['fields']['field_s_conference_image']['table'] = 'field_data_field_s_conference_image';
  $handler->display->display_options['fields']['field_s_conference_image']['field'] = 'field_s_conference_image';
  $handler->display->display_options['fields']['field_s_conference_image']['label'] = '';
  $handler->display->display_options['fields']['field_s_conference_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_conference_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_conference_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_s_conference_image']['settings'] = array(
    'image_style' => 'med-square',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Date and Time */
  $handler->display->display_options['fields']['field_s_conference_date']['id'] = 'field_s_conference_date';
  $handler->display->display_options['fields']['field_s_conference_date']['table'] = 'field_data_field_s_conference_date';
  $handler->display->display_options['fields']['field_s_conference_date']['field'] = 'field_s_conference_date';
  $handler->display->display_options['fields']['field_s_conference_date']['label'] = '';
  $handler->display->display_options['fields']['field_s_conference_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_conference_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_conference_date']['settings'] = array(
    'format_type' => 'stanford_month_date_year',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Lead Text */
  $handler->display->display_options['fields']['field_s_conference_lead_text']['id'] = 'field_s_conference_lead_text';
  $handler->display->display_options['fields']['field_s_conference_lead_text']['table'] = 'field_data_field_s_conference_lead_text';
  $handler->display->display_options['fields']['field_s_conference_lead_text']['field'] = 'field_s_conference_lead_text';
  $handler->display->display_options['fields']['field_s_conference_lead_text']['label'] = '';
  $handler->display->display_options['fields']['field_s_conference_lead_text']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_conference_lead_text']['element_label_colon'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_type'] = 'div';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['edit_node']['element_wrapper_class'] = 'edit-link';
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="postcard-left">
      <div class="postcard-image">
           <div>[field_s_conference_image]</div>
      </div>

      <div class="postcard-content">
           <div><h3>[title]</h3></div>
           <div class="descriptor">[field_s_conference_date]</div>
           <div>[field_s_conference_lead_text]</div>
      </div>

      </div>
<div class="edit-link">[edit_node]</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Date and Time -  start date (field_s_conference_date) */
  $handler->display->display_options['sorts']['field_s_conference_date_value']['id'] = 'field_s_conference_date_value';
  $handler->display->display_options['sorts']['field_s_conference_date_value']['table'] = 'field_data_field_s_conference_date';
  $handler->display->display_options['sorts']['field_s_conference_date_value']['field'] = 'field_s_conference_date_value';
  $handler->display->display_options['sorts']['field_s_conference_date_value']['order'] = 'DESC';
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
    'stanford_conference_overview' => 'stanford_conference_overview',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'conferences';
  $export['conferences'] = $view;

  $view = new view();
  $view->name = 's_conference_link_to_agenda';
  $view->description = 'Link to the agenda for any given conference, depends on the existence of an entity reference from session';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Conference: Link to Agenda';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_s_session_conference_target_id']['id'] = 'field_s_session_conference_target_id';
  $handler->display->display_options['relationships']['field_s_session_conference_target_id']['table'] = 'field_data_field_s_session_conference';
  $handler->display->display_options['relationships']['field_s_session_conference_target_id']['field'] = 'field_s_session_conference_target_id';
  $handler->display->display_options['relationships']['field_s_session_conference_target_id']['required'] = TRUE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['relationship'] = 'field_s_session_conference_target_id';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['path']['alter']['text'] = '<a class="btn" href="[path]/agenda" title="View conference agenda">View conference agenda</a>';
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_s_session_conference_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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
    'stanford_conference_session' => 'stanford_conference_session',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['s_conference_link_to_agenda'] = $view;

  return $export;
}
