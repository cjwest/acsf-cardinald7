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
class FileSettings extends AbstractInstallTask {

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
      'file',
    );
  }

  /**
   * [installTaskAlter description]
   * @param  [type] &$tasks [description]
   * @return [type]         [description]
   */
  public function installTaskAlter(&$tasks) {
    // As ACSF has a crazy name for the public file path we need to remove the
    // default settings of sites/default/files
    unset($tasks['StanfordDrupalProfileFileSettings']);
 }

}
