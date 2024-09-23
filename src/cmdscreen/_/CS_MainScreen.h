#ifndef CMDSCREEN_INTERN_CSMAINSCREEN_H
#define CMDSCREEN_INTERN_CSMAINSCREEN_H

#include "termbox2.h"

#include "clingo/container/pile.h"
#include "clingo/color/cRgb.h"
#include "csMemArea.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

struct MainScreen
{
   csMemArea mem;
};
typedef struct MainScreen MainScreen;

extern MainScreen CS_MainScreen;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

bool init_main_screen( void );

#define alloc_one_( Type )                                                     \
   alloc_one( sizeof_c_( Type ) )
void* alloc_one( int64_t size );

#define alloc_array_( Number, Type )                                           \
   alloc_array( (Number), sizeof_c_( Type ) )
void* alloc_array( int64_t num, int64_t size );

void cleanup_main_screen( void );

#endif