#ifndef CMDSCREEN_BORDER_H
#define CMDSCREEN_BORDER_H

#include "uiinabox/uiBox.h"
#include "cmdscreen/csStyle.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

struct csBorder
{
   cRune tl;
   cRune t;
   cRune tr;
   cRune l;
   cRune r;
   cRune bl;
   cRune b;
   cRune br;
   csStyle style;
};
typedef struct csBorder csBorder;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

CMDSCREEN_API csBorder* ascii_border_cs( csStyle style );

CMDSCREEN_API csBorder* thin_border_cs( csStyle style );

/*******************************************************************************

*******************************************************************************/

CMDSCREEN_API uiBox border_cs( csBorder const border[static 1], uiBox child );

CMDSCREEN_API bool show_border_cs( csBorder const* border, uiRect area );

#endif