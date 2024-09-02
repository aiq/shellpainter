#ifndef CMDSCREEN_CSRECT_H
#define CMDSCREEN_CSRECT_H

#include "cmdscreen/csSize.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

struct csRect
{
   int16_t x;
   int16_t y;
   int16_t w;
   int16_t h;
};
typedef struct csRect csRect;

SLICES_C_(
   csRect,        // Type
   csRectSlice,   // SliceType
   csVarRectSlice // VarSliceType
)

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

CMDSCREEN_API inline csRect rect_cs( int16_t x, int16_t y, int16_t w, int16_t h )
{
   return (csRect){ .x=x, .y=y, .w=w, .h=h };
}

CMDSCREEN_API inline csRect make_rect_cs( uiPoint topLeft, csSize size )
{
   return (csRect){ .x=topLeft.x, .y=topLeft.y, .w=size.w, .h=size.h };
}

CMDSCREEN_API inline csRect null_rect_cs( void )
{
   return (csRect){ .x=0, .y=0, .w=0, .h=0 };
}

/*******************************************************************************

*******************************************************************************/

CMDSCREEN_API inline uiPoint top_left_corner_cs( csRect rect )
{
   return point_ui( rect.x, rect.y );
}

CMDSCREEN_API inline uiPoint top_right_corner_cs( csRect rect )
{
   return point_ui( rect.x + ( rect.w - 1 ), rect.y );
}

CMDSCREEN_API inline uiPoint bottom_left_corner_cs( csRect rect )
{
   return point_ui( rect.x, rect.y + ( rect.h - 1 ) );
}

CMDSCREEN_API inline uiPoint bottom_right_corner_cs( csRect rect )
{
   return point_ui( rect.x + ( rect.w - 1 ), rect.y + ( rect.h - 1 ) );
}

CMDSCREEN_API inline csSize rect_size_cs( csRect rect )
{
   return size_cs( rect.w, rect.h );
}

/*******************************************************************************

*******************************************************************************/

CMDSCREEN_API inline bool eq_rect_cs( csRect rect, csRect oth )
{
   return rect.x == oth.x and
          rect.y == oth.y and
          rect.w == oth.w and
          rect.h == oth.h;
}

CMDSCREEN_API inline bool is_null_rect_cs( csRect rect )
{
   return eq_rect_cs( rect, null_rect_cs() );
}

CMDSCREEN_API inline bool has_null_size_cs( csRect rect )
{
   return is_null_size_cs( rect_size_cs( rect ) );
}

CMDSCREEN_API bool write_rect_cs( cRecorder rec[static 1],
                                  csRect rect,
                                  char const fmt[static 1] );

#define rect_tape_cs_( Rect )                                                  \
   rect_tape_cs( ref_c_( csRect, (Rect) ) )
CMDSCREEN_API cTape rect_tape_cs( csRect const* rect );

#endif