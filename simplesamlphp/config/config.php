<?php

/**
 * @file
 * SimpleSamlPhp Acquia Configuration.
 *
 * This file was last modified on Nov 4, 2015.
 *
 * All custom changes below. Modify as needed.
 */

/**
 ****************************************
 * GLOBAL CONFIGURATION
 * *****************************************
 */

// PHP 7
if (!is_array($config)) {
  $config = array();
}

/**
 * HTTPS vs HTTP Handling.
 */
$protocol = 'http://';
$port = ':80';
if (isset($_SERVER['HTTP_X_FORWARDED_PROTO']) && $_SERVER['HTTP_X_FORWARDED_PROTO'] == 'https') {
  $_SERVER['SERVER_PORT'] = 443;
  $_SERVER['HTTPS'] = 'true';
  $protocol = 'https://';
  $port = ':' . $_SERVER['SERVER_PORT'];
}

$config['baseurlpath'] = $protocol . $_SERVER['HTTP_HOST'] . $port . '/simplesaml/';

// Set some security and other configs that are set above, however we
// overwrite them here to keep all changes in one area.
$config['technicalcontact_name'] = "Stanford Web Services";
$config['technicalcontact_email'] = "sws-developers@stanford.edu";

// Change these for your installation.
$config['secretsalt'] = 'xn3jhrrw1sp1he6x4ao1ilwdacxgkdon';
$config['auth.adminpassword'] = '6hwuzew6csdjwam';

// Core settings
$config['authproc.sp'] = array(
  10 => array(
    'class'                 => 'core:AttributeMap',
    'oid2name',
  ),
  90 => 'core:LanguageAdaptor',
);

/**
 * Cookies No Cache.
 *
 * Allow users to be automatically logged in if they signed in via the same
 * SAML provider on another site.
 *
 * Warning: This has performance implications for anonymous users.
 *
 * @link https://docs.acquia.com/articles/using-simplesamlphp-acquia-cloud-site
 */
# setcookie('NO_CACHE', '1');


/**
 * ACQUIA ENVIRONMENT CONFIGURATION
 */
if (getenv('AH_SITE_ENVIRONMENT')) {
  include_once("config.acquia.php");
}

/**
 * LANDO LOCAL CONFIGURATION.
 */
if (getenv('LANDO') == "ON") {
  include_once("config.lando.php");
}