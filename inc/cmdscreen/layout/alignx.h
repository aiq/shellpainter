#ifndef CMDSCREEN_LAYOUT_ALIGNX_H
#define CMDSCREEN_LAYOUT_ALIGNX_H

#include "uiinabox/csBox.h"
#include "uiinabox/uiAlignment.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

UIINABOX_API extern csBoxType const CS_AlignX;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

UIINABOX_API csBox alignx_cs( ui_AlignX align,
                              csStyle const* style,
                              csBox box );

/*******************************************************************************

*******************************************************************************/

#define left_cs_( Box )                                                        \
   left_cs( NULL, (Box) )
UIINABOX_API inline csBox left_cs( csStyle const* style, csBox box )
{
   return alignx_cs( ui_Left, style, box );
}

#define centerx_cs_( Box )                                                     \
   centerx_cs( NULL, (Box) )
UIINABOX_API inline csBox centerx_cs( csStyle const* style, csBox box )
{
   return alignx_cs( ui_CenterX, style, box );
}

#define right_cs_( Box )                                                       \
   right_cs( NULL, (Box) )
UIINABOX_API inline csBox right_cs( csStyle const* style, csBox box )
{
   return alignx_cs( ui_Right, style, box );
}

#endif