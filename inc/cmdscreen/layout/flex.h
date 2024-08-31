#ifndef CMDSCREEN_LAYOUT_FLEX_H
#define CMDSCREEN_LAYOUT_FLEX_H

#include "cmdscreen/csLayout.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

#define csFlexType_                                                            \
   XMAP_C_( cs_Row, 0 )                                                        \
   XMAP_C_( cs_Column, 1 )

#define XMAP_C_( N, I ) N = I,
enum cs_FlexType { csFlexType_ };
#undef XMAP_C_
typedef enum cs_FlexType cs_FlexType;

struct csFlex
{
   cs_FlexType type;
   int16_t space;
};
typedef struct csFlex csFlex;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

CMDSCREEN_API csBox fill_cs( int16_t fill, csStyle const* style, csBox box );

CMDSCREEN_API
csBox row_cs( int16_t space, csStyle const* style, csBoxes children );

CMDSCREEN_API
csBox col_cs( int16_t space, csStyle const* style, csBoxes children );

CMDSCREEN_API csBox flex_cs( cs_FlexType type,
                             int16_t space,
                             csStyle const* style,
                             csBoxes children );

#define row_layout_cs_( Space )                                                \
   flex_layout_cs( ref_c_( csFlex, ((csFlex){ cs_Row, (Space) }) ) )
#define col_layout_cs_( Space )                                                \
   flex_layout_cs( ref_c_( csFlex, ((csFlex){ cs_Column, (Space) }) ) )
CMDSCREEN_API csLayout flex_layout_cs( csFlex const* flex );

CMDSCREEN_API bool layout_flex_cs( csBox box[static 1],
                                   csLimit limit,
                                   csFlex flex,
                                   cErrorStack es[static 1] );

#endif