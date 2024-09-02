#ifndef UIINABOX_BOX_ALIGN_H
#define UIINABOX_BOX_ALIGN_H

#include "uiinabox/uiBox.h"
#include "uiinabox/uiAlignment.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

UIINABOX_API extern uiBoxType const UI_Align;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

UIINABOX_API uiBox align_ui( uiAlignment align,
                             csStyle const* style,
                             uiBox child );

UIINABOX_API bool layout_align_ui( uiBox box[static 1],
                                   uiLimit limit,
                                   uiAlignment align,
                                   cErrorStack es[static 1] );

/******************************************************************************/

#define top_left_ui_( Box )                                                    \
   top_left_ui( NULL, (Box) )
UIINABOX_API inline uiBox top_left_ui( csStyle const* style, uiBox box )
{
   return align_ui( alignment_ui_( ui_Left, ui_Top ), style, box );
}

#define top_center_ui_( Box )                                                   \
   top_center_ui( NULL, (Box) )
UIINABOX_API inline uiBox top_center_ui( csStyle const* style, uiBox box )
{
   return align_ui( alignment_ui_( ui_CenterX, ui_Top ), style, box );
}

#define top_right_ui_( Box )                                                   \
   top_right_ui( NULL, (Box) )
UIINABOX_API inline uiBox top_right_ui( csStyle const* style, uiBox box )
{
   return align_ui( alignment_ui_( ui_Right, ui_Top ), style, box );
}

/******************************************************************************/

#define center_left_ui_( Box )                                                 \
   center_left_ui( NULL, (Box) )
UIINABOX_API inline uiBox center_left_ui( csStyle const* style, uiBox box )
{
   return align_ui( alignment_ui_( ui_Left, ui_CenterY ), style, box );
}

#define center_ui_( Box )                                                      \
   center_ui( NULL, (Box) )
UIINABOX_API inline uiBox center_ui( csStyle const* style, uiBox box )
{
   return align_ui( alignment_ui_( ui_CenterX, ui_CenterY ), style, box );
}

#define center_right_ui_( Box )                                                \
   center_right_ui( NULL, (Box) )
UIINABOX_API inline uiBox center_right_ui( csStyle const* style, uiBox box )
{
   return align_ui( alignment_ui_( ui_Right, ui_CenterY ), style, box );
}

/******************************************************************************/

#define bottom_left_ui_( Box )                                                 \
   bottom_left_ui( NULL, (Box) )
UIINABOX_API inline uiBox bottom_left_ui( csStyle const* style, uiBox box )
{
   return align_ui( alignment_ui_( ui_Left, ui_Bottom ), style, box );
}

#define bottom_center_ui_( Box )                                               \
   bottom_center_ui( NULL, (Box) )
UIINABOX_API inline uiBox bottom_center_ui( csStyle const* style, uiBox box )
{
   return align_ui( alignment_ui_( ui_CenterX, ui_Bottom ), style, box );
}

#define bottom_right_ui_( Box )                                                \
   bottom_right_ui( NULL, (Box) )
UIINABOX_API inline uiBox bottom_right_ui( csStyle const* style, uiBox box )
{
   return align_ui( alignment_ui_( ui_Right, ui_Bottom ), style, box );
}

#endif