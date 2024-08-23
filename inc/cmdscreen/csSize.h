#ifndef CMDSCREEN_CSSIZE_H
#define CMDSCREEN_CSSIZE_H

#include <curses.h>
#include "cmdscreen/cs_Axis.h"
#include "cmdscreen/csPoint.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

struct csSize
{
   int16_t w;
   int16_t h;
};
typedef struct csSize csSize;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

CMDSCREEN_API inline csSize size_cs( int16_t w, int16_t h )
{
   return (csSize){ .w=w, .h=h };
}

CMDSCREEN_API
inline csSize axis_size_cs( cs_Axis axis, int16_t main, int16_t cross )
{
   return ( axis == cs_Horizontal ) ? size_cs( main, cross )
                                    : size_cs( cross, main );
}

/*******************************************************************************

*******************************************************************************/

CMDSCREEN_API inline bool eq_size_cs( csSize size, csSize oth )
{
   return size.w == oth.w and size.h == oth.h;
}

CMDSCREEN_API inline bool is_null_size_cs( csSize size )
{
   return size.w == 0 and size.h == 0;
}

CMDSCREEN_API bool write_size_cs( cRecorder rec[static 1],
                                  csSize size,
                                  char const fmt[static 1] );

#define size_tape_cs_( Size )                                                  \
   size_tape_cs( ref_c_( csSize, (Size) ) )
CMDSCREEN_API cTape size_tape_cs( csSize const* size );

#endif