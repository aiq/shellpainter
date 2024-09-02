#include "cmdscreen/layout/fixed.h"

#include "cmdscreen/_/CS_MainScreen.h"
#include "cmdscreen/layout/_/util.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

static LAYOUT_CS_( do_fixed, csSize, layout_fixed_cs, do_deref_c_ )
csBoxType const CS_Fixed = {
   .desc = "fixed",
   .layout = &do_fixed
};

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

csBox fixed_cs( csSize size, csStyle const* style, csBox child )
{
   csSize* data = alloc_one_( csSize );
   if ( data == NULL ) return (csBox){0};
   else *data = size;

   return box_cs( data, &CS_Fixed, style, boxes_cs_( child ) );
}

bool layout_fixed_cs( csBox box[static 1],
                      csLimit limit,
                      csSize size,
                      cErrorStack es[static 1] )
{
   if ( not has_just_single_child( "fixed", box->children, es ) )
   {
      return false;
   }
   box->rect.x = 0;
   box->rect.y = 0;
   box->rect.w = limit_width_cs( limit, size.w );
   box->rect.h = limit_height_cs( limit, size.h );

   limit.max = size;

   csBox* child = box->children.v;
   if ( not layout_box_cs( child, limit, es ) )
   {
      return false;
   }
   child->rect.x = 0;
   child->rect.y = 0;
   return true;
}