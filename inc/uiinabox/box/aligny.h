#ifndef UIINABOX_BOX_ALIGNY_H
#define UIINABOX_BOX_ALIGNY_H

#include "uiinabox/uiBox.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

UIINABOX_API extern uiBoxType const UI_AlignY;

#define uiAlignY_                                                              \
   XMAP_C_( ui_Top, 0 )                                                        \
   XMAP_C_( ui_CenterY, 1 )                                                    \
   XMAP_C_( ui_Bottom, 2 )

#define XMAP_C_( N, I ) N = I,
enum ui_AlignY { uiAlignY_ };
#undef XMAP_C_
typedef enum ui_AlignY ui_AlignY;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

UIINABOX_API uiBox aligny_ui( ui_AlignY align,
                              csStyle const* style,
                              uiBox box );

/*******************************************************************************

*******************************************************************************/

#define top_ui_( Box )                                                         \
   top_ui( NULL, (Box) )
UIINABOX_API inline uiBox top_ui( csStyle const* style, uiBox box )
{
   return aligny_ui( ui_Top, style, box );
}

#define centery_ui_( Box )                                                     \
   centery_ui( NULL, (Box) )
UIINABOX_API inline uiBox centery_ui( csStyle const* style, uiBox box )
{
   return aligny_ui( ui_CenterY, style, box );
}

#define bottom_ui_( Box )                                                      \
   bottom_ui( NULL, (Box) )
UIINABOX_API inline uiBox bottom_ui( csStyle const* style, uiBox box )
{
   return aligny_ui( ui_Bottom, style, box );
}

#endif