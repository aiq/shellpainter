#ifndef CMDSCREEN_CSTEXTINPUT_H
#define CMDSCREEN_CSTEXTINPUT_H

#include <curses.h>
#include "cmdscreen/apidecl.h"
#include "uiinabox/uiinabox.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

CMDSCREEN_API extern csWidget const CS_TextInput;

struct csTextInput
{
   CStringList* options;
   int64_t selected;
};
typedef struct csTextInput csTextInput;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

CMDSCREEN_API CString* combo_box_value_cs( CSComboBox const cb[static 1] );

CMDSCREEN_API csBox combo_box_cs( CSComboBox const cb, int64_t width );

#endif