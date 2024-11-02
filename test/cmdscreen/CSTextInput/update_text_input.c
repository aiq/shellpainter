#include "clingo/clingo.h"
#include "cmdscreen/cmdscreen.h"

#define expect_( Input, Exp )                                                  \
{                                                                              \
   cChars val = text_input_value_cs( Input );                                  \
   expect_block_at_c_( chars_is_c( val, (Exp) ) )                              \
   {                                                                           \
      tap_exp_line_c_( "{s}", (Exp) );                                         \
      tap_got_line_c_( "{cs}", val );                                          \
   }                                                                           \
}


int main( void )
{
   init_tap_c_();

   CSTextInput* input = new_text_input_cs();
   input->placeHolder = retain_c( lit_c( "just for a moment" ) );
   CSKeyMsg* msg = let_key_msg_cs_();

   expect_( input, "just for a moment" ); 

   msg->rune = rune_c( "h" );
   require_c_( update_text_input_cs( input, msg ) );
   expect_( input, "h" );

   release_c( input );

   return finish_tap_c_();
}
