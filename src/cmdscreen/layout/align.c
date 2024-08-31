#include "cmdscreen/layout/align.h"

#include "cmdscreen/_/CS_MainScreen.h"
#include "cmdscreen/layout/_/util.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

static LAYOUT_CS_( do_align, csAlignment, layout_align_cs, do_deref_c_ )
csBoxType const CS_Align = {
   .desc = "align",
   .layout = &do_align
};

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

csBox align_cs( csAlignment align,
                csStyle const* style,
                csBox child )
{
   csAlignment* newAlign = alloc_one_( csAlignment );
   if ( newAlign == NULL ) return (csBox){0};
   else *newAlign = align;

   csBox* newChild = alloc_one_( csBox );
   if ( newChild == NULL ) return (csBox){0};
   else *newChild = child;

   return (csBox){
      .payload=newAlign,
      .type=&CS_Align,
      .style=style,
      .children=(csVarBoxes){ .s=1, .v=newChild }
   };
}

bool layout_align_cs( csBox box[static 1],
                      csLimit limit,
                      csAlignment alignment,
                      cErrorStack es[static 1] )
{
   if ( not has_just_single_child( "align", box->children, es ) )
   {
      return false;
   }
   box->rect.x = 0;
   box->rect.y = 0;
   box->rect.w = limit_width_cs_( limit );
   box->rect.h = limit_height_cs_( limit );

   csBox* child = box->children.v;
   if ( not layout_box_cs( child, limit, es ) )
   {
      return false;
   }

   child->rect.x = alignx( alignment.x, box->rect.w, child->rect.w );
   child->rect.y = aligny( alignment.y, box->rect.h, child->rect.h );

   return true;
}