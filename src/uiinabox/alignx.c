#include "uiinabox/alignx.h"

#include "uiinabox/_/util.h"
#include "uiinabox/align.h"
#include "uiinabox/global.h"

/*******************************************************************************
 
*******************************************************************************/

static bool layout_alignx( uiBox box[static 1],
                           uiLimit limit,
                           uiAlignment alignment,
                           cErrorStack es[static 1] )
{
   if ( not has_just_single_child( "alignx", box->children, es ) )
   {
      return false;
   }
   box->rect.x = 0;
   box->rect.y = 0;

   uiBox* child = box->children.v;
   if ( not layout_box_ui( child, limit, es ) )
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

static LAYOUT_UI_( do_align_x, uiAlignment, layout_alignx, do_deref_c_ )
uiBoxType const UI_AlignX = {
   .desc = "alignx",
   .layout = &do_align_x
};

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

uiBox alignx_ui( ui_AlignX align, uiContent const* content, uiBox child )
{
   uiAlignment* data = alloc_ui_( uiAlignment );
   if ( data == NULL ) return (uiBox){0};
   else *data = alignment_ui_( align, ui_Top );

   return box_ui( data, &UI_AlignX, content, boxes_cs_( child ) );
}

/*******************************************************************************

*******************************************************************************/

extern inline uiBox left_ui( uiContent const* content, uiBox box );
extern inline uiBox centerx_ui( uiContent const* content, uiBox box );
extern inline uiBox right_ui( uiContent const* content, uiBox box );