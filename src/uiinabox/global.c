#include "uiinabox/global.h"

#include "cmdscreen/_/csMemArea.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

csMemArea memArea;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

bool init_ui( void )
{
   return init_mem_area_cs( &memArea, csBLOCK_SIZE_ );
}

void* alloc_ui( int64_t size )
{
   return area_alloc_cs( &memArea, size );
}

void* alloc_array_ui( int64_t num, int64_t size )
{
   return area_alloc_array_cs( &memArea, num, size );
}

void cleanup_ui( void )
{
   cleanup_mem_area_cs( &memArea );
}