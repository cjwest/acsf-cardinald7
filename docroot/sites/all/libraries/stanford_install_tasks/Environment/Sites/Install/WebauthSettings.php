<?php
/**
 * @file
 * Abstract Task Class
 */

namespace Environment\Sites\Install;
use \ITasks\AbstractInstallTask;

class WebauthSettings extends AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *  Installation arguments.
   */
  public function execute(&$args = array()) {

  }

  /**
   * @param array $tasks
   */
  public function requirements() {
    return array(
      'webauth',
      'stanford_webauth_block', // on environment branch
    );
  }

}
