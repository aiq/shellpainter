#ifndef UIINABOX_BOX_ALIGNY_H
#define UIINABOX_BOX_ALIGNY_H

#include "uiinabox/uiBox.h"
#include "uiinabox/uiAlignment.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

UIINABOX_API extern uiBoxType const UI_AlignY;

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