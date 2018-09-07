<?php

// Set the webform export path to a directory that's on the shared file system.
// See https://insight.acquia.com/support/tickets/683662.
// See https://stanfordits.atlassian.net/browse/SITES-502.
// Only do this on prod.
if (isset($_ENV['AH_SITE_GROUP']) &&
  isset($_ENV['AH_SITE_ENVIRONMENT']) &&
  $_ENV['AH_SITE_ENVIRONMENT'] == "02live") {
    // /mnt/gfs/cardinald702live/tmp
    $conf['webform_export_path'] = "/mnt/gfs/" . $_ENV['AH_SITE_GROUP'] . $_ENV['AH_SITE_ENVIRONMENT'] . "/tmp";
}
