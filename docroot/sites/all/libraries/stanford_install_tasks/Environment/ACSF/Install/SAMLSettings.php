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
class SAMLSettings extends AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {
    // Change some configuration in the saml paths:
    $ah_stack = getenv('AH_SITE_GROUP');
    $ah_env = getenv('AH_SITE_ENVIRONMENT');
    $pathtosimplesaml = "/var/www/html/" . $ah_stack . "." . $ah_env . "/simplesamlphp";
    variable_set('stanford_simplesamlphp_auth_installdir', $pathtosimplesaml);
  }

  /**
   * Dependencies.
   */
  public function requirements() {
    return array(
      'stanford_ssp',
    );
  }

}
