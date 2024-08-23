#include "cmdscreen/csLayout.h"

#include "clingo/io/jot.h"
#include "clingo/io/write.h"
#include "clingo/lang/error_type.h"
#include "clingo/lang/func.h"
#include "clingo/type/float.h"

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/
/*
static float trunc_float( float f, float* diff )
{
   float res = truncf( f );
   *diff = f - res;
   return res;
}

static bool layout_single( csPoint pos,
                           csBox box,
                           csLayout layout[static 1],
                           cErrorStack es[static 1] )
{

   return false;
}

static bool layout_with_children( csPoint pos,
                                  csBox box,
                                  csLayout layout[static 1],
                                  cErrorStack es[static 1] )
{
   cs_Axis const axis = ( layout->type == cs_Row ) ? cs_Horizontal
                                                   : cs_Vertical;
   csPoint const origin = point_cs_( pos.x + layout->rule.padding.left,
                                     pos.y + layout->rule.padding.top );
   csBox const insideBox = pad_box_cs( box, layout->rule.padding );
   int16_t mainAxis = main_axis_cs_( insideBox, axis );
   int16_t crossAxis = cross_axis_cs_( insideBox, axis );
   int16_t fillCount = 0;
   each_c_( csLayout*, child, layout->children )
   {
      if ( child->rule.fill > 0 )
      {
         int16_t fillPart = child->rule.fill;
         if ( not iadd16_c( fillCount, fillPart, &fillCount ) )
         {
            return push_iadd16_error_c(es, fillCount, fillPart );
         }
      }
      else
      {
         int16_t mainPart = main_axis_cs( child->rule.box, axis, mainAxis );
         mainAxis -= mainPart;
         if ( mainAxis < 0 )
         {
            return push_lit_error_c( es, "not engouh space on the main axis" );
         }
         int16_t crossPart = cross_axis_cs( child->rule.box, axis, crossAxis );
         csSize size = axis_size_cs_( axis, mainPart, crossPart );
         child->rect.w = size.w;
         child->rect.h = size.h;
      }
   }

   float const part = float_c_( mainAxis ) / float_c_( fillCount );
   float diff = 0.0;
   each_c_( csLayout*, child, layout->children )
   {
      if ( child->rule.fill == 0 )
         continue;

      float mainVal = float_c_( child->rule.fill ) * part;
      mainVal = trunc_float( mainVal + diff, &diff );
      int16_t mainPart = main_axis_cs( child->rule.box, axis, int16_c_( mainVal ) );
      mainAxis -= mainPart;
      if ( mainAxis < 0 )
      {
         return push_lit_error_c( es, "not engouh space on the main axis" );
      }
      int16_t crossPart = cross_axis_cs( child->rule.box, axis, crossAxis );
      csSize size = axis_size_cs_( axis, mainPart, crossPart );
      child->rect.w = size.w;
      child->rect.h = size.h;
   }
   return true;

}

bool layout_cs( csRect parent,
                csLayout layout[static 1],
                cErrorStack es[static 1] )
{
   if ( layout->type == cs_Row or
        layout->type == cs_Column )
   {
      return layout_with_children( parent, layout, es );
   }

   return push_lit_error_c( es, "unknown layout type" );
};
*/


/*******************************************************************************

*******************************************************************************/

static bool has_just_single_child( char const name[static 1],
                                   csVarBoxes children,
                                   cErrorStack es[static 1] )
{
   int64_t const size = children.s;
   if ( size != 1 )
   {
      return push_text_error_c_( es, "{s:q} works just with one children, got {i}", name, size );
   }
   return true;
}

bool layout_pad_cs( csBox box[static 1],
                    csLimit limit,
                    csPadding pad,
                    cErrorStack es[static 1] )
{
   if ( not has_just_single_child( "pad", box->children, es ) )
   {
      return false;
   }
   box->rect.x = 0;
   box->rect.y = 0;
   box->rect.w = limit_width_cs_( limit );
   box->rect.h = limit_height_cs_( limit );

   csBox* child = box->children.v;
   csLimit childLimit = pad_limit_cs( limit, pad );
   if ( not layout_box_cs_( child, childLimit, es ) )
   {
      return false;
   }
   child->rect.x = pad.left;
   child->rect.y = pad.top;

   return true;
}

