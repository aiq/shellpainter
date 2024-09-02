#ifndef UIINABOX_ALIGNX_H
#define UIINABOX_ALIGNX_H

#include "uiinabox/uiBox.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

UIINABOX_API extern uiBoxType const UI_AlignX;

#define uiAlignX_                                                              \
   XMAP_C_( ui_Left, 0 )                                                       \
   XMAP_C_( ui_CenterX, 1 )                                                    \
   XMAP_C_( ui_Right, 2 )

#define XMAP_C_( N, I ) N = I,
enum ui_AlignX { uiAlignX_ };
#undef XMAP_C_
typedef enum ui_AlignX ui_AlignX;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

UIINABOX_API uiBox alignx_ui( ui_AlignX align,
                              uiStyle const* style,
                              uiBox box );

/*******************************************************************************

*******************************************************************************/

#define left_ui_( Box )                                                        \
   left_ui( NULL, (Box) )
UIINABOX_API inline uiBox left_ui( uiStyle const* style, uiBox box )
{
   return alignx_ui( ui_Left, style, box );
}

#define centerx_ui_( Box )                                                     \
   centerx_ui( NULL, (Box) )
UIINABOX_API inline uiBox centerx_ui( uiStyle const* style, uiBox box )
{
   return alignx_ui( ui_CenterX, style, box );
}

#define right_ui_( Box )                                                       \
   right_ui( NULL, (Box) )
UIINABOX_API inline uiBox right_ui( uiStyle const* style, uiBox box )
{
   return alignx_ui( ui_Right, style, box );
}

#endif