#ifndef CMDSCREEN_LAYOUT_LINE_H
#define CMDSCREEN_LAYOUT_LINE_H

#include "cmdscreen/csBox.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

CMDSCREEN_API extern csBoxType const CS_Line;

struct csLine
{
   cs_Axis axis;
   int16_t space;
};
typedef struct csLine csLine;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

#define row_cs_( Space, Children )                                             \
   row_cs( (Space), NULL, (Children))
CMDSCREEN_API
csBox row_cs( int16_t space, csStyle const* style, csBoxes children );

#define col_cs_( Space, Children )                                             \
   col_cs( (Space), NULL, (Children) )
CMDSCREEN_API
csBox col_cs( int16_t space, csStyle const* style, csBoxes children );

CMDSCREEN_API csBox line_cs( cs_Axis axis,
                             int16_t space,
                             csStyle const* style,
                             csBoxes children );

CMDSCREEN_API bool layout_line_cs( csBox box[static 1],
                                   csLimit limit,
                                   csLine line,
                                   cErrorStack es[static 1] );

#endif