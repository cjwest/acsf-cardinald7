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
    // Remove this dependency because it conflicts with our login.
    $modules = array('acsf_openid', 'openid');
    module_disable($modules, FALSE);
    drupal_uninstall_modules($modules, FALSE);
  }

  /**
   * Dependencies.
   */
  public function requirements() {
    return array(
      'acsf',
      'acsf_helper',
      'paranoia',
      'stanford_ssp',
      'stanford_saml_block',
      'syslog',
    );
  }

}
