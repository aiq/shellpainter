#include "uiinabox/line.h"

#include "uiinabox/_/util.h"
#include "uiinabox/fill.h"
#include "uiinabox/global.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

static LAYOUT_CS_( do_line, uiLine, layout_line_ui, do_deref_c_ )
uiBoxType const UI_Line = {
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

static uiLimit limit_for_fill( uiLimit limit, ui_Axis axis, int16_t max )
{
   if ( axis == ui_Horizontal )
   {
      limit.max = (uiSize){
         .w=imax16_c( limit.min.w, max ),
         .h=limit.max.h
      };
   }
   else  // ui_Vertical
   {
      limit.max = (uiSize){
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

uiBox row_ui( int16_t space, uiContent const* content, uiBoxes children )
{
   return line_ui( ui_Horizontal, space, content, children );
}

uiBox col_ui( int16_t space, uiContent const* content, uiBoxes children )
{
   return line_ui( ui_Vertical, space, content, children );
}

uiBox line_ui( ui_Axis axis,
               int16_t space,
               uiContent const* content,
               uiBoxes children )
{
   uiLine* data = alloc_ui_( uiLine );
   if ( data == NULL ) return (uiBox){0};
   else *data = (uiLine){ .axis=axis, .space=space };

   return box_ui( data, &UI_Line, content, children );
}

bool layout_line_ui( uiBox box[static 1],
                     uiLimit limit,
                     uiLine line,
                     cErrorStack es[static 1] )
{
   int16_t mainAxis = main_axis_ui_( limit, line.axis );
   int16_t fillCount = 0;
   for_each_c_( i, uiBox*, child, box->children )
   {
      if ( line.space > 0 and i != 0 )
      {
         mainAxis -= line.space;
      }
      int16_t const fill = get_fill_value_ui( child );
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
         if ( not layout_box_ui( child, limit, es ) )
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
   each_c_( uiBox*, child, box->children )
   {
      int16_t const fill = get_fill_value_ui( child );
      if ( fill == 0 )
         continue;

      float mainVal = float_c_( fill ) * part;
      mainVal = trunc_float( mainVal + diff, &diff );
      uiLimit lim = limit_for_fill( limit, line.axis, int16_c_( mainVal ) );
      if ( not layout_box_ui( child, lim, es ) )
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
   for_each_c_( i, uiBox*, child, box->children )
   {
      if ( line.axis == ui_Horizontal )
      {
         if ( line.space > 0 and i != 0 )
         {
            box->rect.w += line.space;
         }
         child->rect.x = box->rect.w;
         child->rect.y = 0;
         box->rect.w += child->rect.w;
         box->rect.h = imax16_c( box->rect.h, child->rect.h );
      }
      else
      {
         if ( line.space > 0 and i != 0 )
         {
            box->rect.h += line.space;
         }
         child->rect.x = 0;
         child->rect.y = box->rect.h;
         box->rect.w = imax16_c( box->rect.w, child->rect.w );
         box->rect.h += child->rect.h;
      }
   }

   return true;
}