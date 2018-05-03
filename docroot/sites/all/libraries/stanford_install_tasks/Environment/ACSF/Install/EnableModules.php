<?php
/**
 * @file
 * Abstract Task Class.
 */

namespace Environment\ACSF\Install;
use \ITasks\AbstractInstallTask;

/**
 *
 */
class EnableModules extends AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {
    // Nothing to see here.
  }

  /**
   * Dependencies.
   */
  public function requirements() {
    return array(
      'acsf',
      'paranoia',
      'newrelic_appname',
      'stanford_ssp',
      'stanford_saml_block'
    );
  }

}
