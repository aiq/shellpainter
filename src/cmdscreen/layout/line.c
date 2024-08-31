#include "cmdscreen/layout/line.h"

#include "cmdscreen/_/CS_MainScreen.h"
#include "cmdscreen/layout/_/util.h"

/*******************************************************************************

*******************************************************************************/

static float trunc_float( float f, float* diff )
{
   float res = truncf( f );
   *diff = f - res;
   return res;
}

static csLimit limit_for_fill( csLimit limit, cs_LineType type, int16_t max )
{
   if ( type == cs_Row )
   {
      limit.max = (csSize){
         .w=imax16_c( limit.min.w, max ),
         .h=limit.max.h
      };
   }
   else  // cs_Column
   {
      limit.max = (csSize){
         .w=limit.max.w,
         .h=imax16_c( limit.max.h, max )
      };
   }

   return limit;
}

static bool fill_func( csBox box[static 1],
                         csLimit limit,
                         void const* nothing,
                         cErrorStack es[static 1] )
{
   if ( not has_just_single_child( "fill", box->children, es ) )
   {
      return false;
   }
   box->rect.x = 0;
   box->rect.y = 0;
   box->rect.w = limit_width_cs_( limit );
   box->rect.h = limit_height_cs_( limit );

   csBox* child = box->children.v;
   if ( not layout_box_cs( child, limit, es ) )
   {
      return false;
   }

   child->rect.x = 0;
   child->rect.y = 0;

   return true;
}

static csLayout fill_layout( void )
{
   return (csLayout){ .i=NULL, .f=fill_func };
}

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

csBox fill_cs( int16_t fill, csStyle const* style, csBox child )
{
   csBox* newChild = alloc_one_( csBox );
   if ( newChild == NULL ) return (csBox){0};
   else *newChild = child;

   return (csBox){
      .layout=fill_layout(  ),
      .fill=fill,
      .style=style,
      .children=(csVarBoxes){ .s=1, .v=newChild }
   };
}

csBox row_cs( int16_t space, csStyle const* style, csBoxes children )
{
   return line_cs( cs_Row, space, style, children );
}

csBox col_cs( int16_t space, csStyle const* style, csBoxes children )
{
   return line_cs( cs_Column, space, style, children );
}

csBox line_cs( cs_LineType type,
               int16_t space,
               csStyle const* style,
               csBoxes children )
{
   csLine* newLine = alloc_one_( csLine );
   if ( newLine == NULL ) return (csBox){0};
   else *newLine = (csLine){ .type=type, .space=space };

   csBox* newChildren = alloc_array_( children.s, csBox );
   if ( newChildren == NULL ) return (csBox){0};

   for_each_c_( i, csBox const*, child, children )
   {
      newChildren[i] = *child;
   }

   return (csBox){
      .layout=line_layout_cs( newLine ),
      .style=style,
      .children=(csVarBoxes){ .s=children.s, .v=newChildren }
   };
}

static LAYOUT_CS_( line_func, csLine, layout_line_cs, do_deref_c_ )
csLayout line_layout_cs( csLine const* line )
{
   return (csLayout){ .i=line, .f=line_func };
}

bool layout_line_cs( csBox box[static 1],
                     csLimit limit,
                     csLine line,
                     cErrorStack es[static 1] )
{
   cs_Axis const axis = ( line.type == cs_Row ) ? cs_Horizontal
                                                : cs_Vertical;
   int16_t mainAxis = main_axis_cs_( limit, axis );
   int16_t crossAxis = cross_axis_cs_( limit, axis );
   int16_t fillCount = 0;
   each_c_( csBox*, child, box->children )
   {
      if ( child->fill > 0 )
      {
         int16_t fillPart = child->fill;
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
         int16_t const mainPart = ( line.type == cs_Row ) ? child->rect.w
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
      if ( child->fill == 0 )
         continue;

      float mainVal = float_c_( child->fill ) * part;
      mainVal = trunc_float( mainVal + diff, &diff );
      csLimit lim = limit_for_fill( limit, line.type, int16_c_( mainVal ) );
      if ( not layout_box_cs( child, lim, es ) )
      {
         return false;
      }
      int16_t const mainPart = ( line.type == cs_Row ) ? child->rect.w
                                                       : child->rect.h;
      if ( mainAxis < 0 )
      {
         return push_lit_error_c( es, "not engouh space on the main axis" );
      }
   }

   box->rect.w = 0;
   box->rect.h = 0;
   each_c_( csBox*, child, box->children )
   {
      if ( line.type == cs_Row )
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