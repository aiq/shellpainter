#include "clingo/lang/expect.h"
#include "clingo/lang/slice.h"
#include "cmdscreen/csSize.h"

TEMP_SLICE_C_(
   test,
   {
      ui_Axis axis;
      int16_t main;
      int16_t cross;
      csSize exp;
   }
)
#define t_( ... ) ((test){__VA_ARGS__})

int main( void )
{
   init_tap_c_();

   testSlice tests = slice_c_( test,
      t_( ui_Horizontal, 640, 480, size_cs( 640, 480 ) ),
      t_( ui_Vertical, 640, 480, size_cs( 480, 640 ) )
   );

   for_each_c_( i, test const*, t, tests )
   {
      csSize res = axis_size_cs( t->axis, t->main, t->cross );

      expect_block_c_( i, eq_size_cs( res, t->exp ) )
      {
         tap_exp_line_c_( "{t}", size_tape_cs_( t->exp ) );
         tap_got_line_c_( "{t}", size_tape_cs_( res ) );
      }
   }

   return finish_tap_c_();
}
