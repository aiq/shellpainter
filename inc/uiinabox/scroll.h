#ifndef UIINABOX_SCROLL_H
#define UIINABOX_SCROLL_H

#include "uiinabox/uiBox.h"
#include "uiinabox/uiViewport.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

UIINABOX_API extern uiBoxType const UI_Scroll;

struct uiScroll
{
   uiBox area;
   uiViewport viewport;
};
typedef struct uiScroll uiScroll;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

UIINABOX_API uiBox scroll_ui( uiBox window, uiBox area );

UIINABOX_API bool layout_scroll_area_ui( uiBox scroll[static 1]);

UIINABOX_API bool update_scroll_ui( uiBox const box[static 1] );

#endif
