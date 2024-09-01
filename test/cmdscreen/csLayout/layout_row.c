#include "clingo/io/write.h"
#include "clingo/lang/expect.h"
#include "cmdscreen/csBox.h"
#include "cmdscreen/csScreen.h"
#include "cmdscreen/layout/align.h"
#include "cmdscreen/layout/aligny.h"
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
      1,
      &tealStyle,
      children_cs_(
         top_cs_(
            fixed_cs( 
               size_cs( 3, 3 ),
               &maroonStyle,
               none_cs()
            )
         ),
         fill_cs_(
            1,
            bottom_right_cs_( 
               fixed_cs(
                  size_cs( 1, 1 ),
                  &greyStyle,
                  none_cs()
               )
            )
         ),
         centery_cs_(
            fixed_cs( 
               size_cs( 5, 5 ),
               &maroonStyle,
               none_cs()
            )
         ),
         fill_cs_(
            1,
            bottom_right_cs_( 
               fixed_cs(
                  size_cs( 1, 1 ),
                  &greyStyle,
                  none_cs()
               )
            )
         ),
         bottom_cs_(
            fixed_cs(
               size_cs( 1, 1 ),
               &maroonStyle,
               none_cs()
            )
         ),
         fill_cs_(
            2,
            fixed_cs(
               size_cs( 1, 1 ),
               &greyStyle,
               none_cs()
            )
         ),
         fixed_cs(
            size_cs( 4, 2 ),
            &maroonStyle,
            none_cs()
         )
      )
   );

   csLimit limit = fix_limit_cs( 24, 12 );
   cErrorStack* es = &error_stack_c_( 256 );
   layout_box_cs( &root, limit, es );
   globalise_cs( &root );
   dump_box_layout_cs( c_c( "layout_row.ppm" ), &root, es );
/*
   csBox exp = layouted_box_cs_(
      rect_cs( 0, 0, 20, 15 ),   // padding
      layouted_box_cs_(
         rect_cs( 2, 2, 16, 11 ),   // align
         layouted_box_cs_(
            rect_cs( 8, 5, 5, 5 ),    // fixed
            layouted_box_cs_(
               rect_cs( 8, 5, 5, 5 ), // align
               layouted_box_cs_(
                  rect_cs( 9, 6, 3, 3 ), // fixed
                  none_cs_()
               )
            )
         )
      )
   );

   cRecorder* rec = &dyn_recorder_c_( 0 );
   record_box_diff_cs( rec, cs_CheckRect, &exp, &root );
   print_recorded_c( rec );
   free_recorder_mem_c( rec );
*/
   cleanup_cmdscreen_cs();
   return finish_tap_c_();
}