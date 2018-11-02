<?php
/**
 * @file
 * This file sets the "image_allow_insecure_derivatives" variable to TRUE.
 */

/** 
 * NOTE: This option is contentious. See https://www.drupal.org/project/drupal/releases/7.20
 * See also: https://github.com/SU-SWS/acsf-cardinald7/pull/124
 *
 * Pros:
 * Eliminates confusing 403/500 errors when derivatives do not exist
 * We had this set to TRUE on Sites 1.x, so it simplifies the migration
 *
 * Cons:
 * Potential additional server overhead
 * Potential DDOS vector
 *
 * Date of decision: 10/31/2018.
 * Decided by: Shea McKinney and John Bickar.
 *
 */

$conf['image_allow_insecure_derivatives'] = TRUE;

