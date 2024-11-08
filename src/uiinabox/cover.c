#include "uiinabox/cover.h"

#include "uiinabox/_/util.h"
#include "uiinabox/global.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

static LAYOUT_UI_( do_cover, uiPadding, layout_cover_ui, do_deref_c_ )
uiBoxType const UI_Cover = {
   .desc = "cover",
   .layout = &do_cover
};

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

uiBox cover_ui( uiPadding pad, uiContent const* content, uiBox child )
{
   uiPadding* data = alloc_ui_( uiPadding );
   if ( data == NULL ) return (uiBox){0};
   else *data = pad;

   return box_ui( data, &UI_Cover, content, boxes_cs_( child ) );
}

bool layout_cover_ui( uiBox box[static 1],
                      uiLimit limit,
                      uiPadding pad,
                      cErrorStack es[static 1] )
{
   if ( not has_just_single_child( "cover", box->children, es ) )
   {
      return false;
   }

   uiBox* child = box->children.v;
   uiLimit childLimit = pad_limit_ui( limit, pad );
   if ( not layout_box_ui( child, childLimit, es ) )
   {
      return false;
   }
   child->rect.x = pad.left;
   child->rect.y = pad.top;

   box->rect.x = 0;
   box->rect.y = 0;
   box->rect.w = child->rect.w + pad.left + pad.right;
   box->rect.h = child->rect.h + pad.top + pad.bottom;

   return true;
}