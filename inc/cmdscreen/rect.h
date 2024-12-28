#ifndef CMDSCREEN_RECT_H
#define CMDSCREEN_RECT_H

#include "uiinabox/uiBox.h"
#include "cmdscreen/csStyle.h"

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

#define rect_cs_( X, Y, Color )                                                \
   rect_cs( size_ui( (X), (Y) ), (Color) )
CMDSCREEN_API uiBox rect_cs( uiSize size, cRgb24 color );

CMDSCREEN_API uiBox grow_rect_cs( cRgb24 color );

#endif