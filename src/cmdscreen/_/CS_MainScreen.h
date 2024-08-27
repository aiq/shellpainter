#ifndef CMDSCREEN_INTERN_CSMAINSCREEN_H
#define CMDSCREEN_INTERN_CSMAINSCREEN_H

#include "curses.h"

#include "clingo/container/pile.h"
#include "clingo/color/cRgb.h"
#include "csMemArea.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

struct ColorEntry
{
   cRgb24 rgb;
   uint8_t idx;
};
typedef struct ColorEntry ColorEntry;

PILE_DEF_C_(
   ,            // LibApi,
   ColorEntry,  // Type,
   ColorTable,  // PileType,
   color,       // FuncSuffix,
   ColorEntry   // ParaType
)

struct ColorPairEntry
{
   cRgb24 front;
   cRgb24 back;
   uint8_t idx;
};
typedef struct ColorPairEntry ColorPairEntry;

PILE_DEF_C_(
   ,                // LibApi,
   ColorPairEntry,  // Type,
   ColorPairTable,  // PileType,
   color_pair,      // FuncSuffix,
   ColorPairEntry   // ParaType
)

struct MainScreen
{
   ColorTable colors;
   ColorPairTable colorPairs;
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