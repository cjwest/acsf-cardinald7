<?php
/**
 * @file
 * stanford_jumpstart_wysiwyg.features.wysiwyg.inc
 */

/**
 * Implements hook_wysiwyg_default_profiles().
 */
function stanford_jumpstart_wysiwyg_wysiwyg_default_profiles() {
  $profiles = array();

  // Exported profile: content_editor_text_format.
  $profiles['content_editor_text_format'] = array(
    'format' => 'content_editor_text_format',
    'editor' => 'ckeditor',
    'settings' => array(
      'buttons' => array(
        'default' => array(
          'Bold' => 1,
          'Italic' => 1,
          'BulletedList' => 1,
          'NumberedList' => 1,
          'Outdent' => 1,
          'Indent' => 1,
          'Undo' => 1,
          'Redo' => 1,
          'Link' => 1,
          'Unlink' => 1,
          'Anchor' => 1,
          'HorizontalRule' => 1,
          'Cut' => 1,
          'Copy' => 1,
          'PasteFromWord' => 1,
          'RemoveFormat' => 1,
          'SpecialChar' => 1,
          'Format' => 1,
          'Styles' => 1,
          'Table' => 1,
          'SpellChecker' => 1,
        ),
      ),
      'theme' => 'advanced',
      'language' => 'en',
      'toolbarLocation' => 'top',
      'resize_enabled' => 1,
      'default_toolbar_grouping' => 0,
      'simple_source_formatting' => 1,
      'css_setting' => 'easy',
      'css_theme' => 'stanford_framework',
      'css_path' => '',
      'stylesSet' => 'Button Link=a.btn
More Link=a.more-link
Descriptor=p.descriptor
Summary Paragraph=p.summary
Image Right=p.float-right
Image Left=p.float-left
Infotext=p.infotext
Caption=p.caption
Credits=p.credits
Highlight Block Right=p.highlight-block-right
Highlight Block Left=p.highlight-block-left
Stack Table=table.tablesaw-stack
Swipe Table=table.tablesaw-swipe
Column Toggle Table=table.tablesaw-column-toggle
Sticky Swipe Table=table.tablesaw-swipe.sticky-enabled
Sticky Column Toggle Table=table.tablesaw-column-toggle.sticky-enabled
Persist Header=th.tablesaw-persist',
      'block_formats' => 'p,h2,h3,h4',
      'forcePasteAsPlainText' => 0,
      'pasteFromWordNumberedHeadingToList' => 0,
      'pasteFromWordPromptCleanup' => 0,
      'pasteFromWordRemoveFontStyles' => 1,
      'pasteFromWordRemoveStyles' => 1,
    ),
    'preferences' => array(
      'default' => 1,
      'user_choose' => 0,
      'show_toggle' => 1,
      'add_to_summaries' => 0,
      'version' => '3.6.6.1.7696',
    ),
    'name' => 'formatcontent_editor_text_format',
    'rdf_mapping' => array(),
  );

  return $profiles;
}
