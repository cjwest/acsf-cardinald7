<?php

/**
 * Lando settings for cardinald7.sws
 */

//$protocol = 'https://';
//$config['baseurlpath'] = $protocol . $_SERVER['HTTP_HOST'] . '/simplesaml/';
$database = !empty(getenv('DB_NAME')) ? getenv('DB_NAME') : 'drupal';
$username = !empty(getenv('DB_USER')) ? getenv('DB_USER') : 'drupal';
$password = !empty(getenv('DB_PASSWORD')) ? getenv('DB_PASSWORD') : 'drupal';
$host = !empty(getenv('DB_HOST')) ? getenv('DB_HOST') : 'database';

// $config['debug'] = TRUE;
$config['showerrors'] = TRUE;
$config['errorreporting'] = TRUE;
// $config['logging.level'] = SimpleSAML\Logger::DEBUG;
$config['enable.http_post'] = TRUE;
// $config['debug.validatexml'] = TRUE;
$config['trusted.url.domains'] = array(
  'cardinald7.sws:443',
  'cardinald7.sws:80',
  'cardinald7.sws',
);
$config['database.dsn'] = 'mysql:host=' . $host . ';dbname=' . $database;
$config['database.username'] = $username;
$config['database.password'] = $password;
$config['enable.saml20-idp'] = TRUE;
$config['session.duration'] = 8 * (60 * 60); // 8 hours.
$config['session.datastore.timeout'] = (4 * 60 * 60); // 4 hours
$config['session.state.timeout'] = (60 * 60); // 1 hour
//$config['session.cookie.name'] = 'SimpleSAMLSessionID';
//$config['session.cookie.lifetime'] = 0;
//$config['session.cookie.path'] = '/';
//$config['session.cookie.secure'] = true;
//$config['session.cookie_domain'] = 'cardinald7.sws';
//$config['session.phpsession.cookiename'] = null;
//$config['session.phpsession.savepath'] = null;
//$config['session.phpsession.httponly'] = true;
$config['session.authtoken.cookiename'] = 'SimpleSAMLAuthToken';
$config['session.rememberme.enable'] = false;
$config['session.rememberme.checked'] = false;
$config['session.rememberme.lifetime'] = (14 * 86400);
$config['store.type']          = 'sql';
$config['store.sql.dsn']       = 'mysql:host=' . $host . ';dbname=' . $database;
$config['store.sql.username']  = "drupal";
$config['store.sql.password']  = "drupal";
$config['store.sql.prefix']    = '';