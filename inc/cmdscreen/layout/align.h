#ifndef CMDSCREEN_LAYOUT_ALIGN_H
#define CMDSCREEN_LAYOUT_ALIGN_H

#include "cmdscreen/csBox.h"
#include "cmdscreen/csAlignment.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

CMDSCREEN_API extern csBoxType const CS_Align;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

CMDSCREEN_API csBox align_cs( csAlignment align,
                              csStyle const* style,
                              csBox child );

CMDSCREEN_API bool layout_align_cs( csBox box[static 1],
                                    uiLimit limit,
                                    csAlignment align,
                                    cErrorStack es[static 1] );

/******************************************************************************/

#define top_left_cs_( Box )                                                    \
   top_left_cs( NULL, (Box) )
CMDSCREEN_API inline csBox top_left_cs( csStyle const* style, csBox box )
{
   return align_cs( alignment_cs_( cs_Left, cs_Top ), style, box );
}

#define top_center_cs_( Box )                                                   \
   top_center_cs( NULL, (Box) )
CMDSCREEN_API inline csBox top_center_cs( csStyle const* style, csBox box )
{
   return align_cs( alignment_cs_( cs_CenterX, cs_Top ), style, box );
}

#define top_right_cs_( Box )                                                   \
   top_right_cs( NULL, (Box) )
CMDSCREEN_API inline csBox top_right_cs( csStyle const* style, csBox box )
{
   return align_cs( alignment_cs_( cs_Right, cs_Top ), style, box );
}

/******************************************************************************/

#define center_left_cs_( Box )                                                 \
   center_left_cs( NULL, (Box) )
CMDSCREEN_API inline csBox center_left_cs( csStyle const* style, csBox box )
{
   return align_cs( alignment_cs_( cs_Left, cs_CenterY ), style, box );
}

#define center_cs_( Box )                                                      \
   center_cs( NULL, (Box) )
CMDSCREEN_API inline csBox center_cs( csStyle const* style, csBox box )
{
   return align_cs( alignment_cs_( cs_CenterX, cs_CenterY ), style, box );
}

#define center_right_cs_( Box )                                                \
   center_right_cs( NULL, (Box) )
CMDSCREEN_API inline csBox center_right_cs( csStyle const* style, csBox box )
{
   return align_cs( alignment_cs_( cs_Right, cs_CenterY ), style, box );
}

/******************************************************************************/

#define bottom_left_cs_( Box )                                                 \
   bottom_left_cs( NULL, (Box) )
CMDSCREEN_API inline csBox bottom_left_cs( csStyle const* style, csBox box )
{
   return align_cs( alignment_cs_( cs_Left, cs_Bottom ), style, box );
}

#define bottom_center_cs_( Box )                                               \
   bottom_center_cs( NULL, (Box) )
CMDSCREEN_API inline csBox bottom_center_cs( csStyle const* style, csBox box )
{
   return align_cs( alignment_cs_( cs_CenterX, cs_Bottom ), style, box );
}

#define bottom_right_cs_( Box )                                                \
   bottom_right_cs( NULL, (Box) )
CMDSCREEN_API inline csBox bottom_right_cs( csStyle const* style, csBox box )
{
   return align_cs( alignment_cs_( cs_Right, cs_Bottom ), style, box );
}

#endif