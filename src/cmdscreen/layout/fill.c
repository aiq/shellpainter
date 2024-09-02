#include "cmdscreen/layout/fill.h"

#include "cmdscreen/_/CS_MainScreen.h"
#include "cmdscreen/layout/_/util.h"

static bool do_fill( csBox box[static 1],
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

   csBox* child = box->children.v;
   if ( not layout_box_cs( child, limit, es ) )
   {
      return false;
   }

   child->rect.x = 0;
   child->rect.y = 0;

   return true;
}

csBoxType const CS_Fill = {
   .desc = "fill",
   .layout = &do_fill
};

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

csBox fill_cs( int16_t fill, csStyle const* style, csBox child )
{
   int16_t* data = alloc_one_( int16_t );
   if ( data == NULL ) return (csBox){0};
   else *data = fill;

   return box_cs( data, &CS_Fill, style, boxes_cs_( child ) );
}

extern inline int16_t get_fill_value_cs( csBox const box[static 1] );
