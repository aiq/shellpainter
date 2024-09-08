#include "uiinabox/uiinabox.h"

TEMP_SLICE_C_(
   test,
   {
      ui_Axis axis;
      int16_t main;
      int16_t cross;
      uiSize exp;
   }
)
#define t_( ... ) ((test){__VA_ARGS__})

int main( void )
{
   init_tap_c_();

   testSlice tests = slice_c_( test,
      t_( ui_Horizontal, 640, 480, size_ui( 640, 480 ) ),
      t_( ui_Vertical, 640, 480, size_ui( 480, 640 ) )
   );

   for_each_c_( i, test const*, t, tests )
   {
      uiSize res = axis_size_ui( t->axis, t->main, t->cross );

      expect_block_c_( i, eq_size_ui( res, t->exp ) )
      {
         tap_exp_line_c_( "{t}", size_tape_ui_( t->exp ) );
         tap_got_line_c_( "{t}", size_tape_ui_( res ) );
      }
   }

   return finish_tap_c_();
}
