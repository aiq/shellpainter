#include "cmdscreen/layout/none.h"

#include "cmdscreen/layout/_/util.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

static bool do_none( csBox box[static 1],
                     uiLimit limit,
                     void const* i,
                     cErrorStack es[static 1] )
{
   box->rect.w = 0;
   box->rect.h = 0;
   return true;
}
csBoxType const CS_None = {
   .desc = "none",
   .layout = &do_none
};

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

csBox none_cs( void )
{
   return (csBox){
      .data=NULL,
      .type=&CS_None,
      .style=NULL,
      .children=(csVarBoxes){ .s=0, .v=NULL }
   };
}
