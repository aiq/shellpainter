#ifndef UIINABOX_FILL_H
#define UIINABOX_FILL_H

#include "uiinabox/uiBox.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

struct uiFill
{
   ui_Axis axis;
   int16_t val;
};
typedef struct uiFill uiFill;

UIINABOX_API extern uiBoxType const UI_Fill;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

#define fill_ui_( Val, Child )                                                 \
   fill_ui( ui_Horizontal, (Val), NULL, (Child) )
UIINABOX_API uiBox fill_ui( ui_Axis axis,
                            int16_t val,
                            uiContent const* content,
                            uiBox child );

UIINABOX_API inline bool set_fill_axis_ui( uiBox box[static 1], ui_Axis axis )
{
   if ( box->type != &UI_Fill )
      return false;

   uiFill* fill = box->data;
   fill->axis = axis;
   return true;
}

UIINABOX_API inline int16_t fill_value_ui( uiBox const box[static 1] )
{
   if ( box->type != &UI_Fill )
      return 0;

   uiFill const* fill = box->data;
   return fill->val;
}

#endif