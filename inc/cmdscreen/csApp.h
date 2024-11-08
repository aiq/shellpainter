#ifndef CMDSCREEN_CSAPP_H
#define CMDSCREEN_CSAPP_H

#include "cmdscreen/csScreen.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

typedef uiBox ( *cs_layout ) ( void const* model );
typedef bool ( *cs_update ) ( void* model, CObject const* msg );

struct csApp
{
   void* model;
   cs_layout layout;
   cs_update update;
};
typedef struct csApp csApp;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

CMDSCREEN_API bool run_app_cs( csApp app, cErrorStack es[static 1] );

CMDSCREEN_API bool quit_app_cs( void );

#endif