<?php
ctools_include('export');
$rules = ctools_export_load_object('js_injector_rule');
foreach ($rules as $rule) {
  js_injector_rule_save($rule);
}

