#ifndef UIINABOX_ALIGN_H
#define UIINABOX_ALIGN_H

#include "uiinabox/alignx.h"
#include "uiinabox/aligny.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

UIINABOX_API extern uiBoxType const UI_Align;

struct uiAlignment
{
   ui_AlignX x;
   ui_AlignY y;
};
typedef struct uiAlignment uiAlignment;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

#define alignment_ui_( X, Y )                                                  \
(uiAlignment){                                                                 \
   .x=(X),                                                                     \
   .y=(Y)                                                                      \
}

UIINABOX_API char const* stringify_alignment_ui( uiAlignment alignment );

/*******************************************************************************

*******************************************************************************/

UIINABOX_API uiBox align_ui( uiAlignment align,
                             uiContent const* content,
                             uiBox child );

UIINABOX_API bool layout_align_ui( uiBox box[static 1],
                                   uiLimit limit,
                                   uiAlignment align,
                                   cErrorStack es[static 1] );

/******************************************************************************/

#define top_left_ui_( Box )                                                    \
   top_left_ui( NULL, (Box) )
UIINABOX_API inline uiBox top_left_ui( uiContent const* content, uiBox box )
{
   return align_ui( alignment_ui_( ui_Left, ui_Top ), content, box );
}

#define top_center_ui_( Box )                                                   \
   top_center_ui( NULL, (Box) )
UIINABOX_API inline uiBox top_center_ui( uiContent const* content, uiBox box )
{
   return align_ui( alignment_ui_( ui_CenterX, ui_Top ), content, box );
}

#define top_right_ui_( Box )                                                   \
   top_right_ui( NULL, (Box) )
UIINABOX_API inline uiBox top_right_ui( uiContent const* content, uiBox box )
{
   return align_ui( alignment_ui_( ui_Right, ui_Top ), content, box );
}

/******************************************************************************/

#define center_left_ui_( Box )                                                 \
   center_left_ui( NULL, (Box) )
UIINABOX_API inline uiBox center_left_ui( uiContent const* content, uiBox box )
{
   return align_ui( alignment_ui_( ui_Left, ui_CenterY ), content, box );
}

#define center_ui_( Box )                                                      \
   center_ui( NULL, (Box) )
UIINABOX_API inline uiBox center_ui( uiContent const* content, uiBox box )
{
   return align_ui( alignment_ui_( ui_CenterX, ui_CenterY ), content, box );
}

#define center_right_ui_( Box )                                                \
   center_right_ui( NULL, (Box) )
UIINABOX_API inline uiBox center_right_ui( uiContent const* content, uiBox box )
{
   return align_ui( alignment_ui_( ui_Right, ui_CenterY ), content, box );
}

/******************************************************************************/

#define bottom_left_ui_( Box )                                                 \
   bottom_left_ui( NULL, (Box) )
UIINABOX_API inline uiBox bottom_left_ui( uiContent const* content, uiBox box )
{
   return align_ui( alignment_ui_( ui_Left, ui_Bottom ), content, box );
}

#define bottom_center_ui_( Box )                                               \
   bottom_center_ui( NULL, (Box) )
UIINABOX_API inline uiBox bottom_center_ui( uiContent const* content, uiBox box )
{
   return align_ui( alignment_ui_( ui_CenterX, ui_Bottom ), content, box );
}

#define bottom_right_ui_( Box )                                                \
   bottom_right_ui( NULL, (Box) )
UIINABOX_API inline uiBox bottom_right_ui( uiContent const* content, uiBox box )
{
   return align_ui( alignment_ui_( ui_Right, ui_Bottom ), content, box );
}

#endif