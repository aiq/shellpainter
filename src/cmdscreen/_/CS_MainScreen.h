#ifndef CMDSCREEN_INTERN_CSMAINSCREEN_H
#define CMDSCREEN_INTERN_CSMAINSCREEN_H

#include "curses.h"

#include "clingo/container/pile.h"
#include "clingo/color/cRgb.h"

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
};
extern struct MainScreen CS_MainScreen;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

bool init_main_screen( void );

void cleanup_main_screen( void );

#endif