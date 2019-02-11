<?php
/**
 * @file
 * stanford_opportunity_layouts.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function stanford_opportunity_layouts_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'opportunities_landing_page';
  $context->description = 'Landing page for Opportunities section';
  $context->tag = 'opportunities';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'opportunities' => 'opportunities',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-109c120de83708ff16757153d2e0029c' => array(
          'module' => 'views',
          'delta' => '109c120de83708ff16757153d2e0029c',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Landing page for Opportunities section');
  t('opportunities');
  $export['opportunities_landing_page'] = $context;

  return $export;
}
