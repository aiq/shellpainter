#ifndef CMDSCREEN_LAYOUT_FIXED_H
#define CMDSCREEN_LAYOUT_FIXED_H

#include "uiinabox/uiBox.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

UIINABOX_API extern uiBoxType const CS_Fixed;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

UIINABOX_API uiBox fixed_cs( uiSize size, csStyle const* style, uiBox child );

UIINABOX_API bool layout_fixed_cs( uiBox box[static 1],
                                   uiLimit limit,
                                   uiSize size,
                                   cErrorStack es[static 1] );

#endif