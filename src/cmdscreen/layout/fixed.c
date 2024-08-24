#include "cmdscreen/layout/pad.h"

#include "cmdscreen/layout/_/util.h"

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
csLayout fixed_layout_cs( csSize const* size )
{
   return (csLayout){ .i=size, .f=fixed_func };
}