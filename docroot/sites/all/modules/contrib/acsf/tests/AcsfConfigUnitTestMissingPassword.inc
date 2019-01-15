<?php

/**
 * AcsfConfigUnitTestMissingPassword.
 */
class AcsfConfigUnitTestMissingPassword extends \Acquia\Acsf\AcsfConfig {

  /**
   * Implements AcsfConfig::loadConfig().
   */
  protected function loadConfig() {
    $this->url = 'http://gardener.unit.test';
    $this->username = 'gardener_unit_test';
  }

}
