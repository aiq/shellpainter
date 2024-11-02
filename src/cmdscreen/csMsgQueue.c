#include "cmdscreen/csMsgQueue.h"

#include "clingo/clingo.h"

/*******************************************************************************
********************************************************************* Functions
********************************************************************************
 error
*******************************************************************************/

ALLOC_PILE_C_( 
   init_msg_queue_cs,   // FuncName
   csMsgQueue,          // PileType
   CObject*             // Type
)

static REALLOC_PILE_C_(
   realloc_msg_queue,   // FuncName
   csMsgQueue,          // PileType
   CObject*             // Type
)

PUT_C_(
   push_msg_cs,         // FuncName
   csMsgQueue,          // PileType
   CObject*,            // ParaType,
   do_not_deref_c_,     // DoDeref
   realloc_msg_queue    // ReallocFunc
)

CObject* pull_msg_cs( csMsgQueue queue[static 1] )
{
   if ( queue->s == 0 )
   {
      return NULL;
   }

   if ( queue->s == 1 )
   {
      queue->s = 0;
      return first_c_( *queue );
   }

   CObject* obj = first_c_( *queue );
   void* dst = queue->v;
   void* src = queue->v + 1;
   queue->s -= 1;
   memmove( dst, src, queue->s );
   return obj;
}
