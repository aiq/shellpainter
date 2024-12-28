#ifndef CMDSCREEN_CSTEXTINPUT_H
#define CMDSCREEN_CSTEXTINPUT_H

#include "cmdscreen/csScreen.h"
#include "cmdscreen/CSKeyMsg.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

CMDSCREEN_API extern cMeta const CS_TextInput;

struct csTextInputCmds
{
   cs_KeyCmd deleteBackward;
   cs_KeyCmd deleteForward;
   cs_KeyCmd moveBackward;
   cs_KeyCmd moveForward;
   cs_KeyCmd moveToStart;
   cs_KeyCmd moveToEnd;
};
typedef struct csTextInputCmds csTextInputCmds;

struct csTextInputInternal;
typedef struct csTextInputInternal csTextInputInternal;

struct CSTextInput
{
   int64_t limit;
   int64_t width;
   cRune unsetMarker;
   CString* prompt;
   CString* placeHolder;
   csStyle promptStyle;
   csStyle placeHolderStyle;
   csStyle textStyle;
   csTextInputCmds commands;
   csTextInputInternal* _;
};
typedef struct CSTextInput CSTextInput;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

CMDSCREEN_API CSTextInput* new_text_input_cs( void );

CMDSCREEN_API uiBox text_input_box_cs( CSTextInput const* input );

CMDSCREEN_API bool show_text_input_cs( CSTextInput const* input, uiRect area );

CMDSCREEN_API bool update_text_input_cs( CSTextInput* input, CObject const* msg );

/*******************************************************************************

*******************************************************************************/

CMDSCREEN_API bool key_cmd_text_input_cs( CSTextInput* input, cs_KeyCmd cmd );

CMDSCREEN_API bool key_msg_text_input_cs( CSTextInput* input, CSKeyMsg const* msg );

/*******************************************************************************

*******************************************************************************/

CMDSCREEN_API int64_t text_input_pos_cs( CSTextInput const* input );

CMDSCREEN_API bool get_text_input_value_cs( CSTextInput const* input,
                                            cRecorder rec[static 1] );

#endif