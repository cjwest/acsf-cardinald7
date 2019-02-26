<?php
/**
 * @file
 * Configuration for the metadata aggregator script.
 */

// Only run on the AH environments.
if (empty($_ENV['AH_SITE_ENVIRONMENT'])) {
  throw new SimpleSAML_Error_Exception("Can only run aggregator on Acquia environments.");
}

// E.g., 02dev, 02test, 02live.
$env = $_ENV['AH_SITE_ENVIRONMENT'];
switch ($env) {
  case '02dev':
  case '02devup':
    $env = "02dev";
    break;

  case '02test':
  case '02testup':
    $env = "02test";
    break;

  case '02update':
  default:
    $env = "02live";
    break;
}

// Only populate this var if we need to. The sources build out causes a curl
// call to every site on the stack.
$sources = (isset($_SESSION['build_with_sources'])) ? build_acsf_saml_metadata() : [];

// Create a unique "Name" attribute for the aggregated metadata for each
// environment.
$aggregated_metadata_name_attribute = 'acsf-' . $env;

// Use a separate key and certificate for each environment.
$key = "metadata_signing." . $env . ".pem";
$cert = "metadata_signing." . $env . ".crt";

// Generate a path to a shared tmp directory.
$ah_tmp = "/mnt/gfs/" . $_ENV['AH_SITE_NAME'] . "/tmp";

// Configuration for the aggregator module.
$config = [
  // List of aggregators.
  'aggregators' => [
    $aggregated_metadata_name_attribute => [
      'sources' => $sources,
    ],
    'example' => [
      'sources' => [
        [
          'type' => 'xml',
          'url' => 'https://saml.sites.stanford.edu:443/simplesaml/module.php/saml/sp/metadata.php/default-sp',
        ],
      ],
    ],
  ],

  // URL parameter to trigger XML generation.
  'genKey' => 'm1fCmGgUfpTOtfvTE7kDs6LUC58bBjltiOqShatXAI',

  // Static HTML generation path.
  // Resolves to something like:
  // `/mnt/gfs/cardinald702dev/tmp/saml-aggregate-metadata.xml`.
  'xmlTmp' => is_dir($ah_tmp) ? $ah_tmp . "/saml-aggregate-metadata.xml" : '/tmp/saml-aggregate-metadata.xml',

  // Maximum 30 days duration on ValidUntil.
  'maxDuration' => 60 * 60 * 24 * 30,

  // If base64 encoded for entity is already cached in the entity, should we
  // reconstruct the XML or re-use.
  'reconstruct' => TRUE,

  // Whether metadata should be signed.
  'sign.enable' => TRUE,

  // Private key which should be used when signing the metadata.
  'sign.privatekey' => $key,

  // Password to decrypt private key, or NULL if the private key is unencrypted.
  'sign.privatekey_pass' => NULL,

  // Certificate which should be included in the signature. Should correspond to
  // the private key.
  'sign.certificate' => $cert,

];
