#ifndef UIINABOX_UIRECT_H
#define UIINABOX_UIRECT_H

#include "uiinabox/uiSize.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

struct uiRect
{
   int16_t x;
   int16_t y;
   int16_t w;
   int16_t h;
};
typedef struct uiRect uiRect;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

UIINABOX_API inline uiRect rect_ui( int16_t x, int16_t y, int16_t w, int16_t h )
{
   return (uiRect){ .x=x, .y=y, .w=w, .h=h };
}

UIINABOX_API inline uiRect make_rect_ui( uiPoint topLeft, uiSize size )
{
   return (uiRect){ .x=topLeft.x, .y=topLeft.y, .w=size.w, .h=size.h };
}

UIINABOX_API inline uiRect null_rect_ui( void )
{
   return (uiRect){ .x=0, .y=0, .w=0, .h=0 };
}

/*******************************************************************************

*******************************************************************************/

UIINABOX_API inline int16_t rect_left_ui( uiRect rect )
{
   return rect.x;
}

UIINABOX_API inline int16_t rect_right_ui( uiRect rect )
{
   return rect.x + ( rect.w - 1 );
}

UIINABOX_API inline int16_t rect_top_ui( uiRect rect )
{
   return rect.y;
}

UIINABOX_API inline int16_t rect_bottom_ui( uiRect rect )
{
   return rect.y + ( rect.h - 1 );
}

/*******************************************************************************

*******************************************************************************/

UIINABOX_API inline uiPoint top_left_corner_ui( uiRect rect )
{
   return point_ui( rect.x, rect.y );
}

UIINABOX_API inline uiPoint top_right_corner_ui( uiRect rect )
{
   return point_ui( rect.x + ( rect.w - 1 ), rect.y );
}

UIINABOX_API inline uiPoint bottom_left_corner_ui( uiRect rect )
{
   return point_ui( rect.x, rect.y + ( rect.h - 1 ) );
}

UIINABOX_API inline uiPoint bottom_right_corner_ui( uiRect rect )
{
   return point_ui( rect.x + ( rect.w - 1 ), rect.y + ( rect.h - 1 ) );
}

UIINABOX_API inline uiSize rect_size_ui( uiRect rect )
{
   return size_ui( rect.w, rect.h );
}

/*******************************************************************************

*******************************************************************************/

UIINABOX_API inline bool eq_rect_ui( uiRect rect, uiRect oth )
{
   return rect.x == oth.x and
          rect.y == oth.y and
          rect.w == oth.w and
          rect.h == oth.h;
}

UIINABOX_API inline bool is_null_rect_ui( uiRect rect )
{
   return eq_rect_ui( rect, null_rect_ui() );
}

UIINABOX_API inline bool has_null_size_ui( uiRect rect )
{
   return is_null_size_ui( rect_size_ui( rect ) );
}

/*******************************************************************************

*******************************************************************************/

UIINABOX_API inline bool in_rect_ui( uiRect rect, uiPoint point )
{
   return point.x >= rect.x and
          point.y >= rect.y and
          point.x < rect.w and
          point.y < rect.h;
}

UIINABOX_API inline uiRect intersection_ui( uiRect a, uiRect b )
{
   int16_t const left = imax16_c( a.x, b.x );
   int16_t const right = imin16_c( a.x + a.w, b.x + b.w );
   int16_t const top = imax16_c( a.y, b.y );
   int16_t const bottom = imin16_c( a.y + a.h, b.y + b.h );
   if ( right < left or top > bottom )
   {
      return null_rect_ui();
   }
   return rect_ui( left, top, right - left, bottom - top );
}

UIINABOX_API inline bool overlap_ui( uiRect a, uiRect b )
{
   return not (
      rect_left_ui( a ) > rect_right_ui( b ) or
      rect_right_ui( a ) < rect_left_ui( b ) or
      rect_top_ui( a ) > rect_bottom_ui( b ) or
      rect_bottom_ui( a ) < rect_top_ui( b )
   );
}

/*******************************************************************************

*******************************************************************************/

UIINABOX_API bool write_rect_ui( cRecorder rec[static 1],
                                 uiRect rect,
                                 char const fmt[static 1] );

#define rect_tape_ui_( Rect )                                                  \
   rect_tape_ui( ref_c_( uiRect, (Rect) ) )
UIINABOX_API cTape rect_tape_ui( uiRect const* rect );

#endif