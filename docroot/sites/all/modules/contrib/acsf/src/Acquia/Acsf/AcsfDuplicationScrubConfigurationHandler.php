<?php

/**
 * @file
 * Contains AcsfDuplicationScrubConfigurationHandler.
 */

namespace Acquia\Acsf;

/**
 * Handles the scrubbing of Drupal core configuration.
 *
 * Anything that is not specifically core or absolutely required by ACSF should
 * live in gardens_duplication module.
 */
class AcsfDuplicationScrubConfigurationHandler extends AcsfEventHandler {

  /**
   * Implements AcsfEventHandler::handle().
   */
  public function handle() {
    drush_print(dt('Entered @class', array('@class' => get_class($this))));

    $options = $this->event->context['scrub_options'];

    // The Acquia Connector module puts the below values in the state system
    // (because it's a general module, not only running on Acquia Hosting
    // infrastructure) but our actual authoritative values are in an include
    // file from Hosting, e.g. D7-<hosting_site>-common-settings.inc:
    // $config['ah_network_key'] and $config['ah_network_identifier']. So we
    // need to clear them here because they are stale after we do a cross-
    // sitegroup duplication. (Hosting/ACE has no method for this because only
    // ACSF ever does cross-sitegroup site copies.)
    variable_del('acquia_identifier');
    variable_del('acquia_key');

    variable_del('cron_last');
    variable_del('cron_semaphore');
    variable_del('node_cron_last');
    variable_del('drupal_private_key');

    variable_set('cron_key', drupal_hash_base64(drupal_random_bytes(55)));

    // Ensure Drupal filesystem related configuration variables are correct for
    // the new site. Consider the following variables:
    // - file_directory_path
    // - file_directory_temp
    // - file_private_path
    // - file_temporary_path
    // Given the AH environment for Gardens, we want to leave the temp paths
    // alone, and we want to delete the other variables, to ensure they reset to
    // their defaults (because of scarecrow, these shouldn't exist in the
    // variable table anyway).
    $file_path_variables = array(
      'file_directory_path',
      'file_private_path',
    );
    foreach ($file_path_variables as $variable) {
      variable_del($variable);
    }
  }

}
