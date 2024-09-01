#include "clingo/io/write.h"
#include "clingo/lang/expect.h"
#include "cmdscreen/csBox.h"
#include "cmdscreen/csScreen.h"
#include "cmdscreen/layout/align.h"
#include "cmdscreen/layout/fixed.h"
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

   csBox root = pad_cs(
      padding_cs( 2, 2, 2, 2 ),
      &tealStyle,
      center_cs(
         &maroonStyle,
         fixed_cs(
            size_cs( 5, 5 ),
            &greyStyle,
            center_cs(
               &greyStyle,
               fixed_cs(
                  size_cs( 3, 3 ),
                  &navyStyle,
                  none_cs()
               )
            )
         )
      )
   );

   csLimit limit = fix_limit_cs( 20, 15 );
   cErrorStack* es = &error_stack_c_( 256 );
   layout_box_cs( &root, limit, es );
   globalise_cs( &root );

   csBox exp = exp_box_cs_(
      rect_cs( 0, 0, 20, 15 ),   // padding
      exp_box_cs_(
         rect_cs( 2, 2, 16, 11 ),   // center_cs
         exp_box_cs_(
            rect_cs( 8, 5, 5, 5 ),    // fixed
            exp_box_cs_(
               rect_cs( 8, 5, 5, 5 ), // center_cs
               exp_box_cs_(
                  rect_cs( 9, 6, 3, 3 ), // fixed
                  none_cs()
               )
            )
         )
      )
   );

   dump_box_layout_cs( c_c( "layout_box.ppm" ), &root, es );

   cRecorder* rec = &dyn_recorder_c_( 0 );
   record_box_diff_cs( rec, &exp, &root );
   print_recorded_c( rec );
   free_recorder_mem_c( rec );

   cleanup_cmdscreen_cs();
   return finish_tap_c_();
}