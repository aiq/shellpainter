#include "cmdscreen/layout/pad.h"

#include "cmdscreen/layout/_/util.h"

csBox align_cs( csAlignment align,
                csStyle const* style,
                csBox child )
{
   return (csBox){};
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
csLayout align_layout_cs( csAlignment const* align )
{
   return (csLayout){ .i=align, .f=align_func };
}