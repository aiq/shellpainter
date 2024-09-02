#include "uiinabox/aligny.h"

#include "cmdscreen/_/CS_MainScreen.h"
#include "uiinabox/_/util.h"

/*******************************************************************************
 
*******************************************************************************/

static bool layout_aligny( uiBox box[static 1],
                           uiLimit limit,
                           uiAlignment alignment,
                           cErrorStack es[static 1] )
{
   if ( not has_just_single_child( "aligny", box->children, es ) )
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
   box->rect.w = child->rect.w;
   box->rect.h = limit_height_ui_( limit );

   child->rect.x = alignx( alignment.x, box->rect.w, child->rect.w );
   child->rect.y = aligny( alignment.y, box->rect.h, child->rect.h );

   return true;
}

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

static LAYOUT_CS_( do_align_y, uiAlignment, layout_aligny, do_deref_c_ )
uiBoxType const UI_AlignY = {
   .desc = "aligny",
   .layout = &do_align_y
};

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

uiBox aligny_ui( ui_AlignY align, uiStyle const* style, uiBox child )
{
   uiAlignment* data = alloc_one_( uiAlignment );
   if ( data == NULL ) return (uiBox){0};
   else *data = alignment_ui_( ui_Left, align );

   return box_ui( data, &UI_AlignY, style, boxes_cs_( child ) );
}

/*******************************************************************************

*******************************************************************************/

extern inline uiBox top_ui( uiStyle const* style, uiBox box );
extern inline uiBox centery_ui( uiStyle const* style, uiBox box );
extern inline uiBox bottom_ui( uiStyle const* style, uiBox box );
