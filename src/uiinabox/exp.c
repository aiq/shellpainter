#include "uiinabox/exp.h"

#include "clingo/clingo.h"
#include "uiinabox/_/util.h"
#include "uiinabox/global.h"

static bool do_exp( uiBox box[static 1],
                    uiLimit limit,
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

/******************************************************************************/

static bool intl_record_box_diff( cRecorder rec[static 1],
                                  cRecorder route[static 1],
                                  uiBox const exp[static 1],
                                  uiBox const got[static 1] )
{
   if ( not eq_rect_ui( exp->rect, got->rect ) )
   {
      return jotln_c_( rec, "~= ", route, " different rect values: ",
                            "expected ", rect_tape_ui_( exp->rect ),
                            ", got ", rect_tape_ui_( got->rect ) );
   }

   if ( exp->children.s != got->children.s )
   {
      return jotln_c_( rec, "~= ", route, " different number of children: ",
                            "expected ", exp->children.s,
                            ", got ", got->children.s );
   }

   int64_t const oldPos = route->pos;
   for ( int64_t i = 0; i < exp->children.s; ++i )
   {
      if ( not write_c_( route, ":{i}", i ) )
         return false;

      uiBox const* expChild = ptr_for_c_( exp->children, i );
      uiBox const* gotChild = ptr_for_c_( got->children, i );
      if ( not intl_record_box_diff( rec, route, expChild, gotChild ) )
         return false;

      move_recorder_to_c( route, oldPos );
   }

   return true;
}

bool record_box_diff_ui( cRecorder rec[static 1],
                         uiBox const exp[static 1],
                         uiBox const oth[static 1] )
{
   cRecorder* route = &dyn_recorder_c_( 0 );
   bool res = false;
   if ( write_c_( route, "{i}", 0 ) )
   {
      res = intl_record_box_diff( rec, route, exp, oth );
   }
   free_recorder_mem_c( route );
   return res;
}
