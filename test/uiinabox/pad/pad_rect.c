#include "clingo/lang/expect.h"
#include "clingo/lang/slice.h"
#include "uiinabox/pad.h"

TEMP_SLICE_C_(
   test,
   {
      uiRect rect;
      uiPadding pad;
      uiRect exp;
   }
)
#define t_( ... ) ((test){__VA_ARGS__})

int main( void )
{
   init_tap_c_();

   testSlice tests = slice_c_( test,
      t_( rect_ui( 0, 0, 20, 20 ), padding_ui( 1, 1, 1, 1 ), rect_ui( 1, 1, 19, 19 ) ),
      t_( rect_ui( 0, 0, 300, 85 ), padding_ui( 5, 5, 5, 5 ), rect_ui( 5, 5, 295, 80 ) )
   );

   for_each_c_( i, test const*, t, tests )
   {
      uiRect res = pad_rect_ui( t->rect, t->pad );

      expect_block_c_( i, eq_rect_ui( res, t->exp ) )
      {
         tap_exp_line_c_( "{t}", rect_tape_ui_( t->exp ) );
         tap_got_line_c_( "{t}", rect_tape_ui_( res ) );
      }
   }

   return finish_tap_c_();
}
