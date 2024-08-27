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
          alloc_pile_of_color_pair( &CS_MainScreen.colorPairs, COLOR_PAIRS ) and 
          init_mem_area_cs( &CS_MainScreen.mem, csBLOCK_SIZE_ );
}

void* alloc_one( int64_t size )
{
   return area_alloc_cs( &CS_MainScreen.mem, size );
}

void* alloc_array( int64_t num, int64_t size )
{
   return area_alloc_array_cs( &CS_MainScreen.mem, num, size );
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
   cleanup_mem_area_cs( &CS_MainScreen.mem );
}