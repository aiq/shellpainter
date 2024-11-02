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

struct csTextInputCommands {
   cs_Key charForward;
   cs_Key charBackward;
   cs_Key wordForward;
   cs_Key wordBackward;
   cs_Key delWordForward;
   cs_Key delWordBackward;
   cs_Key delAfterCursor;
   cs_Key delBeforeCursor;
   cs_Key delCharBackward;
   cs_Key delCharForward;
   cs_Key lineStart;
   cs_Key lineEnd;
   cs_Key paste;
   cs_Key acceptSuggestion;
   cs_Key nextSuggestion;
   cs_Key prevSuggestio;
};
typedef struct csTextInputCommands csTextInputCommands;

struct csTextInputInternal;
typedef struct csTextInputInternal csTextInputInternal;

struct CSTextInput
{
   int64_t limit;
   int64_t width;
   CString* prompt;
   CString* placeHolder;
   csStyle style;
   csTextInputCommands commands;
   csTextInputInternal* _;
};
typedef struct CSTextInput CSTextInput;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

CSTextInput* new_text_input_cs( void );

CMDSCREEN_API uiBox text_input_box_cs( CSTextInput const* input );

CMDSCREEN_API bool show_text_input_cs( CSTextInput const* input, uiRect area );

CMDSCREEN_API bool update_text_input_cs( CSTextInput* input, CSKeyMsg const* msg );

CMDSCREEN_API cChars text_input_value_cs( CSTextInput const* input );

#endif