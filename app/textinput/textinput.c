#include "cmdscreen/cmdscreen.h"

struct Model
{
   CSLabel* question;
   CSTextInput* input;
   CSLabel* note;
};
typedef struct Model Model;

uiBox layout_model( void const* instance )
{
   Model const* model = instance;
   return center_ui_(
      sized_ui_(
         size_ui( 40, UI_Shrink ),
         col_ui_(
            1,
            boxes_cs_(
               label_box_cs( model->question ),
               text_input_box_cs( model->input ),
               centerx_ui_(
                  label_box_cs( model->note )
               )
            )
         )
      )
   );
}

bool update_model( void* instance, CObject const* msg )
{
   Model* model = instance;
   cMeta const* meta = get_meta_c( msg );
   if ( meta == &CS_KeyMsg )
   {
      CSKeyMsg const* keyMsg = msg;
      if ( keyMsg->cmd == cs_EscapeKey )
      {
         return quit_app_cs();
      }
      return update_text_input_cs( model->input, keyMsg );
   }
   return true;
}

int main( int argc, char* argv[] )
{
   Model model = {0};
   model.question = new_label_cs_();
   {
      model.question->text = lit_c( "What is your favorite day of the week?" );
      model.question->style = base_style_cs( csTEAL_, csBLACK_ );
   }
   model.input = new_text_input_cs();
   {
      model.input->prompt = lit_c( "> " );
      model.input->placeHolder = lit_c( "thursday" );
      model.input->textStyle = base_style_cs( csPINK_, csBLACK_ );
   }
   model.note = new_label_cs_();
   {
      model.note->text = lit_c( "press 'esc' to quit" );
      model.note->style = base_style_cs( csTEAL_, csBLACK_ );
   }

   csApp app = {
      .model=&model,
      .layout=layout_model,
      .update=update_model
   };
   cErrorStack* es = &error_stack_c_( 2048 );
   bool res = run_app_cs( app, es );
   if ( not res )
   {
      println_c_( "error: {e}", es->err );
      return EXIT_FAILURE;
   }

   return EXIT_SUCCESS;
}