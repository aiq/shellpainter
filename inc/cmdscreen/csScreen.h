#ifndef CMDSCREEN_CSSCREEN_H
#define CMDSCREEN_CSSCREEN_H

#include "cmdscreen/apidecl.h"
#include "cmdscreen/csStyle.h"
#include "uiinabox/uiRect.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

typedef void csScreen;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************
 main screen
*******************************************************************************/

CMDSCREEN_API csScreen* cmdscreen_cs( void );

CMDSCREEN_API void cleanup_cmdscreen_cs();

/*******************************************************************************

*******************************************************************************/

CMDSCREEN_API bool set_chars_cs( uiPoint cord, cChars text, csStyle const style[static 1] );

CMDSCREEN_API bool set_rune_cs( uiPoint cord, cRune rune, csStyle const style[static 1] );

CMDSCREEN_API bool clear_screen_cs( void );

CMDSCREEN_API bool refresh_screen_cs( void );

CMDSCREEN_API inline csScreen* new_screen_cs( uiRect rect )
{
   return NULL;
}

CMDSCREEN_API inline csScreen* sub_screen_cs( csScreen* scr, uiRect rect );

CMDSCREEN_API inline void remove_screen_cs( csScreen* scr )
{
}

CMDSCREEN_API inline uiSize screen_size_ui( csScreen* scr )
{
   return size_ui( 0, 0 );
}

#endif