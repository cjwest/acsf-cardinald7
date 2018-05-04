<?php
/**
 * @file
 * stanford_conference.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function stanford_conference_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_conf_descriptor|node|stanford_conference_overview|full';
  $field_group->group_name = 'group_conf_descriptor';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_conference_overview';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_conf_overview';
  $field_group->data = array(
    'label' => 'Descriptor Group',
    'weight' => '3',
    'children' => array(
      0 => 'field_s_conference_map_link',
      1 => 'field_s_conference_location',
      2 => 'field_s_conference_date',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Descriptor Group',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'descriptor',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_conf_descriptor|node|stanford_conference_overview|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_conf_lead_text_styles|node|stanford_conference_overview|full';
  $field_group->group_name = 'group_conf_lead_text_styles';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_conference_overview';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Lead text styles',
    'weight' => '0',
    'children' => array(
      0 => 'field_s_conference_lead_text',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Lead text styles',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'summary',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_conf_lead_text_styles|node|stanford_conference_overview|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_conf_overview|node|stanford_conference_overview|full';
  $field_group->group_name = 'group_conf_overview';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_conference_overview';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Overview',
    'weight' => '2',
    'children' => array(
      0 => 'body',
      1 => 'field_s_conference_file_insert',
      2 => 'group_conf_descriptor',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Overview',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_conf_overview|node|stanford_conference_overview|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_conference_contact|node|stanford_conference_overview|form';
  $field_group->group_name = 'group_s_conference_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_conference_overview';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact',
    'weight' => '10',
    'children' => array(
      0 => 'field_s_conference_phone',
      1 => 'field_s_conference_email',
      2 => 'field_s_conference_contact_url',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Contact',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-s-conference-contact field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_s_conference_contact|node|stanford_conference_overview|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard_content|field_collection_item|field_s_session_speaker|default';
  $field_group->group_name = 'group_s_postcard_content';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_session_speaker';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_s_postcard';
  $field_group->data = array(
    'label' => 'Postcard Content',
    'weight' => '9',
    'children' => array(
      0 => 'field_s_speaker_topic',
      1 => 'field_s_speaker_description',
      2 => 'field_s_speaker_file_upload',
      3 => 'field_s_speaker_name',
      4 => 'group_s_session_descriptor',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Postcard Content',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_s_postcard_content|field_collection_item|field_s_session_speaker|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard_image|field_collection_item|field_s_session_speaker|default';
  $field_group->group_name = 'group_s_postcard_image';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_session_speaker';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_s_postcard';
  $field_group->data = array(
    'label' => 'Postcard Image',
    'weight' => '8',
    'children' => array(
      0 => 'field_s_speaker_image',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Postcard Image',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_s_postcard_image|field_collection_item|field_s_session_speaker|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard|field_collection_item|field_s_session_speaker|default';
  $field_group->group_name = 'group_s_postcard';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_session_speaker';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Postcard',
    'weight' => '10',
    'children' => array(
      0 => 'group_s_postcard_image',
      1 => 'group_s_postcard_content',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Postcard',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'postcard-left',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_s_postcard|field_collection_item|field_s_session_speaker|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_session_descriptor|field_collection_item|field_s_session_speaker|default';
  $field_group->group_name = 'group_s_session_descriptor';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_session_speaker';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_s_postcard_content';
  $field_group->data = array(
    'label' => 'Descriptor Group',
    'weight' => '8',
    'children' => array(
      0 => 'field_s_speaker_organization',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Descriptor Group',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'descriptor',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_s_session_descriptor|field_collection_item|field_s_session_speaker|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_speaker_content|field_collection_item|field_s_session_speaker|form';
  $field_group->group_name = 'group_s_speaker_content';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_session_speaker';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Add/Edit Content',
    'weight' => '1',
    'children' => array(
      0 => 'field_s_speaker_image',
      1 => 'field_s_speaker_organization',
      2 => 'field_s_speaker_topic',
      3 => 'field_s_speaker_description',
      4 => 'field_s_speaker_file_upload',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Add/Edit Content',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_s_speaker_content|field_collection_item|field_s_session_speaker|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_sponsor_image_group|field_collection_item|field_s_conference_sponsors|form';
  $field_group->group_name = 'group_s_sponsor_image_group';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_conference_sponsors';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Add/Edit Sponsor Image',
    'weight' => '1',
    'children' => array(
      0 => 'field_s_sponsor_image',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Add/Edit Sponsor Image',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-s-sponsor-image-group field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_s_sponsor_image_group|field_collection_item|field_s_conference_sponsors|form'] = $field_group;

  return $export;
}
