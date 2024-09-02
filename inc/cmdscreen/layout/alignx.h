#ifndef CMDSCREEN_LAYOUT_ALIGNX_H
#define CMDSCREEN_LAYOUT_ALIGNX_H

#include "uiinabox/uiBox.h"
#include "uiinabox/uiAlignment.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

UIINABOX_API extern uiBoxType const CS_AlignX;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

UIINABOX_API uiBox alignx_cs( ui_AlignX align,
                              csStyle const* style,
                              uiBox box );

/*******************************************************************************

*******************************************************************************/

#define left_cs_( Box )                                                        \
   left_cs( NULL, (Box) )
UIINABOX_API inline uiBox left_cs( csStyle const* style, uiBox box )
{
   return alignx_cs( ui_Left, style, box );
}

#define centerx_cs_( Box )                                                     \
   centerx_cs( NULL, (Box) )
UIINABOX_API inline uiBox centerx_cs( csStyle const* style, uiBox box )
{
   return alignx_cs( ui_CenterX, style, box );
}

#define right_cs_( Box )                                                       \
   right_cs( NULL, (Box) )
UIINABOX_API inline uiBox right_cs( csStyle const* style, uiBox box )
{
   return alignx_cs( ui_Right, style, box );
}

#endif