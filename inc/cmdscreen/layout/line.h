#ifndef CMDSCREEN_LAYOUT_LINE_H
#define CMDSCREEN_LAYOUT_LINE_H

#include "uiinabox/csBox.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

UIINABOX_API extern csBoxType const CS_Line;

struct csLine
{
   ui_Axis axis;
   int16_t space;
};
typedef struct csLine csLine;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

#define row_cs_( Space, Children )                                             \
   row_cs( (Space), NULL, (Children))
UIINABOX_API
csBox row_cs( int16_t space, csStyle const* style, csBoxes children );

#define col_cs_( Space, Children )                                             \
   col_cs( (Space), NULL, (Children) )
UIINABOX_API
csBox col_cs( int16_t space, csStyle const* style, csBoxes children );

UIINABOX_API csBox line_cs( ui_Axis axis,
                            int16_t space,
                            csStyle const* style,
                            csBoxes children );

UIINABOX_API bool layout_line_cs( csBox box[static 1],
                                  uiLimit limit,
                                  csLine line,
                                  cErrorStack es[static 1] );

#endif