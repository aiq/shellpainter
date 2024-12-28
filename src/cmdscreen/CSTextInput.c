#include "cmdscreen/CSTextInput.h"

#include "cmdscreen/colors.h"
#include "cmdscreen/term.h"

/*******************************************************************************
 
*******************************************************************************/

static void init_text_input_commands( csTextInputCmds cmds[static 1] )
{
   cmds->deleteBackward = cs_BackspaceKey;
   cmds->deleteForward = cs_DeleteKey;
   cmds->moveBackward = cs_LeftKey;
   cmds->moveForward = cs_RightKey;
   cmds->moveToStart = cs_UpKey;
   cmds->moveToEnd = cs_DownKey;
}

static void* tail( CSTextInput* input )
{
   return input+1;
}

STATIC_VAL_PILE_IMPL_C_(
   __attribute__((unused)),   // Attr
   cRune,                     // Type
   csRunePile,                // PileType
   rune_cs                    // FuncSuffix
)

static REMOVE_C_(
   remove_rune, // FuncName
   csRunePile,  // SliceType
   cRune        // Value
)

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

struct csTextInputInternal
{
   csRunePile pile;
   int16_t pos;
   int16_t watermark;
};

static inline void cleanup( void* instance )
{
   CSTextInput* input = instance;
   if ( input->_->pile.v != NULL )
   {
      free( input->_->pile.v );
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
   if ( not alloc_pile_of_rune_cs( &input->_->pile, 40 ) )
   {
      return release_c( input );
   }
   input->_->pos = 0;
   input->_->watermark = 0;

   input->unsetMarker = rune_c( "." );
   input->prompt = retain_c( lit_c( "> " ) );
   input->promptStyle = base_style_cs( csORANGE_, csBLACK_ );
   input->placeHolderStyle = base_style_cs( csGREY_, csBLACK_ );
   input->textStyle = base_style_cs( csRED_, csBLACK_ );
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
   int16_t width = area.w;
   if ( input->prompt )
   {
      if ( not set_htext_cs( cord, sc_c( input->prompt ), input->promptStyle ) )
      {
         return false;
      }
      cord.x += string_length_c( input->prompt );
      width -= string_length_c( input->prompt );
   }

   if ( is_empty_c_( input->_->pile ) and input->placeHolder != NULL )
   {
      if ( not set_hline_cs( cord, width, input->unsetMarker, input->placeHolderStyle ) )
         return false;
      
      if ( not set_htext_cs( cord, sc_c( input->placeHolder ), input->placeHolderStyle ) )
         return false;
      
      return set_cursor_cs( cord );
   }


   if ( not set_hline_cs( cord, width, input->unsetMarker, input->textStyle ) )
      return false;

   int16_t newWatermark = input->_->pos - (width - 1);
   if ( input->_->watermark < newWatermark )
   {
      input->_->watermark = newWatermark;
   }
   if ( input->_->watermark > input->_->pos )
   {
      input->_->watermark = input->_->pos;
   }
   cRunes sub = mid_c_( cRunes, input->_->pile, input->_->watermark );
   sub = left_c_( cRunes, sub, width );
   if ( not set_hcells_cs( cord, sub, input->textStyle ) )
   {
      return false;
   }

   uiPoint cursor = point_ui( cord.x+input->_->pos, cord.y );
   cursor.x -= input->_->watermark;
   return set_cursor_cs( cursor );
}

bool update_text_input_cs( CSTextInput* input, CObject const* msg )
{
   must_exist_c_( input );
   must_exist_c_( msg );

   cMeta const* meta = get_meta_c( msg );
   if ( meta == &CS_KeyMsg )
   {
      CSKeyMsg const* keyMsg = msg;
      return key_msg_text_input_cs( input, keyMsg );
   }

   return true;
}

/*******************************************************************************

*******************************************************************************/

bool key_cmd_text_input_cs( CSTextInput* input, cs_KeyCmd cmd )
{
   must_exist_c_( input );
   if ( cmd == input->commands.deleteBackward )
   {
      if ( input->_->pos > 0 )
      {
         if ( not remove_rune( &input->_->pile, input->_->pos-1 ) )
         {
            return false;
         }
         input->_->pos--;
      }
      return true;
   }
   else if ( cmd == input->commands.deleteForward )
   {
      if ( input->_->pos < input->_->pile.s )
      {
         if ( not remove_rune( &input->_->pile, input->_->pos ) )
         {
            return false;
         }
      }
      return true;
   }
   else if ( cmd == input->commands.moveBackward )
   {
      if ( input->_->pos > 0 )
      {
         input->_->pos--;
      }
      return true;
   }
   else if ( cmd == input->commands.moveForward )
   {
      if ( input->_->pos < input->_->pile.s )
      {
         input->_->pos++;
      }
      return true;
   }
   else if ( cmd == input->commands.moveToStart )
   {
      input->_->pos = 0;
      return true;
   }
   else if ( cmd == input->commands.moveToEnd )
   {
      input->_->pos = input->_->pile.s;
      return true;
   }

   return true;
}

bool key_msg_text_input_cs( CSTextInput* input, CSKeyMsg const* msg )
{
   must_exist_c_( input );
   if ( msg->cmd != cs_NoCmd )
   {
      return key_cmd_text_input_cs( input, msg->cmd );
   }
   else if ( rune_is_valid_c( msg->rune ) and msg->rune.ctrl != 0 )
   {
      if ( insert_rune_cs( &input->_->pile, input->_->pos, msg->rune ) )
      {
        input->_->pos++;
        return true;
      }
   }

   return true;
}

/*******************************************************************************

*******************************************************************************/

int64_t text_input_pos_cs( CSTextInput const* input )
{
   must_exist_c_( input );
   return input->_->pos;
}

bool get_text_input_value_cs( CSTextInput const* input,
                              cRecorder rec[static 1] )
{
   must_exist_c_( input );
   if ( is_empty_c_( input->_->pile ) and input->placeHolder != NULL )
   {
      return record_chars_c( rec, sc_c( input->placeHolder ) );
   }

   int64_t const oldPos = rec->pos;
   cRunes runes = as_c_( cRunes, input->_->pile );
   each_c_( cRune const*, r, runes )
   {
      if ( not record_rune_c( rec, *r ) )
      {
         move_recorder_to_c( rec, oldPos );
         return false;
      }
   }

   return true;
}