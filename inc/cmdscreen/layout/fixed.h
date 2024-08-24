#ifndef CMDSCREEN_LAYOUT_FIXED_H
#define CMDSCREEN_LAYOUT_FIXED_H

#include "cmdscreen/csLayout.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

CMDSCREEN_API csBox fixed_cs( csSize size,
                              csStyle const* style,
                              csBox child );

CMDSCREEN_API bool layout_fixed_cs( csBox box[static 1],
                                    csLimit limit,
                                    csSize size,
                                    cErrorStack es[static 1] );

#define fixed_layout_cs_( Size )                                               \
   fixed_layout_cs( ref_c_( csSize, (Size) ) )
CMDSCREEN_API csLayout fixed_layout_cs( csSize const* size );

#endif