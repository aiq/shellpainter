#ifndef CMDSCREEN_LAYOUT_EXP_H
#define CMDSCREEN_LAYOUT_EXP_H

#include "cmdscreen/csBox.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

CMDSCREEN_API extern csBoxType const CS_Exp;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

#define exp_cs_( Rect, ... )                                                   \
    exp_cs( (Rect), boxes_cs_( __VA_ARGS__ ) )
CMDSCREEN_API csBox exp_cs( uiRect rect, csBoxes children );

#endif