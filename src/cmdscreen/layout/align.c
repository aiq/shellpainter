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

extern inline csBox top_left_cs( csStyle const* style, csBox box );
extern inline csBox top_center_cs( csStyle const* style, csBox box );
extern inline csBox top_right_cs( csStyle const* style, csBox box );

/******************************************************************************/

extern inline csBox center_left_cs( csStyle const* style, csBox box );
extern inline csBox center_cs( csStyle const* style, csBox box );
extern inline csBox center_right_cs( csStyle const* style, csBox box );

/******************************************************************************/

extern inline csBox bottom_left_cs( csStyle const* style, csBox box );
extern inline csBox bottom_center_cs( csStyle const* style, csBox box );
extern inline csBox bottom_right_cs( csStyle const* style, csBox box );

/******************************************************************************/

csBox align_cs( csAlignment align,
                csStyle const* style,
                csBox child )
{
   csAlignment* data = alloc_one_( csAlignment );
   if ( data == NULL ) return (csBox){0};
   else *data = align;

   return box_cs( data, &CS_Align, style, boxes_cs_( child ) );
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