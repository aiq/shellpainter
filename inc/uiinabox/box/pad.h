#ifndef UIINABOX_BOX_PAD_H
#define UIINABOX_BOX_PAD_H

#include "uiinabox/uiBox.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

UIINABOX_API extern uiBoxType const UI_Pad;

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

UIINABOX_API inline
uiPadding padding_ui( int16_t left, int16_t top, int16_t right, int16_t bottom )
{
   return (uiPadding){ .left=left, .top=top, .right=right, .bottom=bottom };
}

UIINABOX_API inline uiRect pad_rect_ui( uiRect rect, uiPadding pad )
{
   return (uiRect){
      .x=rect.x + pad.left,
      .y=rect.x + pad.top,
      .w=rect.w - pad.right,
      .h=rect.h - pad.bottom
   };
}

UIINABOX_API uiLimit pad_limit_ui( uiLimit limit, uiPadding pad );

/*******************************************************************************

*******************************************************************************/

UIINABOX_API uiBox pad_ui( uiPadding pad,
                           csStyle const* style,
                           uiBox child );

UIINABOX_API bool layout_pad_ui( uiBox box[static 1],
                                 uiLimit limit,
                                 uiPadding pad,
                                 cErrorStack es[static 1] );

#endif