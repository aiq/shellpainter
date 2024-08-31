#ifndef CMDSCREEN_LAYOUT_LINE_H
#define CMDSCREEN_LAYOUT_LINE_H

#include "cmdscreen/csLayout.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

#define csLineType_                                                            \
   XMAP_C_( cs_Row, 0 )                                                        \
   XMAP_C_( cs_Column, 1 )

#define XMAP_C_( N, I ) N = I,
enum cs_LineType { csLineType_ };
#undef XMAP_C_
typedef enum cs_LineType cs_LineType;

struct csLine
{
   cs_LineType type;
   int16_t space;
};
typedef struct csLine csLine;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

#define fill_cs_( Fill, Child )                                                \
   fill_cs( (Fill), NULL, (Child))
CMDSCREEN_API csBox fill_cs( int16_t fill, csStyle const* style, csBox child );

#define row_cs_( Space, Children )                                             \
   row_cs( (Space), NULL, (Children))
CMDSCREEN_API
csBox row_cs( int16_t space, csStyle const* style, csBoxes children );

#define col_cs_( Space, Children )                                             \
   col_cs( (Space), NULL, (Children) )
CMDSCREEN_API
csBox col_cs( int16_t space, csStyle const* style, csBoxes children );

CMDSCREEN_API csBox line_cs( cs_LineType type,
                             int16_t space,
                             csStyle const* style,
                             csBoxes children );

#define row_layout_cs_( Space )                                                \
   line_layout_cs( ref_c_( csFlex, ((csFlex){ cs_Row, (Space) }) ) )
#define col_layout_cs_( Space )                                                \
   line_layout_cs( ref_c_( csFlex, ((csFlex){ cs_Column, (Space) }) ) )
CMDSCREEN_API csLayout line_layout_cs( csLine const* line );

CMDSCREEN_API bool layout_line_cs( csBox box[static 1],
                                   csLimit limit,
                                   csLine line,
                                   cErrorStack es[static 1] );

#endif