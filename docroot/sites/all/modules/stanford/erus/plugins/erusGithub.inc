<?php
/**
 * @file
 * ERUS GitHub plugin.
 *
 * Uses V3 of the github API.
 *
 */

use \Github\Client as GithubClient;

class erusGithub extends erusPlugin {

  /**
   * Configuration form for the plugin.
   * @return [type] [description]
   */
  public function get_configuration_form() {
    $form = array();

    $form['privateonly']['#markup'] = "<p>" . t('Entering a username and password is only required if you have private repositories') . ".</p>";

    $description = 'Enter a GitHub password.';
    if (!module_exists('encrypt')) {
      drupal_set_message(t('It is recommended that you install the') . ' ' . l('encrypt', 'http://dgo.to/encrypt') . t(' module so that your password is not stored in plain text'), 'warning', FALSE);
      $description .= " WARNING: Password is stored in plain text.";
    }

    $form['username'] = array(
      '#type' => 'textfield',
      '#title' => t('Username'),
      '#description' => t('Enter a GitHub username'),
    );

    $form['password'] = array(
      '#type' => 'password',
      '#title' => t('Password'),
      '#description' => t($description),
    );

    return $form;
  }

  /**
   * The Magic Happens.
   * @param  $data  [description]
   * @return [type] [description]
   */
  public function process($data) {

    // Go old or go home.
    if (!isset($data['info']['datestamp'])) {
      $data['info']['datestamp'] = 0;
    }

    // Store data for later
    $this->set_update_data($data);
    $this->authenticate_with_github();

    $client = $this->get_client();
    $github_data = $client->api('repo')->releases()->all($this->get_account(), $this->get_project_name());

    $code = $client->getHttpClient()->getLastResponse()->getStatusCode();

    if ($code !== 200) {
      watchdog('erus', 'GitHub API returned with response code: ' . $code . ' for: ' . $this->get_project_name(), array(), WATCHDOG_ERROR);
      return false;
    }

    // If the github data is an array and not empty get the first element.
    if (!is_array($github_data) || empty($github_data)) {
      return false;
    }

    $releases = $github_data;
    // Convert GH data into update modules data.
    $available = $this->map_data($releases);
    // Sanitize the status of the data from the original call
    $this->sanitize_info_data($data);

    // Allow update module to do its magic.
    update_calculate_project_update_status($this->get_project_name(), $data, $available);

    // Small hack to show update is available instead of unsupported...
    if ($data['status'] == 3) {
      $data['status'] = 4;
    }

    return $data;
  }

  /**
   * [get_client description]
   * @return [type] [description]
   */
  protected function get_client() {
    if (is_null($this->client)) {
      $client = new GithubClient();
      $this->set_client($client);
    }
    return $this->client;
  }

  /**
   * Maps the GH response data into Update status usable format.
   * @param  [type] $releases [description]
   * @return [type]                 [description]
   */
  protected function map_data($releases) {
    $update_data = $this->get_update_data();
    $data = $this->get_default_update_status_available_data_array();

    $latest_release = $this->get_latest_release($releases);
    $dev_release = $this->get_latest_dev_release($releases);

    $latest_prod_tag = !empty($latest_release['tag_name']) ? $latest_release['tag_name'] : $dev_release["tag_name"];

    $data['title'] =                $update_data['info']['name'];
    $data['short_name'] =           $update_data['name'];
    //$data['type'] =                 $update_data['project_type'];
    $data['link'] =                 $this->get_project_url($latest_release);
    $data['last_fetch'] =           time();

    $data['recommended_major'] =    $this->parse_latest_major($latest_prod_tag);
    $data['supported_majors'] =     implode(",", range(1,99));
    $data['default_major'] =        $this->parse_latest_major($latest_prod_tag);
//    $data['latest_version'] =       $dev_release['tag_name'];
//    $data['dev_version'] =          $this->parse_latest_major($latest_prod_tag);


    foreach ($releases as $index => $release) {
      $tag_name = $release['tag_name'];
      $tag_parts = explode('-', $tag_name);

      // Create a url to the tarball
      $download_link = "https://github.com/" . $this->get_account() . "/" . $this->get_project_name() . "/archive/" . $release['tag_name'] . ".tar.gz";

      // If there is an asset use that one.
      if (isset($release['assets'][0])) {
        $download_link = "https://github.com/" . $this->get_account() . "/" . $this->get_project_name() . "/releases/download/" . $release['tag_name'] . "/" . $release['assets'][0]['name'];
      }

      // GH doesn't provide a checksum on files. We will have to provide it in
      // the body.
      $md5 = $this->parse_md5_checksum($release['body']);

      $data['releases'][$tag_name] =  array(
        'name' => $update_data['name'] . ' ' . $tag_name,
        'version' => $tag_name,
        'tag' => $tag_name,
        'version_major' => $this->parse_latest_major($tag_name),
        'version_patch' => $this->parse_latest_minor($tag_name),
        'version_extra' => @$tag_parts[2],
        'status' => 'published',
        'release_link' => $release['html_url'],
        'download_link' => $download_link,
        'date' => strtotime($release['published_at']), // when the release was published.
        // 'date' => strtotime($release['created_at']), // when the tag was created
        'mdhash' => !empty($md5) ? $md5 : md5($release['url']), // just making this stuff up.
        'filesize' => isset($release['assets'][0]) ? $release['assets'][0]['size'] : 0,
        'files' => "\n  \n  \n  ",
        'terms' => $this->parse_release_terms($release['body']),
      );

    }

    // sort by name so that the list shows up as:
    // 7.x-1.1-alpha1
    // 7.x-1.0
    // 7.x-1.0-beta11
    // 7.x-1.0-beta10
    // 7.x-1.0-beta9

    $keys = array_keys($data['releases']);

    uasort($keys, function($a, $b) {
      if ($a == $b) {
        return 0;
      }
      $a = str_replace('7.x-', '', $a);
      $b = str_replace('7.x-', '', $b);

      return version_compare($a, $b, '>') ? -1 : 1;
      }
    );
    $keys = array_flip($keys);
    $data['releases'] = array_merge($keys, $data['releases']);
    return $data;
  }

