#include "cmdscreen/rect.h"

#include "cmdscreen/csScreen.h"
#include "cmdscreen/term.h"

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

static bool show_rect( cRgb24 const* color, uiRect area )
{
   must_exist_c_( color );
   
   cRune const space = rune_c( " " );
   csStyle const style = base_style_cs( *color, *color );
   uiPoint const tl = top_left_corner_ui( area );
   uiPoint const br = bottom_right_corner_ui( area );
   for ( int16_t y = tl.y; y < br.y; ++y )
   {
      if ( not set_hline_cs_( tl.x, y, br.x - tl.x, space, style ) )
      {
         return false;
      }
   }

   return true;
}

INTERN_SCREEN_CS_( it, cRgb24, show_rect )
uiBox rect_cs( uiSize size, cRgb24 color )
{
   cRgb24* screen = alloc_ui_( cRgb24 );
   if ( screen == NULL ) return (uiBox){0};
   else *screen = color;

   return fixed_ui( size, screen_it( screen ), none_ui() );
}

uiBox grow_rect_cs( cRgb24 color )
{
   return rect_cs_( UI_Grow, UI_Grow, color );
}
