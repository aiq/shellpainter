#include "uiinabox/align.h"

#include "uiinabox/_/util.h"
#include "uiinabox/global.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

static LAYOUT_UI_( do_align, uiAlignment, layout_align_ui, do_deref_c_ )
uiBoxType const UI_Align = {
   .desc = "align",
   .layout = &do_align
};

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

char const* stringify_alignment_ui( uiAlignment alignment )
{
   if ( alignment.x == ui_Left and alignment.y == ui_Top )
      return "top-left";
   else if ( alignment.x == ui_CenterX and alignment.y == ui_Top )
      return "top-center";
   else if ( alignment.x == ui_Right and alignment.y == ui_Top )
      return "top-right";
   else if ( alignment.x == ui_Left and alignment.y == ui_CenterY )
      return "center-left";
   else if ( alignment.x == ui_CenterX and alignment.y == ui_CenterY )
      return "center";
   else if ( alignment.x == ui_Right and alignment.y == ui_CenterY )
      return "center-right";
   else if ( alignment.x == ui_Left and alignment.y == ui_Bottom )
      return "bottom-left";
   else if ( alignment.x == ui_CenterX and alignment.y == ui_Bottom )
      return "bottom-center";
   else
      return "bottom-right";
}

/*******************************************************************************

*******************************************************************************/

extern inline uiBox top_left_ui( uiContent const* content, uiBox box );
extern inline uiBox top_center_ui( uiContent const* content, uiBox box );
extern inline uiBox top_right_ui( uiContent const* content, uiBox box );

/******************************************************************************/

extern inline uiBox center_left_ui( uiContent const* content, uiBox box );
extern inline uiBox center_ui( uiContent const* content, uiBox box );
extern inline uiBox center_right_ui( uiContent const* content, uiBox box );

/******************************************************************************/

extern inline uiBox bottom_left_ui( uiContent const* content, uiBox box );
extern inline uiBox bottom_center_ui( uiContent const* content, uiBox box );
extern inline uiBox bottom_right_ui( uiContent const* content, uiBox box );

/******************************************************************************/

uiBox align_ui( uiAlignment align,
                uiContent const* content,
                uiBox child )
{
   uiAlignment* data = alloc_ui_( uiAlignment );
   if ( data == NULL ) return (uiBox){0};
   else *data = align;

   return box_ui( data, &UI_Align, content, boxes_cs_( child ) );
}

bool layout_align_ui( uiBox box[static 1],
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