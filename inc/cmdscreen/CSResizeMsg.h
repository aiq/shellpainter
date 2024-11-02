#ifndef CMDSCREEN_CSRESIZEMSG_H
#define CMDSCREEN_CSRESIZEMSG_H

#include "cmdscreen/apidecl.h"
#include "clingo/clingo.h"

/*******************************************************************************
************************************************************************* types
********************************************************************************
 basic
*******************************************************************************/

CMDSCREEN_API extern cMeta const CS_ResizeMsg;

struct CSResizeMsg
{
   int16_t w;
   int16_t h;
};
typedef struct CSResizeMsg CSResizeMsg;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

#define new_resize_msg_cs_()                                                   \
   new_object_c_( CSResizeMsg, &CS_ResizeMsg )

#define let_resize_msg_cs_()                                                   \
   let_object_c_( CSResizeMsg, &CS_ResizeMsg )

#define write_resize_msg_cs_( Rec, Msg )                                       \
   write_resize_msg_cs( (Rec), (Msg), "" )
CMDSCREEN_API bool write_resize_msg_cs( cRecorder rec[static 1],
                                        CSResizeMsg const* msg,
                                        char const fmt[static 1] );

#endif