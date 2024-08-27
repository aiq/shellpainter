#ifndef CMDSCREEN_LAYOUT_ALIGN_H
#define CMDSCREEN_LAYOUT_ALIGN_H

#include "cmdscreen/csLayout.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

CMDSCREEN_API csBox align_cs( csAlignment align,
                              csStyle const* style,
                              csBox child );

#define align_layout_cs_( Align )                                              \
   align_layout_cs( ref_c_( csAlignment, (Align) ) )
CMDSCREEN_API csLayout align_layout_cs( csAlignment const* align );

CMDSCREEN_API bool layout_align_cs( csBox box[static 1],
                                    csLimit limit,
                                    csAlignment align,
                                    cErrorStack es[static 1] );

#endif