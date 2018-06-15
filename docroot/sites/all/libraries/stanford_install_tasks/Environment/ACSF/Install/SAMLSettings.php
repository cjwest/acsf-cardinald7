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

    // Enable workgroup api role mapping.
    $cert_file = dirname(DRUPAL_ROOT) . "/simplesamlphp/cert/stanford_ssp.cert";
    $key_file = dirname(DRUPAL_ROOT) . "/simplesamlphp/cert/stanford_ssp.key";
    variable_set('stanford_ssp_workgroup_api_cert', $cert_file);
    variable_set('stanford_ssp_workgroup_api_key', $key_file);
    variable_set('stanford_ssp_role_map_source', 'workgroup');

    // Add webservices role mapping.
    $admin_role = user_role_load_by_name('administrator');
    variable_set("stanford_simplesamlphp_auth_rolepopulation", $admin_role->rid . ":eduPersonEntitlement,=,itservices:webservices");

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
