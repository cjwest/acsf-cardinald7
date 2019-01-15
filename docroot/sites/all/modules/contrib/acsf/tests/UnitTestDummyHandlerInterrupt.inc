<?php

/**
 * UnitTestDummyHandlerInterrupt.
 */
class UnitTestDummyHandlerInterrupt extends \Acquia\Acsf\AcsfEventHandler {

  /**
   * Dummy handler.
   */
  public function handle() {
    $this->event->dispatcher->interrupt();
  }

}
