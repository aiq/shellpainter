#include "cmdscreen/border.h"

#include "cmdscreen/csScreen.h"
#include "cmdscreen/term.h"

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

csBorder* ascii_border_cs( csStyle style )
{
   csBorder* border = alloc_ui_( csBorder );
   border->tl = rune_c( "+" );
   border->t  = rune_c( "-" );
   border->tr = rune_c( "+" );
   border->l  = rune_c( "|" );
   border->r  = border->l;
   border->bl = rune_c( "+" );
   border->b  = border->t;
   border->br = rune_c( "+" );
   border->style = style;
   return border;
}

csBorder* thin_border_cs( csStyle style )
{
   csBorder* border = alloc_ui_( csBorder );
   border->tl = rune_c( "┌" );
   border->t  = rune_c( "─" );
   border->tr = rune_c( "┐" );
   border->l  = rune_c( "│" );
   border->r  = border->l;
   border->bl = rune_c( "└" );
   border->b  = border->t;
   border->br = rune_c( "┘" );
   border->style = style;
   return border;
}

/*******************************************************************************

*******************************************************************************/


INTERN_SCREEN_CS_( it, csBorder, show_border_cs )
uiBox border_cs( csBorder const border[static 1], uiBox child )
{
   uiPadding pad = padding_ui( 1, 1, 1, 1 );
   return cover_ui( pad, screen_it( border ), child );
}

bool show_border_cs( csBorder const* border, uiRect area )
{
   must_exist_c_( border );
   uiPoint const tl = top_left_corner_ui( area );
   uiPoint const tr = top_right_corner_ui( area );
   uiPoint const bl = bottom_left_corner_ui( area );
   uiPoint const br = bottom_right_corner_ui( area );
   return set_cell_cs( tl, border->tl, border->style ) and
          set_hline_cs_( tl.x+1, tl.y, tr.x-tl.x, border->t, border->style ) and
          set_cell_cs( tr, border->tr, border->style ) and
          set_vline_cs_( tl.x, tl.y+1, bl.y-tl.y, border->l, border->style ) and
          set_vline_cs_( tr.x, tr.y+1, br.y-tr.y, border->r, border->style ) and
          set_cell_cs( bl, border->bl, border->style ) and
          set_hline_cs_( bl.x+1, bl.y, br.x-bl.x, border->b, border->style ) and
          set_cell_cs( br, border->br, border->style );
}