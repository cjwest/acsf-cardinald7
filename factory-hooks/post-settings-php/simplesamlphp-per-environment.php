<?php
/**
 * @file
 * This file configures the path to simplesamlphp on a per-environment basis.
 */

// AH_SITE_NAME = cardinald702dev
// AH_SITE_ENVIRONMENT = 02dev
// AH_SITE_GROUP = cardinald7
if (isset($_ENV['AH_SITE_NAME'])) {
  $conf['stanford_simplesamlphp_auth_installdir'] = '/var/www/html/' . $_ENV['AH_SITE_NAME'] . '/simplesamlphp';
}