static LAYOUT_CS_( pad_func, csPadding, layout_pad_cs, do_deref_c_ )
csLayout pad_cs( csPadding const* pad )
{
   return (csLayout){ .i=pad, .f=pad_func };
}

bool layout_align_cs( csBox box[static 1],
                      csLimit limit,
                      csAlignment alignment,
                      cErrorStack es[static 1] )
{
   if ( not has_just_single_child( "align", box->children, es ) )
   {
      return false;
   }
   box->rect.x = 0;
   box->rect.y = 0;
   box->rect.w = limit_width_cs_( limit );
   box->rect.h = limit_height_cs_( limit );

   csBox* child = box->children.v;
   if ( not layout_box_cs_( child, limit, es ) )
   {
      return false;
   }

   if ( alignment.x == cs_CenterX )
   {
      child->rect.x = ( box->rect.w / 2 ) - ( child->rect.w / 2 );
   }
   else if ( alignment.x == cs_Right )
   {
      child->rect.x = box->rect.w - child->rect.w;
   }
   else  // cs_Left
   {
      child->rect.x = 0;
   }

   if ( alignment.y == cs_CenterY )
   {
      child->rect.y = ( box->rect.h / 2 ) - ( child->rect.h / 2 );
   }
   else if ( alignment.y == cs_Bottom )
   {
      child->rect.y = box->rect.h - child->rect.h;
   }
   else  // cs_Top
   {
      child->rect.y = 0;
   }

   return true;
}

static LAYOUT_CS_( align_func, csAlignment, layout_align_cs, do_deref_c_ )
csLayout align_cs( csAlignment const* align )
{
   return (csLayout){ .i=align, .f=align_func };
}

bool layout_fixed_cs( csBox box[static 1],
                      csLimit limit,
                      csSize size,
                      cErrorStack es[static 1] )
{
   if ( not has_just_single_child( "fixed", box->children, es ) )
   {
      return false;
   }
   box->rect.x = 0;
   box->rect.y = 0;
   box->rect.w = limit_width_cs( limit, size.w );
   box->rect.h = limit_height_cs( limit, size.h );

   limit.max = size;

   csBox* child = box->children.v;
   if ( not layout_box_cs_( child, limit, es ) )
   {
      return false;
   }
   child->rect.x = 0;
   child->rect.y = 0;
   return true;
}

static LAYOUT_CS_( fixed_func, csSize, layout_fixed_cs, do_deref_c_ )
csLayout fixed_cs( csSize const* size )
{
   return (csLayout){ .i=size, .f=fixed_func };
}

static bool none_func( csBox box[static 1],
                       csLimit limit,
                       void const* i,
                       cErrorStack es[static 1] )
{
   box->rect.w = 0;
   box->rect.h = 0;
   return true;
}
csLayout none_layout_cs( void )
{
   return (csLayout){ .i=NULL, .f=none_func };
}

/*******************************************************************************

*******************************************************************************/

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

void as_global_box_cs( csBox box[static 1] )
{
   intl_as_global_box( box, point_cs( 0, 0 ) );
}

/******************************************************************************/

static bool intl_dump_box_layout( cVarRgb24Image image,
                                  csBox const box[static 1] )
{
   csPoint a = top_left_corner_cs( box->rect );
   csPoint b = bottom_right_corner_cs( box->rect );
   if ( not has_null_size_cs( box->rect ) )
   {
      if ( not fill_rgb24_rect_c( image,
                                  pixel_c_( a.x, a.y ),
                                  pixel_c_( b.x, b.y ),
                                  box->style.back ) )
      {
         return false;
      }
   }

   each_c_( csBox const*, child, box->children )
   {
      if ( not intl_dump_box_layout( image, child ) )
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
   if ( intl_dump_box_layout( image, box ) )
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