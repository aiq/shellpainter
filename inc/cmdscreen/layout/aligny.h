#ifndef CMDSCREEN_LAYOUT_ALIGNY_H
#define CMDSCREEN_LAYOUT_ALIGNY_H

#include "uiinabox/uiBox.h"
#include "uiinabox/uiAlignment.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

UIINABOX_API extern uiBoxType const CS_AlignY;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

UIINABOX_API uiBox aligny_cs( ui_AlignY align,
                              csStyle const* style,
                              uiBox box );

/*******************************************************************************

*******************************************************************************/

#define top_cs_( Box )                                                         \
   top_cs( NULL, (Box) )
UIINABOX_API inline uiBox top_cs( csStyle const* style, uiBox box )
{
   return aligny_cs( ui_Top, style, box );
}

#define centery_cs_( Box )                                                     \
   centery_cs( NULL, (Box) )
UIINABOX_API inline uiBox centery_cs( csStyle const* style, uiBox box )
{
   return aligny_cs( ui_CenterY, style, box );
}

#define bottom_cs_( Box )                                                      \
   bottom_cs( NULL, (Box) )
UIINABOX_API inline uiBox bottom_cs( csStyle const* style, uiBox box )
{
   return aligny_cs( ui_Bottom, style, box );
}

#endif