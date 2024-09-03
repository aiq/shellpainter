#ifndef UIINABOX_EXP_H
#define UIINABOX_EXP_H

#include "uiinabox/uiBox.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

UIINABOX_API extern uiBoxType const UI_Exp;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

#define exp_cs_( Rect, ... )                                                   \
    exp_cs( (Rect), boxes_cs_( __VA_ARGS__ ) )
UIINABOX_API uiBox exp_cs( uiRect rect, uiBoxes children );

UIINABOX_API bool record_box_diff_ui( cRecorder rec[static 1],
                                      uiBox const exp[static 1],
                                      uiBox const got[static 1] );

#define expect_layout_at_ui_( ExpPtr, GotPtr, Prefix )                         \
{                                                                              \
   cRecorder* Prefix##rec = &dyn_recorder_c_( 0 );                             \
   record_box_diff_ui( Prefix##rec, (ExpPtr), (GotPtr) );                      \
   expect_block_at_c_( Prefix##rec->pos == 0 )                                 \
   {                                                                           \
      tap_line_c_( "diff", "{rec}", Prefix##rec );                             \
   }                                                                           \
   free_recorder_mem_c( Prefix##rec );                                         \
}

#endif