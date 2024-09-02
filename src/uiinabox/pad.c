#include "uiinabox/pad.h"

#include "uiinabox/_/util.h"
#include "uiinabox/global.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

static LAYOUT_CS_( do_pad, uiPadding, layout_pad_ui, do_deref_c_ )
uiBoxType const UI_Pad = {
   .desc = "pad",
   .layout = &do_pad
};

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

extern inline
uiPadding padding_ui( int16_t left, int16_t top, int16_t right, int16_t bottom );

extern inline uiRect pad_rect_ui( uiRect rect, uiPadding pad );

#define pad_value_( Value, Pad )                                               \
(                                                                              \
    ( (Value) == CS_Infinity ) ? CS_Infinity                                   \
                               : (Value) - (Pad)                               \
)

uiLimit pad_limit_ui( uiLimit limit, uiPadding pad )
{
   int16_t const horizontal = pad.left + pad.right;
   int16_t const vertical = pad.top + pad.bottom;
   uiSize const min = (uiSize){
      .w=imax16_c( 0, limit.min.w - horizontal ),
      .h=imax16_c( 0, limit.min.h - vertical )
   };
   uiSize const max = (uiSize){
      .w=imax16_c( min.w, limit.max.w - horizontal ),
      .h=imax16_c( min.h, limit.max.h - vertical )
   };
   return (uiLimit){
      .min=min,
      .max=max
   };
}

/*******************************************************************************

*******************************************************************************/

uiBox pad_ui( uiPadding pad, uiStyle const* style, uiBox child )
{
   uiPadding* data = alloc_ui_( uiPadding );
   if ( data == NULL ) return (uiBox){0};
   else *data = pad;

   return box_ui( data, &UI_Pad, style, boxes_cs_( child ) );
}

bool layout_pad_ui( uiBox box[static 1],
                    uiLimit limit,
                    uiPadding pad,
                    cErrorStack es[static 1] )
{
   if ( not has_just_single_child( "pad", box->children, es ) )
   {
      return false;
   }
   box->rect.x = 0;
   box->rect.y = 0;
   box->rect.w = limit_width_ui_( limit );
   box->rect.h = limit_height_ui_( limit );

   uiBox* child = box->children.v;
   uiLimit childLimit = pad_limit_ui( limit, pad );
   if ( not layout_box_ui( child, childLimit, es ) )
   {
      return false;
   }
   child->rect.x = pad.left;
   child->rect.y = pad.top;

   return true;
}