#include "cmdscreen/csAlignment.h"

#include <iso646.h>

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/



/*******************************************************************************

*******************************************************************************/

char const* stringify_alignment_cs( csAlignment alignment )
{
   if ( alignment.x == cs_Left and alignment.y == cs_Top )
      return "top-left";
   else if ( alignment.x == cs_CenterX and alignment.y == cs_Top )
      return "top-center";
   else if ( alignment.x == cs_Right and alignment.y == cs_Top )
      return "top-right";
   else if ( alignment.x == cs_Left and alignment.y == cs_CenterY )
      return "center-left";
   else if ( alignment.x == cs_CenterX and alignment.y == cs_CenterY )
      return "center";
   else if ( alignment.x == cs_Right and alignment.y == cs_CenterY )
      return "center-right";
   else if ( alignment.x == cs_Left and alignment.y == cs_Bottom )
      return "bottom-left";
   else if ( alignment.x == cs_CenterX and alignment.y == cs_Bottom )
      return "bottom-center";
   else
      return "bottom-right";
}

/*******************************************************************************

*******************************************************************************/