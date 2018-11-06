<?php

// If aggregator ID is not provided, show the list of available aggregates.
if (!array_key_exists('id', $_GET)) {
  $t = new SimpleSAML_XHTML_Template($config, 'aggregator:list.php');
  $t->data['sources'] = $aggregators->getOptions();
  $t->show();
  exit();
}

// Get id from parameters.
$id = htmlspecialchars($_GET['id']);
if (!in_array($id, $aggregators->getOptions())) {
  throw new SimpleSAML_Error_NotFound('No aggregator with id ' . var_export($id, TRUE) . ' found.');
}

// Get aggregator configuration.
$aConfig = $aggregators->getConfigItem($id);

// Spin up a new aggregator instance.
$aggregator = new sspmod_aggregator_Aggregator($gConfig, $aConfig, $id);

if (isset($_REQUEST['set'])) {
  $aggregator->limitSets(htmlspecialchars($_REQUEST['set']));
}

if (isset($_REQUEST['exclude'])) {
  $aggregator->exclude(htmlspecialchars($_REQUEST['exclude']));
}

// Get ready to export some XML!!!!
$xml = $aggregator->getMetadataDocument();

// End users can send in their requested mimetime. Prepare valid options.
$mimetype = 'application/samlmetadata+xml';
$allowedmimetypes = array(
  'text/plain',
  'application/samlmetadata-xml',
  'application/xml',
);

// All the user to set one of the options form the above array.
if (isset($_GET['mimetype']) && in_array($_GET['mimetype'], $allowedmimetypes)) {
  $mimetype = $_GET['mimetype'];
}

// Special handling for plain text.
if ($mimetype === 'text/plain') {
  SimpleSAML_Utilities::formatDOMElement($xml);
}

// Create the XML document.
$metadata = '<?xml version="1.0"?>' . "\n" . $xml->ownerDocument->saveXML($xml);

// Prepare the output headers.
header('Content-Type: ' . $mimetype);
header('Content-Length: ' . strlen($metadata));

// Print the XML document to the screen as if it were an XML DOC.
echo $metadata;
