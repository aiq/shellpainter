#ifndef UIINABOX_ALIGNY_H
#define UIINABOX_ALIGNY_H

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
                              uiContent const* content,
                              uiBox box );

/*******************************************************************************

*******************************************************************************/

#define top_ui_( Box )                                                         \
   top_ui( NULL, (Box) )
UIINABOX_API inline uiBox top_ui( uiContent const* content, uiBox box )
{
   return aligny_ui( ui_Top, content, box );
}

#define centery_ui_( Box )                                                     \
   centery_ui( NULL, (Box) )
UIINABOX_API inline uiBox centery_ui( uiContent const* content, uiBox box )
{
   return aligny_ui( ui_CenterY, content, box );
}

#define bottom_ui_( Box )                                                      \
   bottom_ui( NULL, (Box) )
UIINABOX_API inline uiBox bottom_ui( uiContent const* content, uiBox box )
{
   return aligny_ui( ui_Bottom, content, box );
}

#endif