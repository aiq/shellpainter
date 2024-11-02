#include "cmdscreen/term.h"

#include "termbox.h"

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

bool init_term_cs( void )
{
   tb_init();
   tb_set_output_mode( TB_OUTPUT_TRUECOLOR );
   tb_set_input_mode(TB_INPUT_ESC | TB_INPUT_MOUSE);
   return true;
}

void cleanup_term_cs( void )
{
   tb_shutdown();
}

/*******************************************************************************

*******************************************************************************/

bool set_hline_cs( uiPoint cord, cChars text, csStyle style )
{
   cRune r;
   iterate_runes_c_( itr, &r, text )
   {
      if ( not set_cell_cs( cord, r, style ) )
         return false;
      
      cord.x += 1;
   }
   return true;
}

bool set_vline_cs( uiPoint cord, cChars text, csStyle style )
{
   cRune r;
   iterate_runes_c_( itr, &r, text )
   {
      if ( not set_cell_cs( cord, r, style ) )
         return false;
      
      cord.y += 1;
   }
   return true;
}

bool set_cell_cs( uiPoint cord, cRune rune, csStyle style )
{
   uiRect rectTerm = make_rect_ui( point_ui( 0, 0 ), term_size_cs() );
   if ( not in_rect_ui( rectTerm, cord ) )
   {
      return true;
   }
   int const ret = tb_set_cell( cord.x, cord.y, rune_code_c( rune ), style.f, style.b );
   return ret == 0;
}

bool clear_cs( void )
{
   int const ret = tb_clear();
   return ret != 0;
}

bool refresh_cs( void )
{
   int const ret = tb_present();
   return ret != 0;
}

uiSize term_size_cs( void )
{
   return size_ui( int16_c_( tb_width() ), int16_c_( tb_height() ) );
}