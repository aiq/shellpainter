#ifndef CMDSCREEN_CSMSG_H
#define CMDSCREEN_CSMSG_H

#include <inttypes.h>
#include <stdbool.h>

#include "cmdscreen/apidecl.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

typedef void csMsgData;

struct csMsg;
typedef struct csMsg csMsg;

struct csMsgType
{
   char const* desc;
};
typedef struct csMsgType csMsgType;

struct csMsg
{
   csMsgType const* type;
};

struct csMsgStream
{
   int64_t space;
   void* mem;
};
typedef struct csMsgStream csMsgStream;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************
 error
*******************************************************************************/

CMDSCREEN_API bool push_msg_cs( csMsgStream stream[static 1],
                                csMsgType const type[static 1],
                                csMsgData const* data,
                                int64_t dataSize );

CMDSCREEN_API csMsgData const* get_msg_data_cs( csMsg const* msg );

CMDSCREEN_API void reset_msg_stream_cs( csMsgStream stream[static 1] );

#endif