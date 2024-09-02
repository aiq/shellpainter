#include "clingo/io/write.h"
#include "clingo/lang/expect.h"
#include "cmdscreen/csBox.h"
#include "cmdscreen/csScreen.h"
#include "cmdscreen/layout/align.h"
#include "cmdscreen/layout/alignx.h"
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

   csBox root = col_cs(
      0,
      &tealStyle,
      children_cs_(
         fixed_cs(
            size_cs( 10, 4 ),
            &maroonStyle,
            none_cs()
         ),
         fill_cs_( 
            2,
            center_cs_(
               fixed_cs(
                  size_cs( 4, 2 ),
                  &navyStyle,
                  none_cs()
               )
            )
         ),
         right_cs_(
            fixed_cs(
               size_cs( 3, 3 ),
               &maroonStyle,
               none_cs()
            )
         ),
         fill_cs_(
            5,
            fixed_cs(
               size_cs( 1, 1 ),
               &navyStyle,
               none_cs()
            )
         )
      )
   );

   csLimit limit = fix_limit_cs( 12, 24 );
   cErrorStack* es = &error_stack_c_( 256 );
   layout_box_cs( &root, limit, es );
   globalise_cs( &root );
   dump_box_layout_cs( c_c( "layout_col.ppm" ), &root, es );

   csBox exp = exp_cs_(
      rect_cs( 0, 0, 12, 24 ),  // col
      exp_cs_(  // fixed
         rect_cs( 0, 0, 10, 4 ),
         none_cs()
      ),
      exp_cs_(  // fill
         rect_cs( 0, 4, 12, 4 ),
         exp_cs_(   // center
            rect_cs( 0, 4, 12, 4 ),
            exp_cs_(    // fixed
               rect_cs( 4, 5, 4, 2 ),
               none_cs()
            )
         )
      ),
      exp_cs_(  // right
         rect_cs( 0, 8, 12, 3 ),
         exp_cs_(   // fixed
            rect_cs( 9, 8, 3, 3 ),
            none_cs()
         )
      ),
      exp_cs_(  // fill
         rect_cs( 0, 11, 12, 13 ),
         exp_cs_(   // fixed
            rect_cs( 0, 11, 1, 1 ),
            none_cs()
         )
      )
   );

   cRecorder* rec = &dyn_recorder_c_( 0 );
   record_box_diff_cs( rec, &exp, &root );
   print_recorded_c( rec );
   free_recorder_mem_c( rec );

   cleanup_cmdscreen_cs();
   return finish_tap_c_();
}