#ifndef CMDSCREEN_CSKEYMSG_H
#define CMDSCREEN_CSKEYMSG_H

#include "cmdscreen/apidecl.h"
#include "clingo/clingo.h"

/*******************************************************************************
************************************************************************* types
********************************************************************************
 basic
*******************************************************************************/

#define csKey_                                                                 \
   XMAP_C_( cs_NoKey, 0x00, "nokey" )                                          \
   XMAP_C_( cs_EnterKey, 0x0d, "enter" )                                       \
   XMAP_C_( cs_EscapeKey, 0x1b, "escape" )                                     \
   XMAP_C_( cs_BackspaceKey, 0x7f, "backspace" )                               \
   XMAP_C_( cs_RightKey, 0xffea, "right" )                                     \
   XMAP_C_( cs_LeftKey, 0xffeb, "left" )                                       \
   XMAP_C_( cs_DownKey, 0xffec, "down" )                                       \
   XMAP_C_( cs_UpKey, 0xffed, "up" )                                           \
   XMAP_C_( cs_DeleteKey, 0xfff2, "delete" )

#define XMAP_C_( N, I, Str ) N = I,
enum cs_Key { csKey_ };
#undef XMAP_C_

typedef enum cs_Key cs_Key;

CMDSCREEN_API extern cMeta const CS_KeyMsg;

struct CSKeyMsg {
   uint16_t code;
   cRune rune;
};
typedef struct CSKeyMsg CSKeyMsg;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

#define new_key_msg_cs_()                                                      \
   new_object_c_( CSKeyMsg, &CS_KeyMsg )

#define let_key_msg_cs_()                                                      \
   let_object_c_( CSKeyMsg, &CS_KeyMsg )

#define write_key_msg_cs_( Rec, Msg )                                          \
   write_key_msg_cs( (Rec), (Msg), "" )
CMDSCREEN_API bool write_key_msg_cs( cRecorder rec[static 1],
                                     CSKeyMsg const* msg,
                                     char const fmt[static 1] );

#endif