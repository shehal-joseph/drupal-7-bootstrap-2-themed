/*!
 * ceazine scrips
 */
(function($) {
    Drupal.behaviors.ceazine = {
        attach: function(context, settings) {
           $(document).ready(function(){
                $(function() {
                  if ( typeof(ceaZineWidth) == 'undefined' ){
                    ceaZineWidth = 200;
                    ceaZineHeight = 400;
                  }
                  $('.mybook').booklet({
                      closed: true,
                      autoCenter: false,
                      covers: true,
                      width: ceaZineWidth,
                      height: ceaZineHeight,
                      arrows: false,
                      manual: false,
                      overlays: true,
                      shadows: true,
                      hovers: false,
                      pageNumbers: false,
                      menu: '#custom-menu',
                      pageSelector: true,
                      change: function(event, data){
                        $('body').append('<embed src="'+ceaZineSound+'" autostart="true" hidden="true" loop="false">');
                      } 
                    });
                });
                $(".inlineviewer").colorbox({inline:true, width:ceaZineWidth+100}); 
           });
        }
    };
})(jQuery);
