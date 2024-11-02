#include "cmdscreen/CSTextInput.h"

#include "cmdscreen/term.h"

/*******************************************************************************
 
*******************************************************************************/

static void init_text_input_commands( csTextInputCommands commands[static 1] )
{
   commands->charForward = cs_NoKey;
   commands->charBackward = cs_NoKey;
   commands->wordForward = cs_NoKey;
   commands->wordBackward = cs_NoKey;
   commands->delWordForward = cs_NoKey;
   commands->delWordBackward = cs_NoKey;
   commands->delAfterCursor = cs_NoKey;
   commands->delBeforeCursor = cs_NoKey;
   commands->delCharBackward = cs_BackspaceKey;
   commands->delCharForward = cs_DeleteKey;
   commands->lineStart = cs_NoKey;
   commands->lineEnd = cs_NoKey;
   commands->paste = cs_NoKey;
   commands->acceptSuggestion = cs_NoKey;
   commands->nextSuggestion = cs_NoKey;
   commands->prevSuggestio = cs_NoKey;
}

static void* tail( CSTextInput* input )
{
   return input+1;
}

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

struct csTextInputInternal
{
   cRecorder rec;
   int64_t len;
};

static inline void cleanup( void* instance )
{
   CSTextInput* input = instance;
   if ( input->_->rec.mem != NULL)
   {
      free_recorder_mem_c( &input->_->rec );
   }
}

cMeta const CS_TextInput = {
   .desc = stringify_c_( CSTextInput ),
   .cleanup = &cleanup
};

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

CSTextInput* new_text_input_cs( void )
{
   int64_t size;
   if ( not iadd64_c( sizeof_c_( CSTextInput ),
                      sizeof_c_( csTextInputInternal ), &size ) )
   {
      return NULL;
   }

   CSTextInput* input = new_object_c( size, &CS_TextInput );
   if ( input == NULL )
   {
      return NULL;
   }
   input->_ = tail( input );
   input->_->rec = dyn_recorder_c_( 40 );
   if ( input->_->rec.mem == NULL )
   {
      return release_c( input );
   }
   input->prompt = retain_c( lit_c( "> " ) );
   input->style = base_style_cs( rgb24_c_( 0, 255, 0 ), rgb24_c_( 0, 0, 0 ) );
   init_text_input_commands( &input->commands );

   return input;
}

INTERN_SCREEN_CS_( it, CSTextInput, show_text_input_cs )
uiBox text_input_box_cs( CSTextInput const* input )
{
   must_exist_c_( input );
   int64_t width = input->width;
   if ( width > 0 )
   {
      if ( input->prompt )
      {
         width += string_length_c( input->prompt );
      }
      return sized_ui( size_ui( width, 1 ), screen_it( input ), none_ui() );
   }
   return sized_ui( size_ui( UI_Grow, 1 ), screen_it( input ), none_ui() );
}

bool show_text_input_cs( CSTextInput const* input, uiRect area )
{
   must_exist_c_( input );
   uiPoint cord = top_left_corner_ui( area );
   if ( input->prompt )
   {
      if ( not set_hline_cs( cord, sc_c( input->prompt ), input->style ) )
      {
         return false;
      }
      cord.x += string_length_c( input->prompt );
   }

   return set_hline_cs( cord, text_input_value_cs( input ), input->style );
}

bool update_text_input_cs( CSTextInput* input, CSKeyMsg const* msg )
{
   must_exist_c_( input );
   if ( msg->code == input->commands.delCharBackward )
   {
      
   }
   if ( not record_rune_c( &input->_->rec, msg->rune ) )
   {
      return false;
   }
   input->_->len += 1;
   return true;
}

cChars text_input_value_cs( CSTextInput const* input )
{
   must_exist_c_( input );
   cChars value = recorded_chars_c( &input->_->rec );
   if ( is_empty_c_( value ) and input->placeHolder != NULL )
   {
      return sc_c( input->placeHolder );
   }
   return value;
}