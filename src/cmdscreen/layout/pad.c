#include "cmdscreen/layout/pad.h"

#include "cmdscreen/_/CS_MainScreen.h"
#include "cmdscreen/layout/_/util.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

static LAYOUT_CS_( do_pad, csPadding, layout_pad_cs, do_deref_c_ )
csBoxType const CS_Pad = {
   .desc = "pad",
   .layout = &do_pad
};

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

csBox pad_cs( csPadding pad, csStyle const* style, csBox child )
{
   csPadding* data = alloc_one_( csPadding );
   if ( data == NULL ) return (csBox){0};
   else *data = pad;

   return box_cs( data, &CS_Pad, style, boxes_cs_( child ) );
}

bool layout_pad_cs( csBox box[static 1],
                    csLimit limit,
                    csPadding pad,
                    cErrorStack es[static 1] )
{
   if ( not has_just_single_child( "pad", box->children, es ) )
   {
      return false;
   }
   box->rect.x = 0;
   box->rect.y = 0;
   box->rect.w = limit_width_cs_( limit );
   box->rect.h = limit_height_cs_( limit );

   csBox* child = box->children.v;
   csLimit childLimit = pad_limit_cs( limit, pad );
   if ( not layout_box_cs( child, childLimit, es ) )
   {
      return false;
   }
   child->rect.x = pad.left;
   child->rect.y = pad.top;

   return true;
}