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
  if (!empty($sitename)) {
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
  if (!empty($sitename)) {
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

    if (!preg_match('/stanford\.edu/', $key)) {
      continue;
    }

    // Where we get the metadata from.
    $metadata = "https://" . $key . "/simplesaml/module.php/saml/sp/metadata.php/default-sp?output=xml";

    // Check if the simpleSAMLphp URL resolves. If it does not, we get a fatal
    // error in our aggregated metadata.
    // See https://stanfordits.atlassian.net/browse/SITES-690.
    $resolver = "https://" . $key . "/simplesaml/module.php/core/frontpage_welcome.php";
    $ch = curl_init($resolver);
    // CURLOPT_NOBODY: TRUE to exclude the body from the output. Request method
    // is then set to HEAD. Changing this
    // to FALSE does not change it to GET.
    curl_setopt($ch, CURLOPT_NOBODY, TRUE);
    // CURLOPT_CONNECTTIMEOUT: The number of seconds to wait while trying to
    // connect. Use 0 to wait indefinitely.
    curl_setopt($ch, CURLOPT_CONNECTTIMEOUT, 2);
    curl_exec($ch);
    $curl_info = curl_getinfo($ch);
    curl_close($ch);

    // Check if the URL resolves with a 200. If it does, we add it to the
    // aggregated metadata.
    // See https://stanfordits.atlassian.net/browse/SITES-911.
    if (isset($curl_info['http_code']) && $curl_info['http_code'] == 200) {
      $sources[] = array('type' => 'xml', 'url' => $metadata);
    }

  }

  // An array of valid sites to generate XML metadata for.
  return $sources;
}
