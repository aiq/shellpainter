#include "uiinabox/box/pad.h"

#include "cmdscreen/_/CS_MainScreen.h"
#include "uiinabox/box/_/util.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

static LAYOUT_CS_( do_pad, uiPadding, layout_pad_ui, do_deref_c_ )
uiBoxType const UI_Pad = {
   .desc = "pad",
   .layout = &do_pad
};

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

uiBox pad_ui( uiPadding pad, csStyle const* style, uiBox child )
{
   uiPadding* data = alloc_one_( uiPadding );
   if ( data == NULL ) return (uiBox){0};
   else *data = pad;

   return box_ui( data, &UI_Pad, style, boxes_cs_( child ) );
}

bool layout_pad_ui( uiBox box[static 1],
                    uiLimit limit,
                    uiPadding pad,
                    cErrorStack es[static 1] )
{
   if ( not has_just_single_child( "pad", box->children, es ) )
   {
      return false;
   }
   box->rect.x = 0;
   box->rect.y = 0;
   box->rect.w = limit_width_ui_( limit );
   box->rect.h = limit_height_ui_( limit );

   uiBox* child = box->children.v;
   uiLimit childLimit = pad_limit_ui( limit, pad );
   if ( not layout_box_ui( child, childLimit, es ) )
   {
      return false;
   }
   child->rect.x = pad.left;
   child->rect.y = pad.top;

   return true;
}