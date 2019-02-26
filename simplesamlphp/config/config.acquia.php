<?php
/**
 * @file
 * SimpleSamlPhp Acquia Configuration.
 *
 * This file was last modified on in July 2018.
 *
 * All custom changes below. Modify as needed.
 */

/**
 * Defines Acquia account specific options in $config keys.
 *
 *   - 'store.sql.name': Defines the Acquia Cloud database name which
 *     will store SAML session information.
 *   - 'store.type: Define the session storage service to use in each
 *     Acquia environment ("defaults to sql").
 */

/**
 * Generate Acquia session storage via hosting creds.json.
 *
 * Session sorage defaults using the database for the current request.
 *
 * @link https://docs.acquia.com/resource/using-simplesamlphp-acquia-cloud-site/#storing-session-information-using-the-acquia-cloud-sql-database
 */

// Set  ACE and ACSF sites based on hosting database and site name.
$config['certdir'] = "/mnt/www/html/{$_ENV['AH_SITE_NAME']}/simplesamlphp/cert/";
$config['metadatadir'] = "/mnt/www/html/{$_ENV['AH_SITE_NAME']}/simplesamlphp/metadata";
$config['baseurlpath'] = $protocol . $_SERVER['HTTP_HOST'] . $port . '/simplesaml/';
// Setup basic logging.
$config['logging.handler'] = 'file';
$config['loggingdir'] = dirname(getenv('ACQUIA_HOSTING_DRUPAL_LOG'));
$config['logging.logfile'] = 'simplesamlphp-' . date('Ymd') . '.log';
$creds_json = file_get_contents('/var/www/site-php/' . $_ENV['AH_SITE_NAME'] . '/creds.json');
$databases = json_decode($creds_json, TRUE);
$creds = $databases['databases'][$_ENV['AH_SITE_GROUP']];
require_once "/usr/share/php/Net/DNS2_wrapper.php";
try {
  $resolver = new Net_DNS2_Resolver(array(
    'nameservers' => array(
      '127.0.0.1',
      'dns-master',
    ),
  ));
  $response = $resolver->query("cluster-{$creds['db_cluster_id']}.mysql", 'CNAME');
  $creds['host'] = $response->answer[0]->cname;
}
catch (Net_DNS2_Exception $e) {
  $creds['host'] = "";
}
$config['store.type'] = 'sql';
$config['store.sql.dsn'] = sprintf('mysql:host=%s;port=%s;dbname=%s', $creds['host'], $creds['port'], $creds['name']);
$config['store.sql.username'] = $creds['user'];
$config['store.sql.password'] = $creds['pass'];
$config['store.sql.prefix'] = 'simplesaml';
