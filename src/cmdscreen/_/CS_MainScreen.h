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

void cleanup_main_screen( void );

#endif