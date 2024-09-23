#include "CS_MainScreen.h"

#include "uiinabox/uiinabox.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

MainScreen CS_MainScreen = {0};

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

bool init_main_screen( void )
{
   return init_mem_area_cs( &CS_MainScreen.mem, csBLOCK_SIZE_ ) and
          init_ui();
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
   cleanup_mem_area_cs( &CS_MainScreen.mem );
   cleanup_ui();
}