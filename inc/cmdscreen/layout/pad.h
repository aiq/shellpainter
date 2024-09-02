#ifndef CMDSCREEN_LAYOUT_PAD_H
#define CMDSCREEN_LAYOUT_PAD_H

#include "uiinabox/uiBox.h"
#include "uiinabox/uiPadding.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

UIINABOX_API extern uiBoxType const CS_Pad;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

UIINABOX_API uiBox pad_cs( uiPadding pad,
                           csStyle const* style,
                           uiBox child );

UIINABOX_API bool layout_pad_cs( uiBox box[static 1],
                                 uiLimit limit,
                                 uiPadding pad,
                                 cErrorStack es[static 1] );

#endif