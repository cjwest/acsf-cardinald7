<?php
/**
 * @file
 * Contains the php code argument validator plugin.
 */

/**
 * Provide code to validate whether or not an argument is ok.
 *
 * @ingroup views_argument_validate_plugins
 */
class views_plugin_argument_validate_subsite extends views_plugin_argument_validate {

  /**
   * [option_definition description]
   * @return [type] [description]
   */
  public function option_definition() {
    $options = parent::option_definition();
    return $options;
  }

  /**
   * [options_form description]
   * @param  [type] $form       [description]
   * @param  [type] $form_state [description]
   * @return [type]             [description]
   */
  public function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }

  /**
   * Only let users with PHP block visibility permissions set/modify this.
   */
  public function access() {
    return user_access('administer sws');
  }

  /**
   * [validate_argument description]
   * @param  [type] $argument [description]
   * @return [type]           [description]
   */
  public function validate_argument($argument) {
    // Set up variables to make it easier to reference during the argument.
    $view = &$this->view;
    $handler = &$this->argument;
    $subsite = stanford_subsites_get_active_subsite();

    ob_start();
    if (!$subsite) {
      return 0;
    }

    $index = stanford_subsite_index_get("nid", $subsite->nid);
    if (!isset($index->tid)) {
      return 0;
    }

    ob_end_clean();
    return $index->tid;

  }
}
