#ifndef CMDSCREEN_LAYOUT_ALIGN_H
#define CMDSCREEN_LAYOUT_ALIGN_H

#include "uiinabox/uiBox.h"
#include "uiinabox/uiAlignment.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

UIINABOX_API extern uiBoxType const CS_Align;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

UIINABOX_API uiBox align_cs( uiAlignment align,
                             csStyle const* style,
                             uiBox child );

UIINABOX_API bool layout_align_cs( uiBox box[static 1],
                                   uiLimit limit,
                                   uiAlignment align,
                                   cErrorStack es[static 1] );

/******************************************************************************/

#define top_left_cs_( Box )                                                    \
   top_left_cs( NULL, (Box) )
UIINABOX_API inline uiBox top_left_cs( csStyle const* style, uiBox box )
{
   return align_cs( alignment_ui_( ui_Left, ui_Top ), style, box );
}

#define top_center_cs_( Box )                                                   \
   top_center_cs( NULL, (Box) )
UIINABOX_API inline uiBox top_center_cs( csStyle const* style, uiBox box )
{
   return align_cs( alignment_ui_( ui_CenterX, ui_Top ), style, box );
}

#define top_right_cs_( Box )                                                   \
   top_right_cs( NULL, (Box) )
UIINABOX_API inline uiBox top_right_cs( csStyle const* style, uiBox box )
{
   return align_cs( alignment_ui_( ui_Right, ui_Top ), style, box );
}

/******************************************************************************/

#define center_left_cs_( Box )                                                 \
   center_left_cs( NULL, (Box) )
UIINABOX_API inline uiBox center_left_cs( csStyle const* style, uiBox box )
{
   return align_cs( alignment_ui_( ui_Left, ui_CenterY ), style, box );
}

#define center_cs_( Box )                                                      \
   center_cs( NULL, (Box) )
UIINABOX_API inline uiBox center_cs( csStyle const* style, uiBox box )
{
   return align_cs( alignment_ui_( ui_CenterX, ui_CenterY ), style, box );
}

#define center_right_cs_( Box )                                                \
   center_right_cs( NULL, (Box) )
UIINABOX_API inline uiBox center_right_cs( csStyle const* style, uiBox box )
{
   return align_cs( alignment_ui_( ui_Right, ui_CenterY ), style, box );
}

/******************************************************************************/

#define bottom_left_cs_( Box )                                                 \
   bottom_left_cs( NULL, (Box) )
UIINABOX_API inline uiBox bottom_left_cs( csStyle const* style, uiBox box )
{
   return align_cs( alignment_ui_( ui_Left, ui_Bottom ), style, box );
}

#define bottom_center_cs_( Box )                                               \
   bottom_center_cs( NULL, (Box) )
UIINABOX_API inline uiBox bottom_center_cs( csStyle const* style, uiBox box )
{
   return align_cs( alignment_ui_( ui_CenterX, ui_Bottom ), style, box );
}

#define bottom_right_cs_( Box )                                                \
   bottom_right_cs( NULL, (Box) )
UIINABOX_API inline uiBox bottom_right_cs( csStyle const* style, uiBox box )
{
   return align_cs( alignment_ui_( ui_Right, ui_Bottom ), style, box );
}

#endif