#include "uiinabox/fill.h"

#include "cmdscreen/_/CS_MainScreen.h"
#include "uiinabox/_/util.h"

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
   box->rect.w = limit_width_ui_( limit );
   box->rect.h = limit_height_ui_( limit );

   uiBox* child = box->children.v;
   if ( not layout_box_ui( child, limit, es ) )
   {
      return false;
   }

   child->rect.x = 0;
   child->rect.y = 0;

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

uiBox fill_ui( int16_t fill, csStyle const* style, uiBox child )
{
   int16_t* data = alloc_one_( int16_t );
   if ( data == NULL ) return (uiBox){0};
   else *data = fill;

   return box_ui( data, &UI_Fill, style, boxes_cs_( child ) );
}

extern inline int16_t get_fill_value_ui( uiBox const box[static 1] );
