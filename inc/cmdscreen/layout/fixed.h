#ifndef CMDSCREEN_LAYOUT_FIXED_H
#define CMDSCREEN_LAYOUT_FIXED_H

#include "cmdscreen/csBox.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

CMDSCREEN_API extern csBoxType const CS_Fixed;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

CMDSCREEN_API csBox fixed_cs( csSize size, csStyle const* style, csBox child );

CMDSCREEN_API bool layout_fixed_cs( csBox box[static 1],
                                    csLimit limit,
                                    csSize size,
                                    cErrorStack es[static 1] );

#endif