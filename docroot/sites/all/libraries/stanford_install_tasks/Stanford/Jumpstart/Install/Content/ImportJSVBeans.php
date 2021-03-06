<?php
/**
 * @file
 * Abstract Task Class.
 */


namespace Stanford\Jumpstart\Install\Content;
use Stanford\Jumpstart\Install\Content\Importer\ImporterFieldProcessorCustomBody as ImporterFieldProcessorCustomBody;
use Stanford\Jumpstart\Install\Content\Importer\ImporterFieldProcessorFieldSDestinationPublish as ImporterFieldProcessorFieldSDestinationPublish;
use \ITasks\AbstractInstallTask;

/**
 *
 */
class ImportJSVBeans extends AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    // @todo: Make this an option on the install form.
    $endpoint = variable_get("stanford_content_server", "https://jsa-content.stanford.edu/jsainstall");

    // BEANS
    $uuids = array(
      'e813c236-7400-4f43-ad18-736617ceb28e', // Jumpstart Home Page Banner Image.
      'b66a5774-d0d1-44eb-abda-7aa8ea4eea0e', // Jumpstart Home Page About Block
      '2066e872-9547-40be-9342-dbfb81248589', // Jumpstart Footer Social Media Connect Block
      'ba352284-7aec-4044-a6dc-7e60441c2ccf', // Jumpstart Home Page In the Spotlight Block
      '864a97ac-ecd9-43b8-94be-da553c1e0426', // Jumpstart Footer Contact Block
      '67045bcc-06fc-4db8-9ef4-dd0ebb4e6d72', // Jumpstart Footer Optional Block
      '8c4ed672-debf-45a5-8dfc-ef42794b975b', // Jumpstart Homepage Tall Banner
      'b7a04511-fcdb-49c4-a0c0-d4340cb35746', // Jumpstart Homepage announcements Postcard
      'a4b63a55-2626-4591-a952-6db9c3c270fc', // Jumpstart Homepage announcements Block
      'b880d372-ef1c-4c85-93e8-6a47726d98c2', // Jumpstart Postcard with Video
      'd643d114-c4bc-47b0-b0df-dbf1dc673a1a', // Jumpstart Info Text Block
      'f00c9906-971f-4d9d-b75c-23db1499318c', // Jumpstart Homepage Mission Block 2 (this should be 1, I think)
      '008d2300-a00d-4de9-bdce-39f7bc9f312d', // Jumpstart Homepage Mission Block 2
      '7c1bdc2c-cd07-4404-8403-8bdbe7ebc9bb', // Jumpstart Homepage Testimonial Block
      '68d11514-1a52-4716-94b4-3ef0110e75b2', // Jumpstart Lead Text With Body
      '00d94e73-442a-4e10-93cc-243fdf87af66', // Jumpstart Lead Text No Body
    );
    $importer = new \SitesContentImporter();
    $importer->setEndpoint($endpoint);
    $importer->setBeanUuids($uuids);
    $importer->importContentBeans();

  }

  /**
   * [requirements description]
   * @return [type] [description]
   */
  public function requirements() {
    return array(
      'bean',
      'bean_admin_ui',
    );
  }

}
