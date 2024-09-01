#include "cmdscreen/csBox.h"

#include "clingo/color/cRgb24.h"
#include "clingo/io/jot.h"
#include "clingo/io/write.h"
#include "clingo/lang/error_type.h"
#include "clingo/lang/func.h"
#include "clingo/type/float.h"

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

extern inline bool layout_box_cs( csBox box[static 1],
                                  csLimit limit,
                                  cErrorStack es[static 1] );

static void intl_as_global_box( csBox box[static 1], csPoint vec )
{
   if ( has_null_size_cs( box->rect ) )
   {
      return;
   }
   box->rect.x += vec.x;
   box->rect.y += vec.y;
   each_c_( csBox*, child, box->children )
   {
      intl_as_global_box( child, point_cs( box->rect.x, box->rect.y ) );
   }
}

void globalise_cs( csBox box[static 1] )
{
   intl_as_global_box( box, point_cs( 0, 0 ) );
}

/******************************************************************************/

static bool intl_dump_box_layout( cVarRgb24Image image,
                                  csStyle const* style,
                                  csBox const box[static 1] )
{
   csPoint a = top_left_corner_cs( box->rect );
   csPoint b = bottom_right_corner_cs( box->rect );
   if ( not has_null_size_cs( box->rect ) )
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

   each_c_( csBox const*, child, box->children )
   {
      if ( not intl_dump_box_layout( image, style, child ) )
      {
         return false;
      }
   }

   return true;
}

bool dump_box_layout_cs( cChars path,
                         csBox box[static 1],
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
                                  cs_DiffConfig cfg,
                                  csBox const box[static 1],
                                  csBox const oth[static 1] )
{
   if ( has_c_( cfg, cs_CheckRect ) )
   {
      if ( not eq_rect_cs( box->rect, oth->rect ) )
      {
         return jotln_c_( rec, "~= ", route, " different rect values: ",
                               "expected ", rect_tape_cs_( box->rect ),
                               ", got ", rect_tape_cs_( oth->rect ) );
      }
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

      csBox const* boxChild = ptr_for_c_( box->children, i );
      csBox const* othChild = ptr_for_c_( oth->children, i );
      if ( not intl_record_box_diff( rec, route, cfg, boxChild, othChild ) )
         return false;

      move_recorder_to_c( route, oldPos );
   }

   return true;
}

bool record_box_diff_cs( cRecorder rec[static 1],
                         cs_DiffConfig cfg,
                         csBox const box[static 1],
                         csBox const oth[static 1] )
{
   cRecorder* route = &dyn_recorder_c_( 0 );
   bool res = false;
   if ( write_c_( route, "{i}", 0 ) )
   {
      res = intl_record_box_diff( rec, route, cfg, box, oth );
   }
   free_recorder_mem_c( route );
   return res;
}