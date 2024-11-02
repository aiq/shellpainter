#include "uiinabox/scroll.h"

#include "uiinabox/_/util.h"
#include "uiinabox/global.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

static bool do_scroll( uiBox box[static 1],
                       uiLimit limit,
                       void const* ignore,
                       cErrorStack es[static 1] )
{
   if ( not has_just_single_child( "scroll", box->children, es ) )
   {
      return false;
   }

   uiBox* child = box->children.v;
   if ( not layout_box_ui( child, limit, es ) )
   {
      return false;
   }
   child->rect.x = 0;
   child->rect.y = 0;
   box->rect = child->rect;

   uiBox* area = box->data;
   if ( not layout_box_ui( area, no_limit_ui(), es ) )
   {
      return false;
   }

   return true;
}
uiBoxType const UI_Scroll = {
   .desc = "scroll",
   .layout = &do_scroll
};

/*******************************************************************************
********************************************************************* Functions
********************************************************************************
 
*******************************************************************************/

uiBox scroll_ui( uiBox window, uiBox area )
{
   return box_ui( NULL, &UI_Scroll, NULL, boxes_cs_( window ) );
}

bool update_scroll_ui( uiBox const box[static 1] )
{
   if ( box->type == &UI_Scroll )
   {
   }
   return true; 
}
