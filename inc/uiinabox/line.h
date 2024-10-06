#ifndef UIINABOX_LINE_H
#define UIINABOX_LINE_H

#include "uiinabox/uiBox.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

UIINABOX_API extern uiBoxType const UI_Line;

struct uiLine
{
   ui_Axis axis;
   int16_t space;
};
typedef struct uiLine uiLine;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

#define row_ui_( Space, Children )                                             \
   row_ui( (Space), NULL, (Children))
UIINABOX_API
uiBox row_ui( int16_t space, uiContent const* content, uiBoxes children );

#define col_ui_( Space, Children )                                             \
   col_ui( (Space), NULL, (Children) )
UIINABOX_API
uiBox col_ui( int16_t space, uiContent const* content, uiBoxes children );

UIINABOX_API uiBox line_ui( ui_Axis axis,
                            int16_t space,
                            uiContent const* content,
                            uiBoxes children );

UIINABOX_API bool layout_line_ui( uiBox box[static 1],
                                  uiLimit limit,
                                  uiLine line,
                                  cErrorStack es[static 1] );

#endif