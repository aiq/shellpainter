#ifndef UIINABOX_UIPADDING_H
#define UIINABOX_UIPADDING_H

#include "uiinabox/apidecl.h"
#include "cmdscreen/csLimit.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

struct uiPadding
{
   int16_t left;
   int16_t top;
   int16_t right;
   int16_t bottom;
};
typedef struct uiPadding uiPadding;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

CMDSCREEN_API inline
uiPadding padding_ui( int16_t left, int16_t top, int16_t right, int16_t bottom )
{
   return (uiPadding){ .left=left, .top=top, .right=right, .bottom=bottom };
}

/*******************************************************************************

*******************************************************************************/

CMDSCREEN_API inline uiRect pad_rect_ui( uiRect rect, uiPadding pad )
{
   return (uiRect){
      .x=rect.x + pad.left,
      .y=rect.x + pad.top,
      .w=rect.w - pad.right,
      .h=rect.h - pad.bottom
   };
}

CMDSCREEN_API csLimit pad_limit_cs( csLimit limit, uiPadding pad );

#endif