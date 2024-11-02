#include "cmdscreen/cmdscreen.h"

struct Model
{
   cRecorder rec;
   uiSize size;
};
typedef struct Model Model;

bool show_model( Model const* model, uiRect area )
{
   uiPoint cord = top_left_corner_ui( area );
   cChars recorded = recorded_chars_c( &model->rec );
   cCharsToken tok = chars_token_c_( recorded );
   while ( next_line_token_c( &tok ) )
   {
      csStyle style = chars_starts_with_c_( tok.x, "key" ) ? base_style_cs( csRED_, csBLACK_ ) :
                      chars_starts_with_c_( tok.x, "mouse" ) ? base_style_cs( csGREEN_, csBLACK_ ) :
                      chars_starts_with_c_( tok.x, "resize" ) ? base_style_cs( csBLUE_, csBLACK_ ) :
                      base_style_cs( csBLACK_, csWHITE_ );
      cRecorder* rec = &recorder_c_( 1024 );
      write_c_( rec, "{t} {cs}", rect_tape_ui( &area ), tok.x );
      if ( not set_hline_cs( cord, recorded_chars_c( rec ), style ) )
      {
         return false;
      }
      cord.y += 1;
   }
   return true;
}

INTERN_SCREEN_CS_( it, Model, show_model )
uiBox layout_model( void const* instance )
{
   Model const* model = instance;
   return fixed_ui( model->size, screen_it( model ), none_ui() );
}

bool update_model( void* instance, CObject const* msg )
{
   Model* model = instance;
   cMeta const* meta = get_meta_c( msg );
   bool res = false;
   int64_t oldPos = model->rec.pos;
   if ( meta == &CS_KeyMsg )
   {
      CSKeyMsg const* keyMsg = msg;
      res = write_key_msg_cs_( &model->rec, keyMsg );
      if ( rune_is_c( keyMsg->rune, "q" ) )
      {
         quit_app_cs();
      }
   }
   else if ( meta == &CS_MouseMsg )
   {
      CSMouseMsg const* mouseMsg = msg;
      res = write_mouse_msg_cs_( &model->rec, mouseMsg );
   }
   else if ( meta == &CS_ResizeMsg )
   {
      CSResizeMsg const* resizeMsg = msg;
      res = write_resize_msg_cs_( &model->rec, resizeMsg );
   }
   else
   {
      res = write_cstr_c_( &model->rec, meta->desc );
   }
   model->size.w = max_c_( model->size.w, ( model->rec.pos - oldPos ) );
   model->size.h += 1;
   res &= record_char_c( &model->rec, '\n' );
   return res;
}

int main( int argc, char* argv[] )
{
   Model model = {0};
   model.rec = dyn_recorder_c_( 4096 );
   csApp app = {
      .model=&model,
      .layout=layout_model,
      .update=update_model
   };
   cErrorStack* es = &error_stack_c_( 2048 );
   bool res = run_app_cs( app, es );
   if ( not res )
   {
      return EXIT_FAILURE;
   }

   return EXIT_SUCCESS;
}