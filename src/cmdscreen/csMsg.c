#include "cmdscreen/csMsg.h"

#include "clingo/clingo.h"

/*******************************************************************************
********************************************************************* Functions
********************************************************************************
 error
*******************************************************************************/

csMsgData const* get_msg_data_cs( csMsg const* msg )
{
   must_exist_c_( msg );
   return msg + 1;
}

void reset_msg_stream_cs( csMsgStream stream[static 1] )
{
   
}