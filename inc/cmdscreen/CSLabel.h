#ifndef CMDSCREEN_CSLABEL_H
#define CMDSCREEN_CSLABEL_H

#include "cmdscreen/csScreen.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

CMDSCREEN_API extern cMeta const CS_Label;

struct CSLabel
{
   CString* text;
   csStyle style;
   uiAlignment alignment;
};
typedef struct CSLabel CSLabel;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

#define new_label_cs_()                                                        \
   new_object_c_( CSLabel, &CS_Label )

#define let_label_o_()                                                         \
   let_object_c_( CSLabel, &CS_Label )

CMDSCREEN_API void mimic_label_cs( CSLabel label[static 1],
                                   CSLabel const src[static 1] );

CMDSCREEN_API uiBox label_box_cs( CSLabel const* label );

CMDSCREEN_API bool show_label_cs( CSLabel const* label, uiRect area );

#endif