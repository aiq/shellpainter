#ifndef CMDSCREEN_CSAXIS_H
#define CMDSCREEN_CSAXIS_H

#include "cmdscreen/apidecl.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

#define csAxis_                                                                \
   XMAP_C_( cs_Horizontal, 0 )                                                 \
   XMAP_C_( cs_Vertical, 1 )

#define XMAP_C_( N, I ) N = I,
enum cs_Axis { csAxis_ };
#undef XMAP_C_
typedef enum cs_Axis cs_Axis;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/



/*******************************************************************************

*******************************************************************************/

#endif