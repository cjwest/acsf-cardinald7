<?php

// Set the Basic Auth credentials for the SNOW API.

switch ($_ENV['AH_SITE_ENVIRONMENT']) {
  case "02test":
    $conf['stanford_snow_api_user'] = 'acquiaWS';
    $conf['stanford_snow_api_pass'] = 'Servicenow!23';
    $conf['stanford_snow_api_endpoint'] = "https://stanfordtest.service-now.com/api/stu/su_acsf_site_requester_information/requestor";
    break;

  case "02dev":
    $conf['stanford_snow_api_user'] = 'acquiaWS';
    $conf['stanford_snow_api_pass'] = 'Servicenow!23';
    $conf['stanford_snow_api_endpoint'] = "https://stanforddev.service-now.com/api/stu/su_acsf_site_requester_information/requestor";
    break;

  default:
    $conf['stanford_snow_api_user'] = 'acquiaWS';
    $conf['stanford_snow_api_pass'] = 'SXdzspeYRRlSOmb01eeZ';
}
