#ifndef CMDSCREEN_CSMSG_H
#define CMDSCREEN_CSMSG_H

#include <inttypes.h>
#include <stdbool.h>

#include "cmdscreen/apidecl.h"
#include "clingo/clingo.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

PILE_C_(
   CObject*,   // Type
   csMsgQueue  // PileType
)

/*******************************************************************************
********************************************************************* Functions
********************************************************************************
 error
*******************************************************************************/

CMDSCREEN_API bool init_msg_queue_cs( csMsgQueue queue[static 1], int64_t cap );

CMDSCREEN_API bool push_msg_cs( csMsgQueue queue[static 1], CObject* msg );

CMDSCREEN_API CObject* pull_msg_cs( csMsgQueue queue[static 1] );

#endif