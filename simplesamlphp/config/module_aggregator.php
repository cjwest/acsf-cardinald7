<?php

include_once('acsf.php');
$sources = build_acsf_saml_metadata();

if (empty($_ENV['AH_SITE_ENVIRONMENT'])) {
  return;
}
// E.g., 02dev, 02test, 02live
$env = $_ENV['AH_SITE_ENVIRONMENT'];
// Create a unique "Name" attribute for the aggregated metadata for each environment.
$aggregated_metadata_name_attribute = 'acsf-' . $env;

// Use a separate key and certificate for each environment.
$key = "metadata_signing." . $env . ".pem";
$cert = "metadata_signing." . $env . ".crt";
// Configuration for the aggregator module.
$config = array(
  // List of aggregators.
  'aggregators' => array(
    $aggregated_metadata_name_attribute => array(
      'sources' => $sources,
    ),
    'example' => array(
      'sources' => array(
        array(
          'type' => 'xml',
          'url' => 'https://saml-dev.cardinalsites.stanford.edu:443/simplesaml/module.php/saml/sp/metadata.php/default-sp'
        ),
      ),
    ),
  ),

  'maxDuration' => 60 * 60 * 24 * 30, // Maximum 30 days duration on ValidUntil.

  // If base64 encoded for entity is already cached in the entity, should we
  // reconstruct the XML or re-use.
  'reconstruct' => TRUE,

  // Whether metadata should be signed.
  'sign.enable' => TRUE,

  // Private key which should be used when signing the metadata.
  'sign.privatekey' => $key,

  // Password to decrypt private key, or NULL if the private key is unencrypted.
  'sign.privatekey_pass' => NULL,

  // Certificate which should be included in the signature. Should correspond to the private key.
  'sign.certificate' => $cert,

);

