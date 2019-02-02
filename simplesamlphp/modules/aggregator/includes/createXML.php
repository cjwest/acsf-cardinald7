<?php
/**
 * @file
 * Generates XML metadata files.
 */

/**
 * CreateXML.
 *
 * A small class to handle the generation and saving of the xml metadata file.
 */
class CreateXML {

  /**
   * SAML Aggregators.
   *
   * SimpleSAML_Configuration::getConfig('module_aggregator.php')->getConfigItem('aggregators');
   *
   * @var object
   */
  private $aggregators;

  /**
   * Where to save the xml metadata file.
   *
   * @var string
   */
  private $filePath;

  /**
   * The id key of the aggregator to use.
   *
   * @var string
   */
  private $aggID;

  /**
   * AGG config object.
   *
   * SimpleSAML_Configuration::getConfig('module_aggregator.php')
   *
   * @var object
   */
  private $gConfig;

  /**
   * Something to do with limiting the output of the xml metadata.
   *
   * @var mixed
   */
  private $limits;

  /**
   * Something to do with excluding items from outputted metadata.
   *
   * @var mixed
   */
  private $exclude;

  /**
   * The type of file to create.
   *
   * @var string
   */
  private $mimeType = "application/xml";

  /**
   * Create this object and do a little validation.
   *
   * @param object $aggregators
   *   SimpleSAML_Configuration object from the getConfigItem method.
   * @param object $gConfig
   *   SimpleSAML_Configuration object.
   * @param string $filePath
   *   Absolute path to file location.
   * @param string $id
   *   The ID key for the aggregator in use.
   */
  public function __construct($aggregators, $gConfig, $filePath, $id) {

    // Set Aggregators.
    $this->aggregators = $aggregators;

    // Set path to XML.
    $this->filePath = $filePath;

    // Agg config object.
    $this->gConfig = $gConfig;

    // Validate Aggregator ID.
    if (!in_array($id, $aggregators->getOptions())) {
      throw new SimpleSAML\Error\NotFound('No aggregator with id ' . var_export($id, TRUE) . ' found.');
    }

    // Set the Aggregator ID.
    $this->aggID = $id;
  }

  /**
   * Set the MimeType of the file.
   *
   * @param string $type
   *   The response file type. eg: application/xml.
   */
  public function setMimeType($type) {
    if (empty($type)) {
      throw new SimpleSAML\Error\Exception('Please provide a value for mimeType.');
    }
    $this->mimeType = $type;
  }

  /**
   * Set the limits var.
   *
   * @param string $val
   *   metadata generation limits. I honestly have no idea what this does.
   */
  public function setLimits($val) {
    $this->limits = $val;
  }

  /**
   * Set the exclude var.
   *
   * @param string $val
   *   metadata generation exclusions. I honestly have no idea what this does.
   */
  public function setExclude($val) {
    $this->exclude = $val;
  }

  /**
   * Create and save an XML metadata file to disk.
   *
   * @throws SimpleSAML_Error_Exception
   *   Throws an exception if the file was not able to be written.
   */
  public function generateXML() {

    // Get aggregator configuration.
    $aConfig = $this->aggregators->getConfigItem($this->aggID);

    // Spin up a new aggregator instance.
    $aggregator = new sspmod_aggregator_Aggregator($this->gConfig, $aConfig, $this->aggID);

    // Not sure what this does exactly.
    if (!empty($this->limits)) {
      $aggregator->limitSets($this->limits);
    }

    // Set exclusions. Not sure how this works.
    if (!empty($this->exclude)) {
      $aggregator->exclude($this->exclude);
    }

    // Get ready to export some XML!!!!
    $xml = $aggregator->getMetadataDocument();

    // Special handling for plain text.
    if ($this->mimeType === 'text/plain') {
      \SimpleSAML\Utils\XML::formatDOMElement($xml);
    }

    // Create the XML document.
    $metadata = '<?xml version="1.0"?>' . "\n" . $xml->ownerDocument->saveXML($xml);

    // While this is writing lock the file.
    $bytes_written = file_put_contents($this->filePath, $metadata, LOCK_EX);
    if (!$bytes_written) {
      throw new SimpleSAML\Error\Exception("Could not write XML Metadata file to: " . $this->filePath);
    }
  }

}
