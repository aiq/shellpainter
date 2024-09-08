#include "uiinabox/uiBox.h"

#include "clingo/clingo.h"
#include "uiinabox/global.h"

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

extern inline bool layout_box_ui( uiBox box[static 1],
                                  uiLimit limit,
                                  cErrorStack es[static 1] );

static void intl_as_global_box( uiBox box[static 1], uiPoint vec )
{
   if ( has_null_size_ui( box->rect ) )
   {
      return;
   }
   box->rect.x += vec.x;
   box->rect.y += vec.y;
   each_c_( uiBox*, child, box->children )
   {
      intl_as_global_box( child, point_ui( box->rect.x, box->rect.y ) );
   }
}

uiBox box_ui( void* data,
              uiBoxType const type[static 1],
              uiStyle const* style,
              uiBoxes children )
{
   uiBox* newChildren = alloc_array_ui_( children.s, uiBox );
   if ( newChildren == NULL ) return (uiBox){0};

   for_each_c_( i, uiBox const*, child, children )
   {
      newChildren[i] = *child;
   }

   return (uiBox){
      .data=data,
      .type=type,
      .style=style,
      .children=(csVarBoxes){ .s=children.s, .v=newChildren }
   };
}

void globalise_ui( uiBox box[static 1] )
{
   intl_as_global_box( box, point_ui( 0, 0 ) );
}

/******************************************************************************/

static bool intl_dump_box_layout( cVarRgb24Image image,
                                  uiStyle const* style,
                                  uiBox const box[static 1] )
{
   cRgb24 const* color = style;
   uiPoint a = top_left_corner_ui( box->rect );
   uiPoint b = bottom_right_corner_ui( box->rect );
   if ( not has_null_size_ui( box->rect ) )
   {
      if ( box->style != NULL )
      {
         color = box->style;
      }
      if ( not fill_rgb24_rect_c( image,
                                  pixel_c_( a.x, a.y ),
                                  pixel_c_( b.x, b.y ),
                                  *color ) )
      {
         return false;
      }
   }

   each_c_( uiBox const*, child, box->children )
   {
      if ( not intl_dump_box_layout( image, color, child ) )
      {
         return false;
      }
   }

   return true;
}

bool dump_box_layout_ui( cChars path,
                         uiBox box[static 1],
                         cErrorStack es[static 1] )
{
   cVarRgb24Image image = heap_var_rgb24_image_c_( box->rect.w, box->rect.h );
   
   cRgb24 defaultColor = rgb24_c_( 0, 0, 0 );
   bool res = false;
   if ( intl_dump_box_layout( image, &defaultColor, box ) )
   {
      cRgb24Image tmp = image_copy_c_( image );
      res = write_p3_file_c( path, tmp, es );
   }

   free( image.data );
   return res;
}