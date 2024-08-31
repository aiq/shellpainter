#ifndef CMDSCREEN_LAYOUT_PAD_H
#define CMDSCREEN_LAYOUT_PAD_H

#include "cmdscreen/csLayout.h"

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

CMDSCREEN_API csBox pad_cs( csPadding pad,
                            csStyle const* style,
                            csBox child );

#define pad_layout_cs_( Pad )                                                  \
   pad_layout_cs( ref_c_( csPadding, (Pad) ) )
CMDSCREEN_API csLayout pad_layout_cs( csPadding const* pad );

CMDSCREEN_API bool layout_pad_cs( csBox box[static 1],
                                  csLimit limit,
                                  csPadding pad,
                                  cErrorStack es[static 1] );

#endif