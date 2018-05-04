<?php
/**
 * @file
 * stanford_jsplus_layouts.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function stanford_jsplus_layouts_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'all_pages_but_homepage';
  $context->description = 'All pages but the home page';
  $context->tag = 'Sub-pages';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~<front>' => '~<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'stanford_jumpstart_layouts-2' => array(
          'module' => 'menu_block',
          'delta' => 'stanford_jumpstart_layouts-2',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('All pages but the home page');
  t('Sub-pages');
  $export['all_pages_but_homepage'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'events_calendars';
  $context->description = 'Blocks on month and day event views';
  $context->tag = 'Events';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'events/month/*' => 'events/month/*',
        'events/day/*' => 'events/day/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-934c9b9d8d2d2f2b37f050dcd3bba83c' => array(
          'module' => 'views',
          'delta' => '934c9b9d8d2d2f2b37f050dcd3bba83c',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks on month and day event views');
  t('Events');
  $export['events_calendars'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'events_node';
  $context->description = 'Blocks that show up on all Event nodes.';
  $context->tag = 'Events';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'stanford_event' => 'stanford_event',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-934c9b9d8d2d2f2b37f050dcd3bba83c' => array(
          'module' => 'views',
          'delta' => '934c9b9d8d2d2f2b37f050dcd3bba83c',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks that show up on all Event nodes.');
  t('Events');
  $export['events_node'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'events_past';
  $context->description = 'Past Events page';
  $context->tag = 'Events';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'events/past-events' => 'events/past-events',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-ad215e0528148b386833fa3db1f3b7dc' => array(
          'module' => 'views',
          'delta' => 'ad215e0528148b386833fa3db1f3b7dc',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'views-934c9b9d8d2d2f2b37f050dcd3bba83c' => array(
          'module' => 'views',
          'delta' => '934c9b9d8d2d2f2b37f050dcd3bba83c',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Events');
  t('Past Events page');
  $export['events_past'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'events_upcoming';
  $context->description = 'Upcoming Events page in Events section';
  $context->tag = 'Events';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'events/upcoming-events' => 'events/upcoming-events',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-934c9b9d8d2d2f2b37f050dcd3bba83c' => array(
          'module' => 'views',
          'delta' => '934c9b9d8d2d2f2b37f050dcd3bba83c',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Events');
  t('Upcoming Events page in Events section');
  $export['events_upcoming'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sitewide';
  $context->description = 'Sitewide - All pages';
  $context->tag = 'Sitewide';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-stanford_jumpstart_layouts-1' => array(
          'module' => 'menu_block',
          'delta' => 'stanford_jumpstart_layouts-1',
          'region' => 'navigation',
          'weight' => '-10',
        ),
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'search_box',
          'weight' => '-10',
        ),
        'bean-jumpstart-footer-social-media--0' => array(
          'module' => 'bean',
          'delta' => 'jumpstart-footer-social-media--0',
          'region' => 'footer',
          'weight' => '-10',
        ),
        'bean-jumpstart-footer-contact-block' => array(
          'module' => 'bean',
          'delta' => 'jumpstart-footer-contact-block',
          'region' => 'footer',
          'weight' => '-8',
        ),
        'bean-optional-footer-block' => array(
          'module' => 'bean',
          'delta' => 'optional-footer-block',
          'region' => 'footer',
          'weight' => '-7',
        ),
        'menu-menu-related-links' => array(
          'module' => 'menu',
          'delta' => 'menu-related-links',
          'region' => 'footer',
          'weight' => '-6',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sitewide');
  t('Sitewide - All pages');
  $export['sitewide'] = $context;

  return $export;
}
