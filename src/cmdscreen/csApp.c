#include "cmdscreen/csApp.h"

#include "cmdscreen/term.h"
#include "termbox.h"
#include "_/CS_MainScreen.h"
#include "cmdscreen/csMsgQueue.h"
#include "cmdscreen/CSKeyMsg.h"
#include "cmdscreen/CSMouseMsg.h"
#include "cmdscreen/CSResizeMsg.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

static bool doRun = false;

struct AppState
{
   csMemArea mem;
   csMsgQueue msgs;
};
typedef struct AppState AppState;
AppState State = {0};

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

static bool init_app_state( cErrorStack es[static 1] )
{
   set_locale_c( LC_ALL, "en_US.UTF-8" );
   init_term_cs();
   init_mem_area_cs( &State.mem, csBLOCK_SIZE_ );
   init_ui();
   return true;
}

static void cleanup_app_state( AppState state[static 1] )
{
   cleanup_ui();
   cleanup_mem_area_cs( &State.mem );
   cleanup_term_cs();
}

static bool event_as_key_msg( struct tb_event event[static 1],
                              cErrorStack es[static 1]  )
{
   CSKeyMsg* msg = retain_c( new_key_msg_cs_() );
   if ( msg == NULL )
   {
      return push_errno_error_c( es, errno );
   }
   msg->code = event->key;
   msg->rune = utf32_rune_c( event->ch );
   if ( not push_msg_cs( &State.msgs, msg ) )
   {
      release_c( msg );
      return push_lit_error_c( es, "not able to push to msg queue" );
   }
   return true;
}

static bool event_as_mouse_msg( struct tb_event event[static 1],
                                cErrorStack es[static 1] )
{
   CSMouseMsg* msg = retain_c( new_mouse_msg_cs_() );
   if ( msg == NULL )
   {
      return push_errno_error_c( es, errno );
   }
   msg->left = event->key == TB_KEY_MOUSE_LEFT;
   msg->middle = event->key == TB_KEY_MOUSE_MIDDLE;
   msg->right = event->key == TB_KEY_MOUSE_RIGHT;
   msg->wheelUp = event->key == TB_KEY_MOUSE_WHEEL_UP;
   msg->wheelDown = event->key == TB_KEY_MOUSE_WHEEL_DOWN;
   msg->released = event->key == TB_KEY_MOUSE_RELEASE;
   if ( not push_msg_cs( &State.msgs, msg ) )
   {
      release_c( msg );
      return push_lit_error_c( es, "not able to push to msg queue" );
   }
   return true;
}

static bool event_as_resize_msg( struct tb_event event[static 1],
                                 cErrorStack es[static 1] )
{
   CSResizeMsg* msg = retain_c( new_resize_msg_cs_() );
   if ( msg == NULL )
   {
      return push_errno_error_c( es, errno );
   }
   msg->w = event->w;
   msg->h = event->h;
   if ( not push_msg_cs( &State.msgs, msg ) )
   {
      release_c( msg );
      return push_lit_error_c( es, "not able to push to msg queue" );
   }
   return true;
}

static bool poll_term_input_event( cErrorStack es[static 1] )
{
   struct tb_event event;
   int ret = TB_OK;
   do
   {
      ret = tb_poll_event( &event );
      if ( ret == TB_ERR_POLL and tb_last_errno() != EINTR )
      {
         return false;
      }
   } while ( ret != TB_OK );

   switch ( event.type )
   {
   case TB_EVENT_KEY:
      return event_as_key_msg( &event, es );
    
   case TB_EVENT_MOUSE:
      return event_as_mouse_msg( &event, es );

   case TB_EVENT_RESIZE:
      return event_as_resize_msg( &event, es );;

   default:
      return false;;
   }
}

static bool screen_boxes( uiBox const box[static 1] )
{
   if ( box->content != NULL )
   {
      csScreen const* screen = box->content;
      if ( not screen->f( screen->i, box->rect ) )
      {
         return false;
      }
   }

   each_c_( uiBox const*, child, box->children )
   {
      if ( not screen_boxes( child ) )
      {
         return false;
      }
   }

   return true;
}

/*******************************************************************************

*******************************************************************************/

bool run_app_cs( csApp app, cErrorStack es[static 1] )
{
   if ( not init_app_state( es ) )
   {
      return false;
   }

   bool res = true;
   doRun = true;
   uiSize termSize = term_size_cs();
   while ( doRun )
   {
      uiBox root = app.layout( app.model );
      if ( not layout_box_ui( &root, fix_limit_ui( termSize.w, termSize.h ), es ) )
      {
         res = push_lit_error_c( es, "layout failed" );
         break;
      }
      globalise_ui( &root );
      clear_cs();
      if ( not screen_boxes( &root ) )
      {
         res = push_lit_error_c( es, "screen boxes failed" );
         break;
      }
      refresh_cs();
      if ( not poll_term_input_event( es ) )
      {
         res = push_lit_error_c( es, "poll term input failed" );
         break;
      }
      while ( not is_empty_c_( State.msgs ) )
      {
         CObject* msg = pull_msg_cs( &State.msgs );
         if ( not app.update( app.model, msg ) )
         {
            res = push_lit_error_c( es, "update failed" );
         }
         release_c( msg );
      }
      if ( res == false )
      {
         break;
      }
   }
   cleanup_cmdscreen_cs();
   return res;
}

void quit_app_cs( void )
{
   doRun = false;
}
