#include "uiinabox/fill.h"

#include "uiinabox/_/util.h"
#include "uiinabox/global.h"

static bool do_fill( uiBox box[static 1],
                     uiLimit limit,
                     void const* nothing,
                     cErrorStack es[static 1] )
{
   if ( not has_just_single_child( "fill", box->children, es ) )
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
   child->rect.x = 0;
   child->rect.y = 0;

   uiFill const* fill = box->data;
   if ( fill->axis == ui_Horizontal )
   {
      box->rect.w = limit_width_ui_( limit );
      box->rect.h = child->rect.h;
   }
   else // ui_Vertical
   {
      box->rect.w = child->rect.w;
      box->rect.h = limit_height_ui_( limit );
   }

   return true;
}

uiBoxType const UI_Fill = {
   .desc = "fill",
   .layout = &do_fill
};

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

uiBox fill_ui( ui_Axis axis, int16_t fill, uiContent const* content, uiBox child )
{
   uiFill* data = alloc_ui_( uiFill );
   if ( data == NULL ) return (uiBox){0};
   else *data = (uiFill){ .axis=axis, .val=fill };

   return box_ui( data, &UI_Fill, content, boxes_cs_( child ) );
}

extern inline bool set_fill_axis_ui( uiBox box[static 1], ui_Axis axis );

extern inline int16_t fill_value_ui( uiBox const box[static 1] );
