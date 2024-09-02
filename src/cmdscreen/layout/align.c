#include "cmdscreen/layout/align.h"

#include "cmdscreen/_/CS_MainScreen.h"
#include "cmdscreen/layout/_/util.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

static LAYOUT_CS_( do_align, uiAlignment, layout_align_cs, do_deref_c_ )
uiBoxType const CS_Align = {
   .desc = "align",
   .layout = &do_align
};

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

extern inline uiBox top_left_cs( csStyle const* style, uiBox box );
extern inline uiBox top_center_cs( csStyle const* style, uiBox box );
extern inline uiBox top_right_cs( csStyle const* style, uiBox box );

/******************************************************************************/

extern inline uiBox center_left_cs( csStyle const* style, uiBox box );
extern inline uiBox center_cs( csStyle const* style, uiBox box );
extern inline uiBox center_right_cs( csStyle const* style, uiBox box );

/******************************************************************************/

extern inline uiBox bottom_left_cs( csStyle const* style, uiBox box );
extern inline uiBox bottom_center_cs( csStyle const* style, uiBox box );
extern inline uiBox bottom_right_cs( csStyle const* style, uiBox box );

/******************************************************************************/

uiBox align_cs( uiAlignment align,
                csStyle const* style,
                uiBox child )
{
   uiAlignment* data = alloc_one_( uiAlignment );
   if ( data == NULL ) return (uiBox){0};
   else *data = align;

   return box_ui( data, &CS_Align, style, boxes_cs_( child ) );
}

bool layout_align_cs( uiBox box[static 1],
                      uiLimit limit,
                      uiAlignment alignment,
                      cErrorStack es[static 1] )
{
   if ( not has_just_single_child( "align", box->children, es ) )
   {
      return false;
   }
   box->rect.x = 0;
   box->rect.y = 0;
   box->rect.w = limit_width_ui_( limit );
   box->rect.h = limit_height_ui_( limit );

   uiBox* child = box->children.v;
   if ( not layout_box_ui( child, limit, es ) )
   {
      return false;
   }

   child->rect.x = alignx( alignment.x, box->rect.w, child->rect.w );
   child->rect.y = aligny( alignment.y, box->rect.h, child->rect.h );

   return true;
}