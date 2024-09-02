#include "cmdscreen/layout/fixed.h"

#include "cmdscreen/_/CS_MainScreen.h"
#include "cmdscreen/layout/_/util.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

static LAYOUT_CS_( do_fixed, uiSize, layout_fixed_cs, do_deref_c_ )
uiBoxType const CS_Fixed = {
   .desc = "fixed",
   .layout = &do_fixed
};

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

uiBox fixed_cs( uiSize size, csStyle const* style, uiBox child )
{
   uiSize* data = alloc_one_( uiSize );
   if ( data == NULL ) return (uiBox){0};
   else *data = size;

   return box_ui( data, &CS_Fixed, style, boxes_cs_( child ) );
}

bool layout_fixed_cs( uiBox box[static 1],
                      uiLimit limit,
                      uiSize size,
                      cErrorStack es[static 1] )
{
   if ( not has_just_single_child( "fixed", box->children, es ) )
   {
      return false;
   }
   box->rect.x = 0;
   box->rect.y = 0;
   box->rect.w = limit_width_ui( limit, size.w );
   box->rect.h = limit_height_ui( limit, size.h );

   limit.max = size;

   uiBox* child = box->children.v;
   if ( not layout_box_ui( child, limit, es ) )
   {
      return false;
   }
   child->rect.x = 0;
   child->rect.y = 0;
   return true;
}