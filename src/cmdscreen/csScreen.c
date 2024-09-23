#include "cmdscreen/csScreen.h"

#include "termbox.h"
#include "_/CS_MainScreen.h"

/*******************************************************************************

*******************************************************************************/



/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

csScreen* cmdscreen_cs( void )
{
   tb_init();
   init_main_screen();
   return NULL;
}

void cleanup_cmdscreen_cs()
{
   cleanup_main_screen();
   tb_shutdown();
}

/*******************************************************************************

*******************************************************************************/

extern inline csScreen* new_screen_cs( uiRect rect );

bool set_chars_cs( uiPoint cord, cChars text, csStyle const style[static 1] )
{
   cRune r;
   iterate_runes_c_( itr, &r, text )
   {
      if ( not set_rune_cs( cord, r, style ) )
         return false;
      
      cord.x += 1;
   }
   return true;
}

bool set_rune_cs( uiPoint cord, cRune rune, csStyle const style[static 1] )
{
   int const ret = tb_set_cell( cord.x, cord.y, rune_code_c( rune ), style->f, style->b );
   return ret == 0;
}

bool clear_screen_cs( void )
{
   int const ret = tb_clear();
   return ret != 0;
}

bool refresh_screen_cs( void )
{
   int const ret = tb_present();
   return ret != 0;
}

extern inline uiSize screen_size_ui( csScreen* scr );

extern inline void remove_screen_cs( csScreen* scr );