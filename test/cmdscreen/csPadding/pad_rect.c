#include "clingo/lang/expect.h"
#include "clingo/lang/slice.h"
#include "cmdscreen/csPadding.h"

TEMP_SLICE_C_(
   test,
   {
      csRect rect;
      csPadding pad;
      csRect exp;
   }
)
#define t_( ... ) ((test){__VA_ARGS__})

int main( void )
{
   init_tap_c_();

   testSlice tests = slice_c_( test,
      t_( rect_cs( 0, 0, 20, 20 ), padding_cs( 1, 1, 1, 1 ), rect_cs( 1, 1, 19, 19 ) ),
      t_( rect_cs( 0, 0, 300, 85 ), padding_cs( 5, 5, 5, 5 ), rect_cs( 5, 5, 295, 80 ) )
   );

   for_each_c_( i, test const*, t, tests )
   {
      csRect res = pad_rect_cs( t->rect, t->pad );

      expect_block_c_( i, eq_rect_cs( res, t->exp ) )
      {
         tap_exp_line_c_( "{t}", rect_tape_cs_( t->exp ) );
         tap_got_line_c_( "{t}", rect_tape_cs_( res ) );
      }
   }

   return finish_tap_c_();
}
