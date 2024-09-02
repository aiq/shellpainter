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
   csBox box = box_cs( NULL, &CS_Exp, NULL, children );
   box.rect = rect;
   return box;
}
