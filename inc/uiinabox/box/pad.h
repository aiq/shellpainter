#ifndef UIINABOX_BOX_PAD_H
#define UIINABOX_BOX_PAD_H

#include "uiinabox/uiBox.h"
#include "uiinabox/uiPadding.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

UIINABOX_API extern uiBoxType const UI_Pad;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

UIINABOX_API uiBox pad_ui( uiPadding pad,
                           csStyle const* style,
                           uiBox child );

UIINABOX_API bool layout_pad_ui( uiBox box[static 1],
                                 uiLimit limit,
                                 uiPadding pad,
                                 cErrorStack es[static 1] );

#endif