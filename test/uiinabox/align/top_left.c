#include "clingo/io/write.h"
#include "clingo/lang/expect.h"
#include "uiinabox/uiinabox.h"

int main( void )
{
   init_tap_c_();
   init_ui();

   cRgb24 const black = rgb24_c_( 0x00, 0x00, 0x00 );
   cRgb24 const white = rgb24_c_( 0xff, 0xff, 0xff );

   uiBox root = fixed_ui(
      size_ui( 7, 7 ),
      &white,
      top_left_ui_(
         fixed_ui(
            size_ui( 3, 3 ),
            &black,
            none_ui()
         )
      )
   );

   uiLimit limit = fix_limit_ui( 20, 15 );
   cErrorStack* es = &error_stack_c_( 256 );
   layout_box_ui( &root, limit, es );
   globalise_ui( &root );

   uiBox exp = exp_cs_(
      rect_ui( 0, 0, 7, 7 ),   // fixed
      exp_cs_(
         rect_ui( 0, 0, 7, 7 ),   // centerx_ui
         exp_cs_(
            rect_ui( 0, 0, 3, 3 ),    // fixed
            none_ui()
         )
      )
   );

   dump_box_layout_ui( c_c( "top_left.ppm" ), &root, es );

   cRecorder* rec = &dyn_recorder_c_( 0 );
   record_box_diff_ui( rec, &exp, &root );
   print_recorded_c( rec );
   free_recorder_mem_c( rec );

   cleanup_ui();
   return finish_tap_c_();
}