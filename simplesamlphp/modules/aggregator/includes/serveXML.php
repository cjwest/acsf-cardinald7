<?php
/**
 * @file
 * Ship out an XML file to the browser.
 */

/**
 * ServeXML.
 *
 * Fetches and passes through an XML file to the browser.
 */
class ServeXML {

  /**
   * The path to the XML file.
   *
   * @var string
   */
  private $filePath;

  /**
   * The type of file to serve to the browser.
   *
   * @var string
   */
  private $mimeType = "application/xml";

  /**
   * How long the file should be cached in varnish/browser for in seconds.
   *
   * @var string
   */
  private $maxAge = '600';

  /**
   * Build me up, buttercup, don't let me down.
   *
   * @param string $filePath
   *   The path to the file to serve.
   *
   * @throws SimpleSAML_Error_Exception
   *   Throws an exception when the file it should serve doesn't exist.
   */
  public function __construct($filePath) {
    // Store the file path.
    $this->filePath = $filePath;

    // Throw up if something doesn't work.
    if (!is_file($filePath)) {
      throw new SimpleSAML_Error_Exception("Could not find a file to serve up.");
    }
  }

  /**
   * Set the MimeType of the response.
   *
   * @param string $type
   *   The response file type. eg: application/xml.
   *
   * @throws SimpleSAML_Error_Exception
   *   Throws an exception if sent in param does not pass validation.
   */
  public function setMimeType($type) {
    if (empty($type)) {
      throw new SimpleSAML_Error_Exception('Please provide a value for mimeType.');
    }
    $this->mimeType = $type;
  }

  /**
   * Set the maxAge of the response.
   *
   * @param string $age
   *   The response max age in seconds.
   *
   * @throws SimpleSAML_Error_Exception
   *   Throws an exception if sent in param does not pass validation.
   */
  public function setMaxAge($age) {
    if (empty($age)) {
      throw new SimpleSAML_Error_Exception('Please provide a value for maxAge.');
    }
    $this->maxAge = $age;
  }

  /**
   * Sends through an XML file with all the correct headers.
   *
   * @throws SimpleSAML_Error_Exception
   *   When content of file is empty or == 0 bytes.
   */
  public function sendToBrowser() {

    // Get how big.
    $contentLength = sprintf('%u', filesize($this->filePath));
    // When was this file last modified.
    $modTime = filemtime($this->filePath);

    // If there is nothing in the file throw an error.
    if ($contentLength <= 0) {
      throw new SimpleSAML_Error_Exception("Content length of file to serve was 0.");
    }

    // Set the content length.
    header('Content-Length: ' . $contentLength);
    // Set the mimetype. Typically xml.
    header('Content-Type: ' . $this->mimeType);
    // Max Age setting in seconds. Good for varnish.
    header('Cache-Control: public,max-age=' . $this->maxAge);
    // When this file should be expected as stale and expired. 10 minutes.
    header('Expires: ' . gmdate('D, j M Y H:i:s \G\M\T', time() + 10 * 60));
    // When was this file last modified.
    header('Last-Modified: ' . gmdate('D, j M Y H:i:s \G\M\T', $modTime));
    // Generate an e-tag for this.
    header('ETag: ' . md5($modTime));

    // Send the file to the user.
    readfile($this->filePath);
  }

}
