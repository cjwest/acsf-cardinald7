(function($) {

  /**
   * Add syntext highlighter for textarea.
   */
  Drupal.behaviors.cssInjectorHighlighter = {
    attach: function(context, settings) {
      $('body', context).addClass('has-js');
      var editor = ace.edit("editor");
      editor.getSession().setUseWorker(false);
      editor.setTheme("ace/theme/chrome");
      editor.getSession().setMode("ace/mode/css");

      editor.getSession().on('change', function(e) {
        setTextareaValue();
      });

      var setTextareaValue = function() {
        $('#edit-css-text').val(editor.getValue());
      }

      $('.disable-ace').click(function() {
        var $this = $(this);
        $this.toggleClass('ace-disabled');
        $text = $this.text() == 'Disable syntax highlighter' ? 'Enable syntax highlighter' : 'Disable syntax highlighter';
        $this.text($text);
        $('.form-item-css-text .form-textarea-wrapper, .ace-editor').toggle();
        if (!$this.hasClass('ace-disabled')) {
          editor.setValue($("#edit-css-text").val());
        }
      });

      // And once more for good luck.
      if ($("#edit-css-text", context).length) {
        editor.setValue($("#edit-css-text", context).val());
      }
    }
  }

})(jQuery)
