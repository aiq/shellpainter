#include "uiinabox/sized.h"

#include "uiinabox/_/util.h"
#include "uiinabox/global.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

int16_t const UI_Shrink = -1;

int16_t const UI_Grow = INT16_MAX;

static LAYOUT_UI_( do_sized, uiSize, layout_sized_ui, do_deref_c_ )
uiBoxType const UI_Sized = {
   .desc = "sized",
   .layout = &do_sized
};

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

uiBox sized_ui( uiSize size, uiContent const* content, uiBox child )
{
   uiSize* data = alloc_ui_( uiSize );
   if ( data == NULL ) return (uiBox){0};
   else *data = size;

   return box_ui( data, &UI_Sized, content, boxes_cs_( child ) );
}

bool layout_sized_ui( uiBox box[static 1],
                      uiLimit limit,
                      uiSize size,
                      cErrorStack es[static 1] )
{
   if ( not has_just_single_child( "sized", box->children, es ) )
   {
      return false;
   }
   box->rect.x = 0;
   box->rect.y = 0;
   box->rect.w = ( size.w == UI_Shrink ) ? UI_Shrink
                                         : limit_width_ui( limit, size.w );
   box->rect.h = ( size.h == UI_Shrink ) ? UI_Shrink
                                         : limit_height_ui( limit, size.h );

   limit.max.w = ( size.w == UI_Shrink ) ? UI_Infinity
                                         : size.w;
   limit.max.h = ( size.h == UI_Shrink ) ? UI_Infinity
                                         : size.h;

   uiBox* child = box->children.v;
   if ( not layout_box_ui( child, limit, es ) )
   {
      return false;
   }
   child->rect.x = 0;
   child->rect.y = 0;

   box->rect.w = ( box->rect.w == UI_Shrink ) ? child->rect.w
                                              : box->rect.w;
   box->rect.h = ( box->rect.h == UI_Shrink ) ? child->rect.h
                                              : box->rect.h;
   return true;
}

/*******************************************************************************

*******************************************************************************/

extern inline uiSize shrink_ui( void );

extern inline uiSize grow_ui( void );