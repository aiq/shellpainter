#include "uiinabox/uiinabox.h"

int main( void )
{
   init_tap_c_();
   init_ui();

   cRgb24 const black = rgb24_c_( 0x00, 0x00, 0x00 );
   cRgb24 const red = rgb24_c_( 0xff, 0x00, 0x00 );
   cRgb24 const white = rgb24_c_( 0xff, 0xff, 0xff );

   uiBox root = fixed_ui(
      size_ui( 10, 10 ),
      &white,
      center_ui_(
         sized_ui(
            size_ui( UI_Grow, UI_Grow ),
            &black,
            fixed_ui(
               size_ui( 3, 2 ),
               &red,
               none_ui()
            )
         )
      )
   );

   uiLimit limit = fix_limit_ui( 20, 15 );
   cErrorStack* es = &error_stack_c_( 256 );
   layout_box_ui( &root, limit, es );
   globalise_ui( &root );

   uiBox exp = exp_cs_(
      rect_ui( 0, 0, 10, 10 ),   // fixed
      exp_cs_(
         rect_ui( 0, 0, 10, 10 ),   // centerx_ui
         exp_cs_(
            rect_ui( 0, 0, 10, 10 ),    // sized
            exp_cs_(
               rect_ui( 0, 0, 3, 2 ),    // fixed
               none_ui()
         )
         )
      )
   );

   dump_box_layout_ui( c_c( "sized_grow_grow.ppm" ), &root, es );
   expect_layout_at_ui_( &exp, &root, xyz );

   cleanup_ui();
   return finish_tap_c_();
}