#ifndef CMDSCREEN_CSSCREEN_H
#define CMDSCREEN_CSSCREEN_H

#include <curses.h>
#include "cmdscreen/csRect.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

typedef WINDOW csScreen;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************
 main screen
*******************************************************************************/

CMDSCREEN_API csScreen* cmdscreen_cs( void );

CMDSCREEN_API void cleanup_cmdscreen_cs();

/*******************************************************************************

*******************************************************************************/

CMDSCREEN_API inline csScreen* new_screen_cs( csRect rect )
{
   return newwin( rect.h, rect.w, rect.y, rect.x );
}

CMDSCREEN_API inline csScreen* sub_screen_cs( csScreen* scr, csRect rect );

CMDSCREEN_API inline void remove_screen_cs( csScreen* scr )
{
   delwin( scr );
}

CMDSCREEN_API inline uiSize screen_size_ui( csScreen* scr )
{
   uiPoint tole;
   getbegyx( scr, tole.y, tole.x );
   uiPoint bori;
   getmaxyx( scr, bori.y, bori.x );
   return size_ui( bori.x - tole.x, bori.y - tole.y );
}

#endif