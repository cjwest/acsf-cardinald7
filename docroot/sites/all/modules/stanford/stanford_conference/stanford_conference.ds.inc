<?php
/**
 * @file
 * stanford_conference.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function stanford_conference_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_s_session_speaker|default';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_s_session_speaker';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_s_speaker_name',
        1 => 'group_s_postcard_image',
        2 => 'group_s_session_descriptor',
        3 => 'field_s_speaker_topic',
        4 => 'field_s_speaker_organization',
        5 => 'group_s_postcard_content',
        6 => 'group_s_postcard',
        7 => 'field_s_speaker_description',
        8 => 'field_s_speaker_file_upload',
        9 => 'field_s_speaker_image',
      ),
    ),
    'fields' => array(
      'field_s_speaker_name' => 'ds_content',
      'group_s_postcard_image' => 'ds_content',
      'group_s_session_descriptor' => 'ds_content',
      'field_s_speaker_topic' => 'ds_content',
      'field_s_speaker_organization' => 'ds_content',
      'group_s_postcard_content' => 'ds_content',
      'group_s_postcard' => 'ds_content',
      'field_s_speaker_description' => 'ds_content',
      'field_s_speaker_file_upload' => 'ds_content',
      'field_s_speaker_image' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['field_collection_item|field_s_session_speaker|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|stanford_conference_overview|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'stanford_conference_overview';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_s_conference_lead_text',
        1 => 'field_conference_image',
        2 => 'field_s_conference_phone',
        3 => 'field_s_conference_email',
        4 => 'field_s_conference_contact_url',
        5 => 'field_s_conference_reg_link',
        6 => 'body',
        7 => 'field_conference_file_insert',
        8 => 'field_s_conference_date',
        9 => 'field_s_conference_location',
        10 => 'field_s_conference_map_link',
      ),
    ),
    'fields' => array(
      'field_s_conference_lead_text' => 'ds_content',
      'field_conference_image' => 'ds_content',
      'field_s_conference_phone' => 'ds_content',
      'field_s_conference_email' => 'ds_content',
      'field_s_conference_contact_url' => 'ds_content',
      'field_s_conference_reg_link' => 'ds_content',
      'body' => 'ds_content',
      'field_conference_file_insert' => 'ds_content',
      'field_s_conference_date' => 'ds_content',
      'field_s_conference_location' => 'ds_content',
      'field_s_conference_map_link' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|stanford_conference_overview|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|stanford_conference_overview|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'stanford_conference_overview';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'group_conf_lead_text_styles',
        1 => 'field_s_conference_reg_link',
        2 => 'field_s_conference_lead_text',
        3 => 'group_conf_overview',
        5 => 'group_conf_descriptor',
        6 => 'field_s_conference_date',
        7 => 'body',
        9 => 'field_s_conference_file_insert',
        10 => 'field_s_conference_location',
        13 => 'field_s_conference_map_link',
      ),
      'contact' => array(
        4 => 'field_s_conference_phone',
        8 => 'field_s_conference_email',
        11 => 'field_s_conference_contact_url',
      ),
      's_conference_image_block' => array(
        12 => 'field_s_conference_image',
      ),
    ),
    'fields' => array(
      'group_conf_lead_text_styles' => 'ds_content',
      'field_s_conference_reg_link' => 'ds_content',
      'field_s_conference_lead_text' => 'ds_content',
      'group_conf_overview' => 'ds_content',
      'field_s_conference_phone' => 'contact',
      'group_conf_descriptor' => 'ds_content',
      'field_s_conference_date' => 'ds_content',
      'body' => 'ds_content',
      'field_s_conference_email' => 'contact',
      'field_s_conference_file_insert' => 'ds_content',
      'field_s_conference_location' => 'ds_content',
      'field_s_conference_contact_url' => 'contact',
      'field_s_conference_image' => 's_conference_image_block',
      'field_s_conference_map_link' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|stanford_conference_overview|full'] = $ds_layout;

  return $export;
}
