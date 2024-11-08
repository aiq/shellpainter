#ifndef UIINABOX_COVER_H
#define UIINABOX_COVER_H

#include "uiinabox/pad.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

UIINABOX_API extern uiBoxType const UI_Cover;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

UIINABOX_API uiBox cover_ui( uiPadding pad,
                             uiContent const* content,
                             uiBox child );

UIINABOX_API bool layout_cover_ui( uiBox box[static 1],
                                   uiLimit limit,
                                   uiPadding pad,
                                   cErrorStack es[static 1] );

#endif