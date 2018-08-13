<?php

/**
 * Build the multidimensional array that has the URLs for the XML metadata for every site on the factory.
 *
 * @return array The array of URLs for XML metadata for every site.
 */
function build_acsf_saml_metadata() {
  $sources = array();

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
    return;
  }
  $sites_info = json_decode($sites_json, TRUE);
  if ($sites_info === null) {
    return;
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
    $metadata = "https://" . $key . "/simplesaml/module.php/saml/sp/metadata.php/default-sp?output=xml";
    
    // Check if the simpleSAMLphp URL resolves. If it does not, we get a fatal error in our aggregated metadata.
    // See https://stanfordits.atlassian.net/browse/SITES-690.
    $resolver = "https://" . $key . "/simplesaml/module.php/core/frontpage_welcome.php";
    $ch = curl_init($resolver);
    // CURLOPT_CONNECT_ONLY: TRUE tells the library to perform all the required proxy authentication and connection
    // setup, but no data transfer. This option is implemented for HTTP, SMTP and POP3.
    curl_setopt($ch, CURLOPT_CONNECT_ONLY, TRUE);
    // CURLOPT_NOBODY: TRUE to exclude the body from the output. Request method is then set to HEAD. Changing this
    // to FALSE does not change it to GET.
    curl_setopt($ch, CURLOPT_NOBODY, TRUE);
    // CURLOPT_CONNECTTIMEOUT: The number of seconds to wait while trying to connect. Use 0 to wait indefinitely.
    curl_setopt($ch, CURLOPT_CONNECTTIMEOUT, 2);
    curl_exec($ch);
    
    if(!curl_errno($ch)) {
      $sources[] = array('type' => 'xml', 'url' => $metadata);
    }
  }
  return $sources;
}
