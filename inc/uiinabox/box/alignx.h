#ifndef UIINABOX_BOX_ALIGNX_H
#define UIINABOX_BOX_ALIGNX_H

#include "uiinabox/uiBox.h"
#include "uiinabox/uiAlignment.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

UIINABOX_API extern uiBoxType const UI_AlignX;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

UIINABOX_API uiBox alignx_ui( ui_AlignX align,
                              csStyle const* style,
                              uiBox box );

/*******************************************************************************

*******************************************************************************/

#define left_ui_( Box )                                                        \
   left_ui( NULL, (Box) )
UIINABOX_API inline uiBox left_ui( csStyle const* style, uiBox box )
{
   return alignx_ui( ui_Left, style, box );
}

#define centerx_ui_( Box )                                                     \
   centerx_ui( NULL, (Box) )
UIINABOX_API inline uiBox centerx_ui( csStyle const* style, uiBox box )
{
   return alignx_ui( ui_CenterX, style, box );
}

#define right_ui_( Box )                                                       \
   right_ui( NULL, (Box) )
UIINABOX_API inline uiBox right_ui( csStyle const* style, uiBox box )
{
   return alignx_ui( ui_Right, style, box );
}

#endif