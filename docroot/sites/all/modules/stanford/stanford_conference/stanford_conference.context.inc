<?php
/**
 * @file
 * stanford_conference.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function stanford_conference_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'conference_agenda';
  $context->description = 'Blocks placed on the Conference Agenda view page';
  $context->tag = 'Conference';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'conference_session_agenda:page' => 'conference_session_agenda:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-f13fefdd74f6f51f9da968007c77564d' => array(
          'module' => 'views',
          'delta' => 'f13fefdd74f6f51f9da968007c77564d',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks placed on the Conference Agenda view page');
  t('Conference');
  $export['conference_agenda'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'conference_overview';
  $context->description = 'Blocks placed on the conference overview page.';
  $context->tag = 'Conference';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'stanford_conference_overview' => 'stanford_conference_overview',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-7a765c0764e66b425c52b219354153c2' => array(
          'module' => 'views',
          'delta' => '7a765c0764e66b425c52b219354153c2',
          'region' => 'content_lower',
          'weight' => '-10',
        ),
        'views-conference_image-block' => array(
          'module' => 'views',
          'delta' => 'conference_image-block',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-conference_contact_info-block' => array(
          'module' => 'views',
          'delta' => 'conference_contact_info-block',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'views-conference_sponsors-block' => array(
          'module' => 'views',
          'delta' => 'conference_sponsors-block',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks placed on the conference overview page.');
  t('Conference');
  $export['conference_overview'] = $context;

  return $export;
}
