<?php

/**
 * Local Database Defaults For Lando.
 */
$databases = array(
  'default' =>
  array(
    'default' =>
    array(
      'database' => !empty(getenv('DB_NAME')) ? getenv('DB_NAME') : 'drupal',
      'username' => !empty(getenv('DB_USER')) ? getenv('DB_USER') : 'drupal',
      'password' => !empty(getenv('DB_PASSWORD')) ? getenv('DB_PASSWORD') : 'drupal',
      'host' => !empty(getenv('DB_HOST')) ? getenv('DB_HOST') : 'database',
      'port' => !empty(getenv('DB_PORT')) ? getenv('DB_PORT') : 3306,
      'driver' => 'mysql',
      'prefix' => '',
    ),
  ),
);

// Local path to simpesamlphp.
$conf['stanford_simplesamlphp_auth_installdir'] = "/app/simplesamlphp";
// The SP for local development.
$conf['stanford_simplesamlphp_auth_authsource'] = "cardinald7";
// Force https for the sake of SAML auth.
$conf['stanford_ssp_force_https'] = TRUE;
