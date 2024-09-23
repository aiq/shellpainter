#ifndef CMDSCREEN_CSSTYLE_H
#define CMDSCREEN_CSSTYLE_H

#include "cmdscreen/apidecl.h"
#include "clingo/clingo.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

struct csBorder
{
   cRune l;
   cRune r;
   cRune t;
   cRune b;
   cRune tl;
   cRune tr;
   cRune bl;
   cRune br;
};
typedef struct csBorder csBorder;

struct csStyle
{
   uint64_t f;
   uint64_t b;
};
typedef struct csStyle csStyle;

extern csStyle CS_DefaultStyle;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

#define none_style_cs_() ((csStyle){0,0})

/*******************************************************************************

*******************************************************************************/

CMDSCREEN_API csStyle base_style_cs( cRgb24 front, cRgb24 back );

#endif