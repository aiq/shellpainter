#include "cmdscreen/layout/exp.h"

#include "cmdscreen/_/CS_MainScreen.h"
#include "cmdscreen/layout/_/util.h"

static bool do_exp( uiBox box[static 1],
                    uiLimit limit,
                    void const* nothing,
                    cErrorStack es[static 1] )
{
   return true;
}

uiBoxType const CS_Exp = {
   .desc = "exp",
   .layout = &do_exp
};

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

uiBox exp_cs( uiRect rect, uiBoxes children )
{
   uiBox box = box_ui( NULL, &CS_Exp, NULL, children );
   box.rect = rect;
   return box;
}
