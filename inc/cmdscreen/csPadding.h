#ifndef CMDSCREEN_CSPADDING_H
#define CMDSCREEN_CSPADDING_H

#include "cmdscreen/csLimit.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

struct csPadding
{
   int16_t left;
   int16_t top;
   int16_t right;
   int16_t bottom;
};
typedef struct csPadding csPadding;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

CMDSCREEN_API inline
csPadding padding_cs( int16_t left, int16_t top, int16_t right, int16_t bottom )
{
   return (csPadding){ .left=left, .top=top, .right=right, .bottom=bottom };
}

/*******************************************************************************

*******************************************************************************/

CMDSCREEN_API inline uiRect pad_rect_ui( uiRect rect, csPadding pad )
{
   return (uiRect){
      .x=rect.x + pad.left,
      .y=rect.x + pad.top,
      .w=rect.w - pad.right,
      .h=rect.h - pad.bottom
   };
}

CMDSCREEN_API csLimit pad_limit_cs( csLimit limit, csPadding pad );

#endif