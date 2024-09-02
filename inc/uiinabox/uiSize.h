#ifndef UIINABOX_UISIZE_H
#define UIINABOX_UISIZE_H

#include "uiinabox/ui_Axis.h"
#include "uiinabox/uiPoint.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

struct uiSize
{
   int16_t w;
   int16_t h;
};
typedef struct uiSize uiSize;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

UIINABOX_API inline uiSize size_ui( int16_t w, int16_t h )
{
   return (uiSize){ .w=w, .h=h };
}

UIINABOX_API
inline uiSize axis_size_ui( ui_Axis axis, int16_t main, int16_t cross )
{
   return ( axis == ui_Horizontal ) ? size_ui( main, cross )
                                    : size_ui( cross, main );
}

/*******************************************************************************

*******************************************************************************/

UIINABOX_API inline bool eq_size_ui( uiSize size, uiSize oth )
{
   return size.w == oth.w and size.h == oth.h;
}

UIINABOX_API inline bool is_null_size_ui( uiSize size )
{
   return size.w == 0 and size.h == 0;
}

UIINABOX_API bool write_size_ui( cRecorder rec[static 1],
                                 uiSize size,
                                 char const fmt[static 1] );

#define size_tape_ui_( Size )                                                  \
   size_tape_ui( ref_c_( uiSize, (Size) ) )
UIINABOX_API cTape size_tape_ui( uiSize const* size );

#endif