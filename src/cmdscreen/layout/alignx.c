#include "cmdscreen/layout/alignx.h"

#include "cmdscreen/_/CS_MainScreen.h"
#include "cmdscreen/layout/_/util.h"

/*******************************************************************************
 
*******************************************************************************/

static bool layout_alignx( csBox box[static 1],
                           uiLimit limit,
                           csAlignment alignment,
                           cErrorStack es[static 1] )
{
   if ( not has_just_single_child( "alignx", box->children, es ) )
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
   box->rect.w = limit_width_ui_( limit );
   box->rect.h = child->rect.h;

   child->rect.x = alignx( alignment.x, box->rect.w, child->rect.w );
   child->rect.y = aligny( alignment.y, box->rect.h, child->rect.h );

   return true;
}

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

static LAYOUT_CS_( do_align_x, csAlignment, layout_alignx, do_deref_c_ )
csBoxType const CS_AlignX = {
   .desc = "alignx",
   .layout = &do_align_x
};

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

csBox alignx_cs( cs_AlignX align, csStyle const* style, csBox child )
{
   csAlignment* data = alloc_one_( csAlignment );
   if ( data == NULL ) return (csBox){0};
   else *data = alignment_cs_( align, cs_Top );

   return box_cs( data, &CS_AlignX, style, boxes_cs_( child ) );
}

/*******************************************************************************

*******************************************************************************/

extern inline csBox left_cs( csStyle const* style, csBox box );
extern inline csBox centerx_cs( csStyle const* style, csBox box );
extern inline csBox right_cs( csStyle const* style, csBox box );