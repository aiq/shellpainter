#include "cmdscreen/CSMouseMsg.h"

/*******************************************************************************
************************************************************************* types
********************************************************************************
 basic
*******************************************************************************/

static inline void cleanup( void* instance ) {}

cMeta const CS_MouseMsg = {
   .desc = stringify_c_( CS_MouseMsg ),
   .cleanup = &cleanup
};

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

bool write_mouse_msg_cs( cRecorder rec[static 1],
                         CSMouseMsg const* msg,
                         char const fmt[static 1] )
{
   must_exist_c_( msg );

   return write_c_( rec, "mouse msg ",
                    "=> left:{bool}", msg->left,
                    " / middle:{bool}", msg->middle,
                    " / right:{bool}", msg->right,
                    " / wheelUp:{bool}", msg->wheelUp,
                    " / wheelDown:{bool}", msg->wheelDown,
                    " / released:{bool}", msg->released );
}
