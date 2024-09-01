#ifndef CMDSCREEN_CSALIGNMENT_H
#define CMDSCREEN_CSALIGNMENT_H

#include "cmdscreen/apidecl.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

#define csAlignX_                                                              \
   XMAP_C_( cs_Left, 0 )                                                       \
   XMAP_C_( cs_CenterX, 1 )                                                    \
   XMAP_C_( cs_Right, 2 )

#define XMAP_C_( N, I ) N = I,
enum cs_AlignX { csAlignX_ };
#undef XMAP_C_
typedef enum cs_AlignX cs_AlignX;

#define csAlignY_                                                              \
   XMAP_C_( cs_Top, 0 )                                                        \
   XMAP_C_( cs_CenterY, 1 )                                                    \
   XMAP_C_( cs_Bottom, 2 )

#define XMAP_C_( N, I ) N = I,
enum cs_AlignY { csAlignY_ };
#undef XMAP_C_
typedef enum cs_AlignY cs_AlignY;

struct csAlignment
{
   cs_AlignX x;
   cs_AlignY y;
};
typedef struct csAlignment csAlignment;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

#define alignment_cs_( X, Y )                                                  \
(csAlignment){                                                                 \
   .x=(X),                                                                     \
   .y=(Y)                                                                      \
}

#define top_left_alignment_cs_()                                               \
   alignment_cs_( cs_Left, cs_Top )

#define top_center_alignment_cs_()                                             \
   alignment_cs_( cs_CenterX, cs_Top )

#define top_right_alignment_cs_()                                              \
   alignment_cs_( cs_Right, cs_Top )

#define center_left_alignment_cs_()                                            \
   alignment_cs_( cs_Left, cs_CenterY )

#define center_alignment_cs_()                                                 \
   alignment_cs_( cs_CenterX, cs_CenterY )

#define center_right_alignment_cs_()                                           \
   alignment_cs_( cs_Right, cs_CenterY )

#define bottom_left_alignment_cs_()                                            \
   alignment_cs_( cs_Left, cs_Bottom )

#define bottom_center_alignment_cs_()                                          \
   alignment_cs_( cs_CenterX, cs_Bottom )

#define bottom_right_alignment_cs_()                                           \
   alignment_cs_( cs_Right, cs_Bottom )

/*******************************************************************************

*******************************************************************************/

CMDSCREEN_API char const* stringify_alignment_cs( csAlignment alignment );

#endif