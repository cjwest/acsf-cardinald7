<?php

/**
 * Returns the sites.json hash value from cache.
 *
 * @return string|NULL
 *   Site json hash value.
 */
function build_acsf_saml_metadata_get_sites_json_hash_cache() {
  // Get the temporary directory.
  // If we're not on the ACSF environment, we never get to this point, so these
  // array keys SHOULD exist.
  $ah_tmp_dir = "/mnt/gfs/" . $_ENV['AH_SITE_GROUP'] . $_ENV['AH_SITE_ENVIRONMENT'] . "/tmp";

  // If does not exist you can use the /tmp dir.
  if (!is_dir($ah_tmp_dir)) {
    $ah_tmp_dir = "/tmp";
  }

  // If the hash file exists get its contents.
  $sites_json_hash_file = "sites_json_hash";

  // Hash of sites.json used to check for changes.
  $sites_hash = NULL;

  // If the file exists get the hash out of the file.
  if (file_exists($ah_tmp_dir . "/" . $sites_json_hash_file)) {
    $sites_hash = file_get_contents($ah_tmp_dir . "/" . $sites_json_hash_file);
  }

  return $sites_hash;
}

/**
 * Returns the sites.json hash value.
 *
 * @return string|NULL
 *   Site json hash value.
 */
function build_acsf_saml_metadata_sites_json_hash() {
  $sitename = getenv('AH_SITE_NAME');
  // Grab the canonical sites.json file if on the ACSF environment.
  if (!empty($sitename) && is_file('/mnt/files/' . $sitename . '/files-private/sites.json')) {
    $sites_json_file = '/mnt/files/' . $sitename . '/files-private/sites.json';
  }
  // Fall back to a file in /tmp if not. Useful for local development.
  else {
    $sites_json_file = '/tmp/sites.json';
  }

  return md5(file_get_contents($sites_json_file));
}

/**
 * Set the hash value of the current sites.json.
 *
 * @param string $hash
 *   The md5 value of the sites.json file.
 */
function build_acsf_saml_metadata_set_sites_json_hash($hash) {
  // Get the temporary directory.
  $ah_tmp_dir = "/mnt/gfs/" . $_ENV['AH_SITE_GROUP'] . $_ENV['AH_SITE_ENVIRONMENT'] . "/tmp";

  // If does not exist you can use the /tmp dir.
  if (!is_dir($ah_tmp_dir)) {
    $ah_tmp_dir = "/tmp";
  }

  // If the hash file exists get its contents.
  $sites_json_hash_file = "sites_json_hash";

  // Save the new hash to the file.
  file_put_contents($ah_tmp_dir . "/" . $sites_json_hash_file, $hash, LOCK_EX);
}

/**
 * Generate XML metadata.
 *
 * Build the multidimensional array that has the URLs for the XML metadata for
 * every site on the factory.
 *
 * @return array
 *   The array of URLs for XML metadata for every site.
 */
function build_acsf_saml_metadata() {
  $sources = [];
  $sitename = getenv('AH_SITE_NAME');

  // Grab the canonical sites.json file if on the ACSF environment.
  if (!empty($sitename) && is_file('/mnt/files/' . $sitename . '/files-private/sites.json')) {
    $sites_json_file = '/mnt/files/' . $sitename . '/files-private/sites.json';
  }
  // Fall back to a file in /tmp if not. Useful for local development.
  else {
    $sites_json_file = '/tmp/sites.json';
  }

  $sites_json = file_get_contents($sites_json_file);
  if (!$sites_json) {
    throw new SimpleSAML_Error_Exception("Could not get contents of sites.json");
  }

  $sites_info = json_decode($sites_json, TRUE);
  if ($sites_info === NULL) {
    throw new SimpleSAML_Error_Exception("Could not decode the contents of sites.json");
  }

  if (array_key_exists('sites', $sites_info)) {
    $sites_info = $sites_info['sites'];
  }

  // TODO: use the preferred_domain value instead of just *.stanford.edu
  // See https://stanfordits.atlassian.net/browse/SITES-651.
  foreach ($sites_info as $key => $value) {

    // Only stanford.edu and other custom domains. No Acquia/acsitefactory.com domains.
    if (preg_match('/acsitefactory.com/', $key)) {
      continue;
    }

    // Where we get the metadata from.
    $metadata = "https://" . $key . "/simplesaml/module.php/saml/sp/metadata.php/default-sp?output=xml";
    $sources[] = array('type' => 'xml', 'url' => $metadata);

  }

  // An array of valid sites to generate XML metadata for.
  return $sources;
}
