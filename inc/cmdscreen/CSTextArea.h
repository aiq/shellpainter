#ifndef CMDSCREEN_CSTEXTAREA_H
#define CMDSCREEN_CSTEXTAREA_H

#include "cmdscreen/csScreen.h"
#include "cmdscreen/CSKeyMsg.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

CMDSCREEN_API extern cMeta const CS_TextArea;

struct csTextAreaCmds
{
   cs_KeyCmd deleteBackward;
   cs_KeyCmd deleteForward;
   cs_KeyCmd moveBackward;
   cs_KeyCmd moveForward;
   cs_KeyCmd moveToLineStart;
   cs_KeyCmd moveToLineEnd;
   cs_KeyCmd moveToStart;
   cs_KeyCmd moveToEnd;
};
typedef struct csTextAreaCmds csTextAreaCmds;

struct csTextAreaInternal;
typedef struct csTextAreaInternal csTextAreaInternal;

struct CSTextArea
{
   csStyle textStyle;
   csTextAreaCmds commands;
   csTextAreaInternal* _;
};
typedef struct CSTextArea CSTextArea;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

CMDSCREEN_API CSTextArea* new_text_area_cs( void );

CMDSCREEN_API uiBox text_area_box_cs( CSTextArea const* area );

CMDSCREEN_API bool show_text_area_cs( CSTextArea const* area, uiRect term );

CMDSCREEN_API bool update_text_area_cs( CSTextArea const* area,
                                        CObject const* msg );

/*******************************************************************************

*******************************************************************************/

CMDSCREEN_API bool command_text_area_cs( CSTextArea* area, cs_KeyCmd cmd );

CMDSCREEN_API bool get_text_area_value_cs( CSTextArea const* area,
                                           cRecorder rec[static 1] );

CMDSCREEN_API bool set_text_area_value_cs( CSTextArea* area, cChars value );

#endif