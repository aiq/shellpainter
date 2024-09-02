#include "uiinabox/uiBox.h"

#include "clingo/color/cRgb24.h"
#include "clingo/io/jot.h"
#include "clingo/io/write.h"
#include "clingo/lang/error_type.h"
#include "clingo/lang/func.h"
#include "clingo/type/float.h"
#include "cmdscreen/_/CS_MainScreen.h"

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
              csStyle const* style,
              uiBoxes children )
{
   uiBox* newChildren = alloc_array_( children.s, uiBox );
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
                                  csStyle const* style,
                                  uiBox const box[static 1] )
{
   uiPoint a = top_left_corner_ui( box->rect );
   uiPoint b = bottom_right_corner_ui( box->rect );
   if ( not has_null_size_ui( box->rect ) )
   {
      if ( box->style != NULL )
      {
         style = box->style;
      }
      if ( not fill_rgb24_rect_c( image,
                                  pixel_c_( a.x, a.y ),
                                  pixel_c_( b.x, b.y ),
                                  style->back ) )
      {
         return false;
      }
   }

   each_c_( uiBox const*, child, box->children )
   {
      if ( not intl_dump_box_layout( image, style, child ) )
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
   
   bool res = false;
   if ( intl_dump_box_layout( image, &CS_DefaultStyle, box ) )
   {
      cRgb24Image tmp = image_copy_c_( image );
      res = write_p3_file_c( path, tmp, es );
   }

   free( image.data );
   return res;
}

/******************************************************************************/

static bool intl_record_box_diff( cRecorder rec[static 1],
                                  cRecorder route[static 1],
                                  uiBox const box[static 1],
                                  uiBox const oth[static 1] )
{
   if ( not eq_rect_ui( box->rect, oth->rect ) )
   {
      return jotln_c_( rec, "~= ", route, " different rect values: ",
                            "expected ", rect_tape_ui_( box->rect ),
                            ", got ", rect_tape_ui_( oth->rect ) );
   }

   if ( box->children.s != oth->children.s )
   {
      return jotln_c_( rec, "~= ", route, " different number of children: ",
                            "expected ", box->children.s,
                            ", got ", oth->children.s );
   }

   int64_t const oldPos = route->pos;
   for ( int64_t i = 0; i < box->children.s; ++i )
   {
      if ( not write_c_( route, ":{i}", i ) )
         return false;

      uiBox const* boxChild = ptr_for_c_( box->children, i );
      uiBox const* othChild = ptr_for_c_( oth->children, i );
      if ( not intl_record_box_diff( rec, route, boxChild, othChild ) )
         return false;

      move_recorder_to_c( route, oldPos );
   }

   return true;
}

bool record_box_diff_ui( cRecorder rec[static 1],
                         uiBox const box[static 1],
                         uiBox const oth[static 1] )
{
   cRecorder* route = &dyn_recorder_c_( 0 );
   bool res = false;
   if ( write_c_( route, "{i}", 0 ) )
   {
      res = intl_record_box_diff( rec, route, box, oth );
   }
   free_recorder_mem_c( route );
   return res;
}