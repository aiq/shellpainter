#ifndef UIINABOX_FILL_H
#define UIINABOX_FILL_H

#include "uiinabox/uiBox.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

UIINABOX_API extern uiBoxType const UI_Fill;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

#define fill_ui_( Fill, Child )                                                \
   fill_ui( (Fill), NULL, (Child) )
UIINABOX_API uiBox fill_ui( int16_t fill, uiStyle const* style, uiBox child );

UIINABOX_API inline int16_t get_fill_value_ui( uiBox const box[static 1] )
{
   if ( box->type == &UI_Fill )
   {
      int16_t const* val = box->data;
      return *val;
   }

   return 0;
}

#endif