#include "cmdscreen/layout/aligny.h"

#include "cmdscreen/_/CS_MainScreen.h"
#include "cmdscreen/layout/_/util.h"

/*******************************************************************************
 
*******************************************************************************/

static bool layout_aligny( csBox box[static 1],
                           csLimit limit,
                           csAlignment alignment,
                           cErrorStack es[static 1] )
{
   if ( not has_just_single_child( "aligny", box->children, es ) )
   {
      return false;
   }
   box->rect.x = 0;
   box->rect.y = 0;

   csBox* child = box->children.v;
   if ( not layout_box_cs( child, limit, es ) )
   {
      return false;
   }
   box->rect.w = child->rect.w;
   box->rect.h = limit_height_cs_( limit );

   child->rect.x = alignx( alignment.x, box->rect.w, child->rect.w );
   child->rect.y = aligny( alignment.y, box->rect.h, child->rect.h );

   return true;
}

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

static LAYOUT_CS_( do_align_y, csAlignment, layout_aligny, do_deref_c_ )
csBoxType const CS_AlignY = {
   .desc = "aligny",
   .layout = &do_align_y
};

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

csBox aligny_cs( cs_AlignY align, csStyle const* style, csBox child )
{
   csAlignment* newAlign = alloc_one_( csAlignment );
   if ( newAlign == NULL ) return (csBox){0};
   else *newAlign = alignment_cs_( cs_Left, align );

   csBox* newChild = alloc_one_( csBox );
   if ( newChild == NULL ) return (csBox){0};
   else *newChild = child;

   return (csBox){
      .data=newAlign,
      .type=&CS_AlignY,
      .style=style,
      .children=(csVarBoxes){ .s=1, .v=newChild }
   };
}

/*******************************************************************************

*******************************************************************************/

extern inline csBox top_cs( csStyle const* style, csBox box );
extern inline csBox centery_cs( csStyle const* style, csBox box );
extern inline csBox bottom_cs( csStyle const* style, csBox box );
