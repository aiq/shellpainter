#include "uiinabox/uiinabox.h"

TEMP_SLICE_C_(
   test,
   {
      uiLimit limit;
      ui_Axis axis;
      int16_t val;
      int16_t exp;
   }
)
#define t_( ... ) ((test){__VA_ARGS__})

int main( void )
{
   init_tap_c_();

   testSlice tests = slice_c_( test,
      t_( fix_limit_ui( 1280, 720 ), ui_Horizontal, UI_Infinity, 720 ),
      t_( fix_limit_ui( 1280, 720 ), ui_Vertical, UI_Infinity, 1280 )
   );

   for_each_c_( i, test const*, t, tests )
   {
      int16_t res = cross_axis_ui( t->limit, t->axis, t->val );

      expect_block_c_( i, res == t->exp )
      {
         tap_exp_line_c_( "{i16}", t->exp );
         tap_got_line_c_( "{i16}", res );
      }
   }

   return finish_tap_c_();
}
