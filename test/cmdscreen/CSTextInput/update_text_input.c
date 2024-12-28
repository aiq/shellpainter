#include "clingo/clingo.h"
#include "cmdscreen/cmdscreen.h"

#define expect_( Input, ExpPos, ExpVal )                                       \
{                                                                              \
   cRecorder* rec = &recorder_c_( 1024 );                                      \
   get_text_input_value_cs( Input, rec );                                      \
   cChars val = recorded_chars_c( rec );                                       \
   expect_block_at_c_( chars_is_c( val, (ExpVal) ) )                           \
   {                                                                           \
      tap_exp_line_c_( "{s}", (ExpVal) );                                      \
      tap_got_line_c_( "{cs}", val );                                          \
   }                                                                           \
   int64_t pos = text_input_pos_cs( Input );                                   \
   expect_block_at_c_( pos == (ExpPos) )                                       \
   {                                                                           \
      tap_exp_line_c_( "{i64}", (ExpPos) );                                    \
      tap_got_line_c_( "{i64}", pos );                                         \
   }                                                                           \
}

static inline CSKeyMsg* with_rune_msg( CSKeyMsg* msg, char const cstr[static 1] )
{
   msg->cmd = cs_NoCmd;
   msg->rune = rune_c( cstr );
   return msg;
}

static inline CSKeyMsg* with_cmd_msg( CSKeyMsg* msg, uint16_t code )
{
   msg->cmd = code;
   return msg;
}

int main( void )
{
   init_tap_c_();

   CSTextInput* input = new_text_input_cs();
   input->placeHolder = retain_c( lit_c( "just for a moment" ) );
   CSKeyMsg* msg = let_key_msg_cs_();

   expect_( input, 0, "just for a moment" ); 

   require_c_( update_text_input_cs( input, with_rune_msg( msg, "h") ) );
   expect_( input, 1, "h" );

   require_c_( update_text_input_cs( input, with_rune_msg( msg, "e") ) );
   require_c_( update_text_input_cs( input, with_rune_msg( msg, "l") ) );
   require_c_( update_text_input_cs( input, with_rune_msg( msg, "l") ) );
   require_c_( update_text_input_cs( input, with_rune_msg( msg, "o") ) );
   expect_( input, 5, "hello" );

   require_c_( update_text_input_cs( input, with_cmd_msg( msg, input->commands.moveBackward ) ) );
   require_c_( update_text_input_cs( input, with_cmd_msg( msg, input->commands.moveBackward ) ) );
   require_c_( update_text_input_cs( input, with_cmd_msg( msg, input->commands.moveBackward ) ) );
   expect_( input, 2, "hello" );

   require_c_( update_text_input_cs( input, with_cmd_msg( msg, input->commands.deleteBackward ) ) );
   expect_( input, 1, "hllo" );

   require_c_( update_text_input_cs( input, with_cmd_msg( msg, input->commands.moveToStart ) ) );
   expect_( input, 0, "hllo" );

   require_c_( update_text_input_cs( input, with_cmd_msg( msg, input->commands.deleteForward ) ) );
   expect_( input, 0, "llo" );

   require_c_( update_text_input_cs( input, with_cmd_msg( msg, input->commands.deleteBackward ) ) );
   expect_( input, 0, "llo" );

   release_c( input );

   return finish_tap_c_();
}
