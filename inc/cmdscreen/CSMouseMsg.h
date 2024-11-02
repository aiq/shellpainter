#ifndef CMDSCREEN_CSMOUSEMSG_H
#define CMDSCREEN_CSMOUSEMSG_H

#include "cmdscreen/apidecl.h"
#include "clingo/clingo.h"

/*******************************************************************************
************************************************************************* types
********************************************************************************
 basic
*******************************************************************************/

CMDSCREEN_API extern cMeta const CS_MouseMsg;

struct CSMouseMsg
{
   uint16_t left        :1;
   uint16_t middle      :1;
   uint16_t right       :1;
   uint16_t wheelUp     :1;
   uint16_t wheelDown   :1;
   uint16_t released    :1;
};
typedef struct CSMouseMsg CSMouseMsg;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

#define new_mouse_msg_cs_()                                                    \
   new_object_c_( CSMouseMsg, &CS_MouseMsg )

#define let_mouse_msg_cs_()                                                    \
   let_object_c_( CSMouseMsg, &CS_MouseMsg )

#define write_mouse_msg_cs_( Rec, Msg )                                        \
   write_mouse_msg_cs( (Rec), (Msg), "" )
CMDSCREEN_API bool write_mouse_msg_cs( cRecorder rec[static 1],
                                       CSMouseMsg const* msg,
                                       char const fmt[static 1] );

#endif