<?php
/**
 * @file
 * stanford_opportunity.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function stanford_opportunity_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_contact|node|stanford_opportunity|form';
  $field_group->group_name = 'group_s_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_opportunity';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact',
    'weight' => '17',
    'children' => array(
      0 => 'field_s_opp_contact_email',
      1 => 'field_s_opp_contact_name',
      2 => 'field_s_opp_contact_phone',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-s-contact field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_s_contact|node|stanford_opportunity|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_opp_dates|node|stanford_opportunity|form';
  $field_group->group_name = 'group_s_opp_dates';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_opportunity';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Dates',
    'weight' => '2',
    'children' => array(
      0 => 'field_s_opp_acceptance_deadline',
      1 => 'field_s_opp_application_deadline',
      2 => 'field_s_opp_approx_offer_date',
      3 => 'field_s_opp_duration',
      4 => 'field_s_opp_pre_travel_deadline',
      5 => 'field_s_opp_submissions_open',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-s-opp-dates field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_s_opp_dates|node|stanford_opportunity|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Contact');
  t('Dates');

  return $field_groups;
}
