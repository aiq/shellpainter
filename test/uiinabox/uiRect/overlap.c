#include "uiinabox/uiinabox.h"

TEMP_SLICE_C_(
   test,
   {
      uiRect a;
      uiRect b;
      bool exp;
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
         .exp = true
      ),
      t_( 
         .a = rect_ui( 10, 10, 20, 20 ),
         .b = rect_ui( 50, 50, 50, 50 ),
         .exp = false
      )
   );

   for_each_c_( i, test const*, t, tests )
   {
      bool res = overlap_ui( t->a, t->b );

      expect_block_c_( i, res == t->exp )
      {
         tap_line_c_( "input a", "{t}", rect_tape_ui( &t->a ) );
         tap_line_c_( "input b", "{t}", rect_tape_ui( &t->b ) );
         tap_exp_line_c_( "{bool}", t->exp );
         tap_got_line_c_( "{bool}", res );
      }
   }

   return finish_tap_c_();
}
