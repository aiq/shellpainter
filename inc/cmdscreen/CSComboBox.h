#ifndef CMDSCREEN_CSCOMBOBOX_H
#define CMDSCREEN_CSCOMBOBOX_H

#include <curses.h>
#include "cmdscreen/apidecl.h"
#include "uiinabox/uiinabox.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

struct CSComboBox
{
   CStringList* options;
   int64_t selected;
};
typedef struct CSComboBox CSComboBox;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

CMDSCREEN_API CString* combo_box_value_cs( CSComboBox const cb[static 1] );

CMDSCREEN_API uiBox combo_box_cs( CSComboBox const cb, int64_t width );

#endif