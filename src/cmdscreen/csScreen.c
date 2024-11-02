#include "cmdscreen/csScreen.h"

#include "_/CS_MainScreen.h"
#include "cmdscreen/term.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/



/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

csScreen* screen_cs( void const* i, cs_show f )
{
   csScreen* screen = alloc_ui_( csScreen );
   if ( screen != NULL )
   {
      *screen = (csScreen){ .i=i, .f=f };
   }
   return screen;
}

csScreen* cmdscreen_cs( void )
{
   set_locale_c( LC_ALL, "en_US.UTF-8" );
   init_term_cs();
   init_main_screen();
   return NULL;
}

void cleanup_cmdscreen_cs()
{
   cleanup_main_screen();
   cleanup_term_cs();
}
