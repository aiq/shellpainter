#include "clingo/io/write.h"
#include "clingo/lang/expect.h"
#include "uiinabox/uiinabox.h"

int main( void )
{
   init_tap_c_();
   init_ui();

   cRgb24 const black = rgb24_c_( 0x00, 0x00, 0x00 );
   cRgb24 const maroon = rgb24_c_( 0x80, 0x00, 0x00 );
   cRgb24 const navy = rgb24_c_( 0x00, 0x00, 0x80 );
   cRgb24 const teal = rgb24_c_( 0x00, 0x80, 0x80 );
   cRgb24 const white = rgb24_c_( 0xff, 0xff, 0xff );
   cRgb24 const yellow = rgb24_c_( 0xff, 0xff, 0x19 );

   uiBox root = col_ui(
      0,
      &black,
      boxes_cs_(
         fixed_ui(
            size_ui( 3, 3 ),
            &maroon,
            none_ui()
         ),
         fixed_ui(
            size_ui( 1, 1 ),
            &navy,
            none_ui()
         ),
         fixed_ui(
            size_ui( 4, 4 ),
            &teal,
            none_ui()
         ),
         fixed_ui(
            size_ui( 2, 2 ),
            &yellow,
            none_ui()
         )
      )
   );

   uiLimit limit = fix_limit_ui( 10, 20 );
   cErrorStack* es = &error_stack_c_( 256 );
   layout_box_ui( &root, limit, es );
   globalise_ui( &root );

   uiBox exp = exp_cs_(
      rect_ui( 0, 0, 4, 10 ),   // row
      exp_cs_(
         rect_ui( 0, 0, 3, 3 ),   // fixed
         none_ui()
      ),
      exp_cs_(
         rect_ui( 0, 3, 1, 1 ),   // fixed
         none_ui()
      ),
      exp_cs_(
         rect_ui( 0, 4, 4, 4 ),   // fixed
         none_ui()
      ),
      exp_cs_(
         rect_ui( 0, 8, 2, 2 ),   // fixed
         none_ui()
      )
   );

   dump_box_layout_ui( c_c( "col.ppm" ), &root, es );

   cRecorder* rec = &dyn_recorder_c_( 0 );
   record_box_diff_ui( rec, &exp, &root );
   print_recorded_c( rec );
   free_recorder_mem_c( rec );

   cleanup_ui();
   return finish_tap_c_();
}