<?php
/**
 * @file
 * This file has been modified.
 *
 * This file has been edited from it's original source and should be
 * considered custom to this project. It generates a static XML file in which
 * it serves up.
 */

require_once dirname(__FILE__) . "/../includes/serveXML.php";
require_once dirname(__FILE__) . "/../includes/createXML.php";
require_once dirname(__FILE__) . "/../includes/acsf.php";

// Start up Simplesaml.
$saml = \SimpleSAML\Configuration::getInstance();
$gConfig = \SimpleSAML\Configuration::getConfig('module_aggregator.php');

// Check for the genKey URL parameter. If no parameter was sent then we should
// just return the static XML document if available. If not available, generate
// the static XML file and return it to the asker.
$genKey = $gConfig->getValue('genKey');
$xmlFile = $gConfig->getValue('xmlTmp');

// -----------------------------------------------------------------------------
// GENERATE
// If the request has the genKey correct generate new XML metadata.
// -----------------------------------------------------------------------------
if (isset($_REQUEST['genKey']) && htmlspecialchars($_REQUEST['genKey']) == $genKey) {

  // Ensure this doesn't get cached in Varnish.
  header('Cache-control: no-cache');

  // Before we go any further check to see if sites.json has changed.
  $cache_hash = build_acsf_saml_metadata_get_sites_json_hash_cache();
  $new_hash = build_acsf_saml_metadata_sites_json_hash();

  // If we have a match no need to continue.
  if ($cache_hash == $new_hash) {
    exit("No new changes.");
  }

  // If we don't have a match generate the $sources for the config and cache
  // the new hash.
  build_acsf_saml_metadata_set_sites_json_hash($new_hash);

  // Add the sources to the metadata file.
  $_SESSION['build_with_sources'] = TRUE;
  \SimpleSAML\Configuration::clearInternalState();
  $gConfig = \SimpleSAML\Configuration::getConfig('module_aggregator.php');

  // Get list of aggregators.
  $aggregators = $gConfig->getConfigItem('aggregators');

  $id = htmlspecialchars($_GET['id']);
  $createXML = new CreateXML($aggregators, $gConfig, $xmlFile, $id);

  // Optional Params.
  if (isset($_REQUEST['set'])) {
    $createXML->setLimit(htmlspecialchars($_REQUEST['set']));
  }

  // Optional Param.
  if (isset($_REQUEST['exclude'])) {
    $createXML->setExclude(htmlspecialchars($_REQUEST['exclude']));
  }

  // Allow the user to set the mimetype.
  if (isset($_GET['mimetype'])) {
    $createXML->setMimeType(htmlspecialchars($_GET['mimetype']));
  }

  // Do it.
  $createXML->generateXML();

  // Yay.
  exit('Success.');
}

// -----------------------------------------------------------------------------
// SERVE
// If the request does not have the genKey try to serve up the static xml file.
// -----------------------------------------------------------------------------
if (!isset($_REQUEST['genKey']) && file_exists($xmlFile)) {
  $serveXML = new ServeXML($xmlFile);
  $serveXML->sendToBrowser();
  exit();
}

// -----------------------------------------------------------------------------
// LIST
// If aggregator ID is not provided, show the list of available aggregates.
// -----------------------------------------------------------------------------
if (!array_key_exists('id', $_GET)) {
  $t = new SimpleSAML\XHTML\Template($saml, 'aggregator:list.php');
  $t->data['sources'] = $aggregators->getOptions();
  $t->show();
  exit();
}

// If the file does not exist and no keys were provided, error out, and let the
// user know.
throw new SimpleSAML\Error\Exception("Could not serve metadata or metadata file doesn't exist.");
