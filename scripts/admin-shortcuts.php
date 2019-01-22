<?php
// Get all menu items in the admin shortcut menu that are part of reports.
$mlid = db_select('menu_links', 'ml')
  ->fields('ml', (array('mlid')))
  ->condition('link_path', 'admin/stanford/jumpstart/shortcuts/site-actions/reports%', 'LIKE')
  ->execute()
  ->fetchAll();

// Hide all report menu items from the admin shortcuts menu.
foreach ($mlid as $mitem) {
  $existing_item = menu_link_load($mitem->mlid);
  if(is_array($existing_item)) {
    $item = $existing_item;
    $item['hidden'] = 1;
    $item['customized'] = 1;
    menu_link_save($item);
  }
}
