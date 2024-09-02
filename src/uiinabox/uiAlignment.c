#include "uiinabox/uiAlignment.h"

#include <iso646.h>

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/



/*******************************************************************************

*******************************************************************************/

char const* stringify_alignment_ui( uiAlignment alignment )
{
   if ( alignment.x == ui_Left and alignment.y == ui_Top )
      return "top-left";
   else if ( alignment.x == ui_CenterX and alignment.y == ui_Top )
      return "top-center";
   else if ( alignment.x == ui_Right and alignment.y == ui_Top )
      return "top-right";
   else if ( alignment.x == ui_Left and alignment.y == ui_CenterY )
      return "center-left";
   else if ( alignment.x == ui_CenterX and alignment.y == ui_CenterY )
      return "center";
   else if ( alignment.x == ui_Right and alignment.y == ui_CenterY )
      return "center-right";
   else if ( alignment.x == ui_Left and alignment.y == ui_Bottom )
      return "bottom-left";
   else if ( alignment.x == ui_CenterX and alignment.y == ui_Bottom )
      return "bottom-center";
   else
      return "bottom-right";
}

/*******************************************************************************

*******************************************************************************/