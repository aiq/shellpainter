#include "cmdscreen/layout/exp.h"

#include "cmdscreen/_/CS_MainScreen.h"
#include "cmdscreen/layout/_/util.h"

static bool do_exp( csBox box[static 1],
                    csLimit limit,
                    void const* nothing,
                    cErrorStack es[static 1] )
{
   return true;
}

csBoxType const CS_Exp = {
   .desc = "exp",
   .layout = &do_exp
};

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

csBox exp_cs( csRect rect, csBoxes children )
{
   csBox* newChildren = alloc_array_( children.s, csBox );
   if ( newChildren == NULL ) return (csBox){0};

   for_each_c_( i, csBox const*, child, children )
   {
      newChildren[i] = *child;
   }

   return (csBox){
      .rect=rect,
      .data=NULL,
      .type=&CS_Exp,
      .style=NULL,
      .children=(csVarBoxes){ .s=children.s, .v=newChildren }
   };
}
