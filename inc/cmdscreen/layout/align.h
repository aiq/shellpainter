#ifndef CMDSCREEN_LAYOUT_ALIGN_H
#define CMDSCREEN_LAYOUT_ALIGN_H

#include "cmdscreen/csLayout.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

CMDSCREEN_API extern csBoxType const CS_Align;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

CMDSCREEN_API csBox align_cs( csAlignment align,
                              csStyle const* style,
                              csBox child );

CMDSCREEN_API bool layout_align_cs( csBox box[static 1],
                                    csLimit limit,
                                    csAlignment align,
                                    cErrorStack es[static 1] );

#endif