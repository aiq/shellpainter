#ifndef UIINABOX_FIXED_H
#define UIINABOX_FIXED_H

#include "uiinabox/uiBox.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

UIINABOX_API extern uiBoxType const UI_Fixed;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

UIINABOX_API uiBox fixed_ui( uiSize size, uiContent const* content, uiBox child );

UIINABOX_API bool layout_fixed_ui( uiBox box[static 1],
                                   uiLimit limit,
                                   uiSize size,
                                   cErrorStack es[static 1] );

#endif