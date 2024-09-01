#ifndef CMDSCREEN_LAYOUT_ALIGNX_H
#define CMDSCREEN_LAYOUT_ALIGNX_H

#include "cmdscreen/csBox.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

CMDSCREEN_API extern csBoxType const CS_AlignX;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

CMDSCREEN_API csBox alignx_cs( cs_AlignX align,
                               csStyle const* style,
                               csBox box );

/*******************************************************************************

*******************************************************************************/

#define left_cs_( Box )                                                        \
   left_cs( NULL, (Box) )
CMDSCREEN_API inline csBox left_cs( csStyle const* style, csBox box )
{
   return alignx_cs( cs_Left, style, box );
}

#define centerx_cs_( Box )                                                     \
   centerx_cs( NULL, (Box) )
CMDSCREEN_API inline csBox centerx_cs( csStyle const* style, csBox box )
{
   return alignx_cs( cs_CenterX, style, box );
}

#define right_cs_( Box )                                                       \
   right_cs( NULL, (Box) )
CMDSCREEN_API inline csBox right_cs( csStyle const* style, csBox box )
{
   return alignx_cs( cs_Right, style, box );
}

#endif