#ifndef CMDSCREEN_LAYOUT_ALIGNY_H
#define CMDSCREEN_LAYOUT_ALIGNY_H

#include "cmdscreen/csBox.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

CMDSCREEN_API extern csBoxType const CS_AlignY;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

CMDSCREEN_API csBox aligny_cs( cs_AlignY align,
                               csStyle const* style,
                               csBox box );

/*******************************************************************************

*******************************************************************************/

#define top_cs_( Box )                                                         \
   top_cs( NULL, (Box) )
CMDSCREEN_API inline csBox top_cs( csStyle const* style, csBox box )
{
   return aligny_cs( cs_Top, style, box );
}

#define centery_cs_( Box )                                                     \
   centery_cs( NULL, (Box) )
CMDSCREEN_API inline csBox centery_cs( csStyle const* style, csBox box )
{
   return aligny_cs( cs_CenterY, style, box );
}

#define bottom_cs_( Box )                                                      \
   bottom_cs( NULL, (Box) )
CMDSCREEN_API inline csBox bottom_cs( csStyle const* style, csBox box )
{
   return aligny_cs( cs_Bottom, style, box );
}

#endif