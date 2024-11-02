#include "uiinabox/uiinabox.h"

TEMP_SLICE_C_(
   test,
   {
      uiRect a;
      uiRect b;
      uiRect exp;
   }
)
#define t_( ... ) ((test){__VA_ARGS__})

int main( void )
{
   init_tap_c_();

   testSlice tests = slice_c_( test,
      t_( 
         .a = rect_ui( 10, 10, 20, 20 ),
         .b = rect_ui( 20, 20, 50, 50 ),
         .exp = rect_ui( 20, 20, 10, 10 )
      ),
      t_( 
         .a = rect_ui( 10, 10, 20, 20 ),
         .b = rect_ui( 50, 50, 50, 50 ),
         .exp = null_rect_ui()
      )
   );

   for_each_c_( i, test const*, t, tests )
   {
      uiRect res = intersection_ui( t->a, t->b );

      expect_block_c_( i, eq_rect_ui( t->exp, res ) )
      {
         tap_line_c_( "input a", "{t}", rect_tape_ui( &t->a ) );
         tap_line_c_( "input b", "{t}", rect_tape_ui( &t->b ) );
         tap_exp_line_c_( "{t}", rect_tape_ui( &t->exp ) );
         tap_got_line_c_( "{t}", rect_tape_ui( &res ) );
      }
   }

   return finish_tap_c_();
}
