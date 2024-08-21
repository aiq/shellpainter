#include "CS_MainScreen.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

PILE_IMPL_C_( 
   ColorEntry,      // Type
   ColorTable,      // PileType
   color,           // FuncSuffix
   ColorEntry,      // ParaType
   do_not_deref_c_  // DoDeref
)

PILE_IMPL_C_( 
   ColorPairEntry,  // Type
   ColorPairTable,  // PileType
   color_pair,      // FuncSuffix
   ColorPairEntry,  // ParaType
   do_not_deref_c_  // DoDeref
)

struct MainScreen CS_MainScreen = {0};

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

bool init_main_screen( void )
{
   return alloc_pile_of_color( &CS_MainScreen.colors, COLORS ) and
          alloc_pile_of_color_pair( &CS_MainScreen.colorPairs, COLOR_PAIRS );
}

void cleanup_main_screen( void )
{
   if ( CS_MainScreen.colors.v != NULL )
   {
      free( CS_MainScreen.colors.v );
   }
   if ( CS_MainScreen.colorPairs.v != NULL )
   {
      free( CS_MainScreen.colorPairs.v );
   }
}