#include "uiinabox/exp.h"

#include "cmdscreen/_/CS_MainScreen.h"
#include "uiinabox/_/util.h"

static bool do_exp( uiBox box[static 1],
                    uiLimit limit,
                    void const* nothing,
                    cErrorStack es[static 1] )
{
   return true;
}

uiBoxType const UI_Exp = {
   .desc = "exp",
   .layout = &do_exp
};

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

uiBox exp_cs( uiRect rect, uiBoxes children )
{
   uiBox box = box_ui( NULL, &UI_Exp, NULL, children );
   box.rect = rect;
   return box;
}
