#ifndef CMDSCREEN_LAYOUT_FILL_H
#define CMDSCREEN_LAYOUT_FILL_H

#include "cmdscreen/csBox.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

CMDSCREEN_API extern csBoxType const CS_Fill;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

#define fill_cs_( Fill, Child )                                                \
   fill_cs( (Fill), NULL, (Child))
CMDSCREEN_API csBox fill_cs( int16_t fill, csStyle const* style, csBox child );

CMDSCREEN_API inline int16_t get_fill_value_cs( csBox const box[static 1] )
{
   if ( box->type == &CS_Fill )
   {
      int16_t const* val = box->payload;
      return *val;
   }

   return 0;
}

#endif