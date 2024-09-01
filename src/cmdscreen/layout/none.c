#include "cmdscreen/layout/none.h"

#include "cmdscreen/layout/_/util.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

static bool do_none( csBox box[static 1],
                     csLimit limit,
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
      .payload=NULL,
      .type=&CS_None,
      .style=NULL,
      .children=(csVarBoxes){ .s=0, .v=NULL }
   };
}

static bool none_func( csBox box[static 1],
                       csLimit limit,
                       void const* i,
                       cErrorStack es[static 1] )
{
   box->rect.w = 0;
   box->rect.h = 0;
   return true;
}
csLayout none_layout_cs( void )
{
   return (csLayout){ .i=NULL, .f=none_func };
}