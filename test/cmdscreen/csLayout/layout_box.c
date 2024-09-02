#include "clingo/io/write.h"
#include "clingo/lang/expect.h"
#include "uiinabox/uiBox.h"
#include "cmdscreen/csScreen.h"
#include "uiinabox/box/box.h"

#include "distinct_styles.h"

int main( void )
{
   init_tap_c_();
   cmdscreen_cs();

   csStyle const tealStyle = TEAL_;
   csStyle const maroonStyle = MAROON_;
   csStyle const greyStyle = GREY_;
   csStyle const navyStyle = NAVY_;

   uiBox root = pad_ui(
      padding_ui( 2, 2, 2, 2 ),
      &tealStyle,
      center_ui(
         &maroonStyle,
         fixed_ui(
            size_ui( 5, 5 ),
            &greyStyle,
            center_ui(
               &greyStyle,
               fixed_ui(
                  size_ui( 3, 3 ),
                  &navyStyle,
                  none_ui()
               )
            )
         )
      )
   );

   uiLimit limit = fix_limit_ui( 20, 15 );
   cErrorStack* es = &error_stack_c_( 256 );
   layout_box_ui( &root, limit, es );
   globalise_ui( &root );

   uiBox exp = exp_cs_(
      rect_ui( 0, 0, 20, 15 ),   // padding
      exp_cs_(
         rect_ui( 2, 2, 16, 11 ),   // center_ui
         exp_cs_(
            rect_ui( 8, 5, 5, 5 ),    // fixed
            exp_cs_(
               rect_ui( 8, 5, 5, 5 ), // center_ui
               exp_cs_(
                  rect_ui( 9, 6, 3, 3 ), // fixed
                  none_ui()
               )
            )
         )
      )
   );

   dump_box_layout_ui( c_c( "layout_box.ppm" ), &root, es );

   cRecorder* rec = &dyn_recorder_c_( 0 );
   record_box_diff_ui( rec, &exp, &root );
   print_recorded_c( rec );
   free_recorder_mem_c( rec );

   cleanup_cmdscreen_cs();
   return finish_tap_c_();
}