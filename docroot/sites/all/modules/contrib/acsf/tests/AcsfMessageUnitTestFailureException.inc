<?php

/**
 * AcsfMessageUnitTestFailureException.
 */
class AcsfMessageUnitTestFailureException extends \Acquia\Acsf\AcsfMessage {

  /**
   * Implements AcsfMessage::sendMessage().
   */
  protected function sendMessage($url, $method, $endpoint, array $parameters, $username, $password) {
    throw new \Acquia\Acsf\AcsfMessageFailureException('error message');
  }

}
