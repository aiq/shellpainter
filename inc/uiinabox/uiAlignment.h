#ifndef UIINABOX_UIALIGNMENT_H
#define UIINABOX_UIALIGNMENT_H

#include "uiinabox/apidecl.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

#define uiAlignX_                                                              \
   XMAP_C_( ui_Left, 0 )                                                       \
   XMAP_C_( ui_CenterX, 1 )                                                    \
   XMAP_C_( ui_Right, 2 )

#define XMAP_C_( N, I ) N = I,
enum ui_AlignX { uiAlignX_ };
#undef XMAP_C_
typedef enum ui_AlignX ui_AlignX;

#define uiAlignY_                                                              \
   XMAP_C_( ui_Top, 0 )                                                        \
   XMAP_C_( ui_CenterY, 1 )                                                    \
   XMAP_C_( ui_Bottom, 2 )

#define XMAP_C_( N, I ) N = I,
enum ui_AlignY { uiAlignY_ };
#undef XMAP_C_
typedef enum ui_AlignY ui_AlignY;

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

#define top_left_alignment_ui_()                                               \
   alignment_ui_( ui_Left, ui_Top )

#define top_center_alignment_ui_()                                             \
   alignment_ui_( ui_CenterX, ui_Top )

#define top_right_alignment_ui_()                                              \
   alignment_ui_( ui_Right, ui_Top )

#define center_left_alignment_ui_()                                            \
   alignment_ui_( ui_Left, ui_CenterY )

#define center_alignment_ui_()                                                 \
   alignment_ui_( ui_CenterX, ui_CenterY )

#define center_right_alignment_ui_()                                           \
   alignment_ui_( ui_Right, ui_CenterY )

#define bottom_left_alignment_ui_()                                            \
   alignment_ui_( ui_Left, ui_Bottom )

#define bottom_center_alignment_ui_()                                          \
   alignment_ui_( ui_CenterX, ui_Bottom )

#define bottom_right_alignment_ui_()                                           \
   alignment_ui_( ui_Right, ui_Bottom )

/*******************************************************************************

*******************************************************************************/

UIINABOX_API char const* stringify_alignment_ui( uiAlignment alignment );

#endif