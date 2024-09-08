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
      1,
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
      rect_ui( 0, 0, 4, 13 ),   // row
      exp_cs_(
         rect_ui( 0, 0, 3, 3 ),   // fixed
         none_ui()
      ),
      exp_cs_(
         rect_ui( 0, 4, 1, 1 ),   // fixed
         none_ui()
      ),
      exp_cs_(
         rect_ui( 0, 6, 4, 4 ),   // fixed
         none_ui()
      ),
      exp_cs_(
         rect_ui( 0, 11, 2, 2 ),   // fixed
         none_ui()
      )
   );

   dump_box_layout_ui( c_c( "col_space.ppm" ), &root, es );
   expect_layout_at_ui_( &exp, &root, xyz );

   cleanup_ui();
   return finish_tap_c_();
}