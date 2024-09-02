#include "cmdscreen/layout/line.h"

#include "cmdscreen/_/CS_MainScreen.h"
#include "cmdscreen/layout/_/util.h"
#include "cmdscreen/layout/fill.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

static LAYOUT_CS_( do_line, csLine, layout_line_cs, do_deref_c_ )
csBoxType const CS_Line = {
   .desc = "line",
   .layout = &do_line
};

/*******************************************************************************

*******************************************************************************/

static float trunc_float( float f, float* diff )
{
   float res = truncf( f );
   *diff = f - res;
   return res;
}

static csLimit limit_for_fill( csLimit limit, ui_Axis axis, int16_t max )
{
   if ( axis == ui_Horizontal )
   {
      limit.max = (csSize){
         .w=imax16_c( limit.min.w, max ),
         .h=limit.max.h
      };
   }
   else  // ui_Vertical
   {
      limit.max = (csSize){
         .w=limit.max.w,
         .h=imax16_c( limit.min.h, max )
      };
   }

   return limit;
}

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

csBox row_cs( int16_t space, csStyle const* style, csBoxes children )
{
   return line_cs( ui_Horizontal, space, style, children );
}

csBox col_cs( int16_t space, csStyle const* style, csBoxes children )
{
   return line_cs( ui_Vertical, space, style, children );
}

csBox line_cs( ui_Axis axis,
               int16_t space,
               csStyle const* style,
               csBoxes children )
{
   csLine* data = alloc_one_( csLine );
   if ( data == NULL ) return (csBox){0};
   else *data = (csLine){ .axis=axis, .space=space };

   return box_cs( data, &CS_Line, style, children );
}

bool layout_line_cs( csBox box[static 1],
                     csLimit limit,
                     csLine line,
                     cErrorStack es[static 1] )
{
   int16_t mainAxis = main_axis_cs_( limit, line.axis );
   int16_t fillCount = 0;
   each_c_( csBox*, child, box->children )
   {
      int16_t const fill = get_fill_value_cs( child );
      if ( fill > 0 )
      {
         int16_t fillPart = fill;
         if ( not iadd16_c( fillCount, fillPart, &fillCount ) )
         {
            return push_iadd16_error_c(es, fillCount, fillPart );
         }
      }
      else
      {
         if ( not layout_box_cs( child, limit, es ) )
         {
            return false;
         }
         int16_t const mainPart = ( line.axis == ui_Horizontal ) ? child->rect.w
                                                                 : child->rect.h;
         mainAxis -= mainPart;
         if ( mainAxis < 0 )
         {
            return push_lit_error_c( es, "not engouh space on the main axis" );
         }
      }
   }

   float const part = float_c_( mainAxis ) / float_c_( fillCount );
   float diff = 0.0;
   each_c_( csBox*, child, box->children )
   {
      int16_t const fill = get_fill_value_cs( child );
      if ( fill == 0 )
         continue;

      float mainVal = float_c_( fill ) * part;
      mainVal = trunc_float( mainVal + diff, &diff );
      csLimit lim = limit_for_fill( limit, line.axis, int16_c_( mainVal ) );
      if ( not layout_box_cs( child, lim, es ) )
      {
         return false;
      }
      int16_t const mainPart = ( line.axis == ui_Horizontal ) ? child->rect.w
                                                              : child->rect.h;
      mainAxis -= mainPart;
      if ( mainAxis < 0 )
      {
         return push_lit_error_c( es, "not engouh space on the main axis" );
      }
   }

   box->rect.w = 0;
   box->rect.h = 0;
   each_c_( csBox*, child, box->children )
   {
      if ( line.axis == ui_Horizontal )
      {
         child->rect.x = box->rect.w;
         child->rect.y = 0;
         box->rect.w += child->rect.w;
         box->rect.h = imax16_c( box->rect.h, child->rect.h );
      }
      else
      {
         child->rect.x = 0;
         child->rect.y = box->rect.h;
         box->rect.w = imax16_c( box->rect.w, child->rect.w );
         box->rect.h += child->rect.h;
      }
   }

   return true;
}