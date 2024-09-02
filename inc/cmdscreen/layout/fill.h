#ifndef CMDSCREEN_LAYOUT_FILL_H
#define CMDSCREEN_LAYOUT_FILL_H

#include "uiinabox/uiBox.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

UIINABOX_API extern uiBoxType const CS_Fill;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

#define fill_cs_( Fill, Child )                                                \
   fill_cs( (Fill), NULL, (Child) )
UIINABOX_API uiBox fill_cs( int16_t fill, csStyle const* style, uiBox child );

UIINABOX_API inline int16_t get_fill_value_cs( uiBox const box[static 1] )
{
   if ( box->type == &CS_Fill )
   {
      int16_t const* val = box->data;
      return *val;
   }

   return 0;
}

#endif