<?php

/**
 * AcsfConfigUnitTestMissingUsername.
 */
class AcsfConfigUnitTestMissingUsername extends \Acquia\Acsf\AcsfConfig {

  /**
   * Implements AcsfConfig::loadConfig().
   */
  protected function loadConfig() {
    $this->url = 'http://gardener.unit.test';
    $this->password = 'Un1tT35t';
  }

}
