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
// Force https?
//$conf['https'] = TRUE;
// UAT Endpoint for local.
$conf['stanford_ssp_workgroup_api_endpoint'] = "https://workgroupsvc-uat.stanford.edu/v1/workgroups/";
// UAT key and cert for local.
// Enable workgroup api role mapping.
$cert_file = dirname(DRUPAL_ROOT) . "/simplesamlphp/cert/stanford_ssp-test.cert";
$key_file = dirname(DRUPAL_ROOT) . "/simplesamlphp/cert/stanford_ssp-test.key";
$conf['stanford_ssp_workgroup_api_cert'] = $cert_file;
$conf['stanford_ssp_workgroup_api_key'] = $key_file;
