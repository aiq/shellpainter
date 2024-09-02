#include "clingo/io/write.h"
#include "clingo/lang/expect.h"
#include "cmdscreen/csBox.h"
#include "cmdscreen/csScreen.h"
#include "cmdscreen/layout/align.h"
#include "cmdscreen/layout/aligny.h"
#include "cmdscreen/layout/exp.h"
#include "cmdscreen/layout/fill.h"
#include "cmdscreen/layout/fixed.h"
#include "cmdscreen/layout/line.h"
#include "cmdscreen/layout/none.h"
#include "cmdscreen/layout/pad.h"

#include "distinct_styles.h"

int main( void )
{
   init_tap_c_();
   cmdscreen_cs();

   csStyle const tealStyle = TEAL_;
   csStyle const maroonStyle = MAROON_;
   csStyle const greyStyle = GREY_;
   csStyle const navyStyle = NAVY_;

   csBox root = row_cs(
      0,
      &tealStyle,
      boxes_cs_(
         top_cs_(
            fixed_cs( 
               size_ui( 3, 3 ),
               &maroonStyle,
               none_cs()
            )
         ),
         fill_cs_(
            1,
            bottom_right_cs_( 
               fixed_cs(
                  size_ui( 1, 1 ),
                  &greyStyle,
                  none_cs()
               )
            )
         ),
         centery_cs_(
            fixed_cs( 
               size_ui( 5, 5 ),
               &maroonStyle,
               none_cs()
            )
         ),
         fill_cs_(
            1,
            bottom_center_cs_( 
               fixed_cs(
                  size_ui( 1, 1 ),
                  &greyStyle,
                  none_cs()
               )
            )
         ),
         bottom_cs_(
            fixed_cs(
               size_ui( 1, 1 ),
               &maroonStyle,
               none_cs()
            )
         ),
         fill_cs_(
            2,
            fixed_cs(
               size_ui( 1, 1 ),
               &greyStyle,
               none_cs()
            )
         ),
         fixed_cs(
            size_ui( 4, 2 ),
            &maroonStyle,
            none_cs()
         )
      )
   );

   uiLimit limit = fix_limit_ui( 24, 12 );
   cErrorStack* es = &error_stack_c_( 256 );
   layout_box_cs( &root, limit, es );
   globalise_cs( &root );
   dump_box_layout_cs( c_c( "layout_row.ppm" ), &root, es );

   csBox exp = exp_cs_(
      rect_ui( 0, 0, 24, 12 ),   // row
      exp_cs_(  // top
         rect_ui( 0, 0, 3, 12 ),
         exp_cs_(   // fixed
            rect_ui( 0, 0, 3, 3 ),
            none_cs()
         )
      ),
      exp_cs_(  // fill
         rect_ui( 3, 0, 2, 12 ),
         exp_cs_(   // bottom right
            rect_ui( 3, 0, 2, 12 ),
            exp_cs_(    // fixed
                rect_ui( 4, 11, 1, 1 ),
                none_cs()
            )
         )
      ),
      exp_cs_(  // center
         rect_ui( 5, 0, 3, 12 ),
         exp_cs_(   // fixed
            rect_ui( 5, 4, 5, 5 ),
            none_cs()
         )
      ),
      exp_cs_(  // fill
         rect_ui( 10, 0, 3, 12 ),
         exp_cs_(   // bottom center
            rect_ui( 10, 0, 3, 12 ),
            exp_cs_(    // fixed
                rect_ui( 11, 11, 1, 1 ),
                none_cs()
            )
         )
      ),
      exp_cs_(  // bottom
         rect_ui( 13, 0, 1, 12 ),
         exp_cs_(   // fixed
            rect_ui( 13, 11, 1, 1 ),
            none_cs()
         )
      ),
      exp_cs_(  // fill
         rect_ui( 14, 0, 6, 12 ),
         exp_cs_(   // top left
            rect_ui( 14, 0, 6, 12 ),
            exp_cs_(    // fixed
                rect_ui( 14, 0, 1, 1 ),
                none_cs()
            )
         )
      ),
      exp_cs_(  // fixed
         rect_ui( 20, 0, 4, 2 ),
         none_cs()
      )
   );

   cRecorder* rec = &dyn_recorder_c_( 0 );
   record_box_diff_cs( rec, &exp, &root );
   print_recorded_c( rec );
   free_recorder_mem_c( rec );

   cleanup_cmdscreen_cs();
   return finish_tap_c_();
}