  /**
   * Look for "Release type:" in the body of a release for tag information.
   * Tags should be a comma separated list
   * eg: Release type: Bug fixes, New features, Security update
   * @param  string $string [description]
   * @return [type]         [description]
   */
  protected function parse_release_terms($string = '') {
    $terms = array('Release type' => array());

    preg_match_all('/Release type:.*\n/', $string, $matches);
    $found = array_pop($matches);

    if (!empty($found)) {
      $found = str_replace("Release type:", "", $found[0]);
      $found = str_replace(", ", ",", $found);
      $found = str_replace(" ,", ",", $found);
      $found = trim($found);
      $terms['Release type'] = explode(",", $found);
    }
    else {
      $terms['Release type'] = array('Bug fixes');
    }


    return $terms;
  }

  /**
   * Parses out the md5 checksum value from the body of a release.
   * This is needed for 'drush up' to work
   * @param  string $string [description]
   * @return [type]         [description]
   */
  protected function parse_md5_checksum($string = '') {
    preg_match_all('/md5:.*\n/', $string, $matches);
    $found = array_pop($matches);
    if (!empty($found)) {
      $md5 = str_replace("md5: ", "", $found[0]);
      return trim($md5);
    }
    return FALSE;
  }


  /**
   * Goes through the releases looking for a release that isnt marked as
   * a "pre-lease" in the github ui.
   * @param  [array] $releases [all of the releases from GH]
   * @return [array]           [the latest marked as non prerelease]
   */
  protected function get_latest_release($releases) {
    $potentials = array();

    foreach ($releases as $i => $release) {
      if ($release['draft'] == TRUE || $release['prerelease'] == TRUE) {
        continue;
      }
      $potentials[$release['tag_name']] = $release;
    }

    if (empty($potentials)) {
      return FALSE;
    }

    // Silly ksort will put 7.x-1.0-alpha1 in front of 7.x-1.0
    krsort($potentials);
    $key = array_shift($potentials);

    $parts = explode("-", $key["tag_name"]);
    if (isset($potentials[$parts[0] . "-" . $parts[1]])) {
      return $potentials[$parts[0] . "-" . $parts[1]];
    }
    else {
      return $key;
    }

  }

  /**
   * Looks for the latest tag marked with pre-release
   * @param  [type] $releases [description]
   * @return [type]           [description]
   */
  protected function get_latest_dev_release($releases) {
    foreach ($releases as $i => $release) {
      if ($release['prerelease'] == TRUE) {
        return $release;
      }
    }
  }

  /**
   * Return a link to the github page.
   * @param  [type] $releases [description]
   * @return [type]           [description]
   */
  protected function get_project_url($release) {
    $bits = parse_url($release['html_url']);
    $its_n_bits = explode("/", ltrim($bits['path'], "/"));
    return $bits['scheme'] . "://" . $bits['host'] . "/" . $its_n_bits[0] . "/" . $its_n_bits[1];
  }

  /**
   * Sends a username and password to authenticate (OAuth) with GH.
   */
  protected function authenticate_with_github() {
    $client = $this->get_client();
    $settings = variable_get('erus_github.com', array());

    if (empty($settings['username'])) {
      return;
    }

    $password = $settings['password'];

    // Only if the module exists.
    if (module_exists('encrypt')) {
      $password = decrypt($settings['password']);
    }

    $client->authenticate($settings['username'], $password, GithubClient::AUTH_HTTP_PASSWORD);
    $this->set_client($client);
  }


}
