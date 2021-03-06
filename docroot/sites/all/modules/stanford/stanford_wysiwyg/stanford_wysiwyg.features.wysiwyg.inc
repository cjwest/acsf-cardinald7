<?php
/**
 * @file
 * stanford_wysiwyg.features.wysiwyg.inc
 */

/**
 * Implements hook_wysiwyg_default_profiles().
 */
function stanford_wysiwyg_wysiwyg_default_profiles() {
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
          'Image' => 1,
          'Superscript' => 1,
          'Subscript' => 1,
          'Blockquote' => 1,
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
          'CreateDiv' => 1,
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
      'stylesSet' => 'Abbreviation for All-Caps=abbr.initialism
Button Link=a.button
Edit Link=a.edit-link
More Link=a.more-link
White Icon=i.icon-white
Callout=p.callout
Caption=p.caption
Error Text=p.text-error
Informational Text=p.text-info
Lead=p.lead
Muted Text=p.muted
Pullquote Credits=p.credits
Pullquote Large=p.pullquote-large
Pullquote Small=p.pullquote
Success Text=p.text-success
Summary Text=p.summary
Warning Text=p.text-warning
Bracket=blockquote.bracket
Callout=blockquote.callout
Pull Right Blockquote=blockquote.pull-right
Topline=blockquote.topline
Jump To Links=ul.jump-to
Unstyled Ordered List=ol.unstyled
Unstyled Unordered List=ul.unstyled
Scrollable Code=pre.pre-scrollable
Table=table.table
Table Striped=table.table-striped
Table Bordered=table.table-bordered
Table Condensed=table.table-condensed
Table Hover=table.table-hover
Table Row Success=tr.success
Table Row Error=tr.error
Table Row Warning=tr.warning
Table Row Information=tr.info
Alert=div.alert
Error Alert=div.alert-error
Success Alert=div.alert-success
Informational Alert=div.alert-info
Well=div.well',
      'block_formats' => 'p,h2,h3,h4,h5,h6,pre',
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
