#include "cmdscreen/layout/pad.h"

#include "cmdscreen/layout/_/util.h"

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
csLayout pad_layout_cs( csPadding const* pad )
{
   return (csLayout){ .i=pad, .f=pad_func };
}