#ifndef CMDSCREEN_LAYOUT_LINE_H
#define CMDSCREEN_LAYOUT_LINE_H

#include "uiinabox/uiBox.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

UIINABOX_API extern uiBoxType const CS_Line;

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
uiBox row_cs( int16_t space, csStyle const* style, uiBoxes children );

#define col_cs_( Space, Children )                                             \
   col_cs( (Space), NULL, (Children) )
UIINABOX_API
uiBox col_cs( int16_t space, csStyle const* style, uiBoxes children );

UIINABOX_API uiBox line_cs( ui_Axis axis,
                            int16_t space,
                            csStyle const* style,
                            uiBoxes children );

UIINABOX_API bool layout_line_cs( uiBox box[static 1],
                                  uiLimit limit,
                                  csLine line,
                                  cErrorStack es[static 1] );

#endif