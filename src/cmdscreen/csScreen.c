#include "cmdscreen/csScreen.h"

#include "_/CS_MainScreen.h"

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

csScreen* new_main_screen_cs( void )
{
   csScreen* scr = initscr();
   raw();
   noecho();
   start_color();
   init_main_screen();
   return scr;
}

void remove_main_screen_cs()
{
   cleanup_main_screen();
   endwin();
}

/*******************************************************************************

*******************************************************************************/

extern inline csScreen* new_screen_cs( csRect rect );

extern inline csSize screen_size_cs( csScreen* scr );

extern inline void remove_screen_cs( csScreen* scr );