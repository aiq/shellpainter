#include "clingo/io/write.h"
#include "clingo/lang/expect.h"
#include "cmdscreen/csScreen.h"
#include "uiinabox/uiinabox.h"

#include "distinct_styles.h"

int main( void )
{
   init_tap_c_();
   init_ui();

   cRgb24 const tealStyle = DISTINCT_TEAL_;
   cRgb24 const maroonStyle = DISTINCT_MAROON_;
   cRgb24 const greyStyle = DISTINCT_GREY_;
   cRgb24 const navyStyle = DISTINCT_NAVY_;

   uiBox root = row_ui(
      0,
      &tealStyle,
      boxes_cs_(
         top_ui_(
            fixed_ui( 
               size_ui( 3, 3 ),
               &maroonStyle,
               none_ui()
            )
         ),
         fill_ui_(
            1,
            bottom_right_ui_( 
               fixed_ui(
                  size_ui( 1, 1 ),
                  &greyStyle,
                  none_ui()
               )
            )
         ),
         centery_ui_(
            fixed_ui( 
               size_ui( 5, 5 ),
               &maroonStyle,
               none_ui()
            )
         ),
         fill_ui_(
            1,
            bottom_center_ui_( 
               fixed_ui(
                  size_ui( 1, 1 ),
                  &greyStyle,
                  none_ui()
               )
            )
         ),
         bottom_ui_(
            fixed_ui(
               size_ui( 1, 1 ),
               &maroonStyle,
               none_ui()
            )
         ),
         fill_ui_(
            2,
            fixed_ui(
               size_ui( 1, 1 ),
               &greyStyle,
               none_ui()
            )
         ),
         fixed_ui(
            size_ui( 4, 2 ),
            &maroonStyle,
            none_ui()
         )
      )
   );

   uiLimit limit = fix_limit_ui( 24, 12 );
   cErrorStack* es = &error_stack_c_( 256 );
   layout_box_ui( &root, limit, es );
   globalise_ui( &root );
   dump_box_layout_ui( c_c( "layout_row.ppm" ), &root, es );

   uiBox exp = exp_cs_(
      rect_ui( 0, 0, 24, 12 ),   // row
      exp_cs_(  // top
         rect_ui( 0, 0, 3, 12 ),
         exp_cs_(   // fixed
            rect_ui( 0, 0, 3, 3 ),
            none_ui()
         )
      ),
      exp_cs_(  // fill
         rect_ui( 3, 0, 2, 12 ),
         exp_cs_(   // bottom right
            rect_ui( 3, 0, 2, 12 ),
            exp_cs_(    // fixed
                rect_ui( 4, 11, 1, 1 ),
                none_ui()
            )
         )
      ),
      exp_cs_(  // center
         rect_ui( 5, 0, 5, 12 ),
         exp_cs_(   // fixed
            rect_ui( 5, 4, 5, 5 ),
            none_ui()
         )
      ),
      exp_cs_(  // fill
         rect_ui( 10, 0, 3, 12 ),
         exp_cs_(   // bottom center
            rect_ui( 10, 0, 3, 12 ),
            exp_cs_(    // fixed
                rect_ui( 11, 11, 1, 1 ),
                none_ui()
            )
         )
      ),
      exp_cs_(  // bottom
         rect_ui( 13, 0, 1, 12 ),
         exp_cs_(   // fixed
            rect_ui( 13, 11, 1, 1 ),
            none_ui()
         )
      ),
      exp_cs_(  // fill
         rect_ui( 14, 0, 6, 1 ),
         exp_cs_(    // fixed
            rect_ui( 14, 0, 1, 1 ),
            none_ui()
         )
      ),
      exp_cs_(  // fixed
         rect_ui( 20, 0, 4, 2 ),
         none_ui()
      )
   );

   expect_layout_at_ui_( &exp, &root, xyz );

   cleanup_ui();
   return finish_tap_c_();
}