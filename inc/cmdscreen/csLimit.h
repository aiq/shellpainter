#ifndef CMDSCREEN_CSLIMIT_H
#define CMDSCREEN_CSLIMIT_H

#include "cmdscreen/apidecl.h"
#include "uiinabox/ui_Axis.h"
#include "uiinabox/uiRect.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

CLINGO_API extern int16_t const CS_Infinity;

struct csLimit
{
   uiSize min;
   uiSize max;
};
typedef struct csLimit csLimit;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

CMDSCREEN_API inline csLimit default_limit_cs( void )
{
   return (csLimit){
      .min=size_ui( 0, 0 ),
      .max=size_ui( CS_Infinity, CS_Infinity )
   };
}

CMDSCREEN_API inline csLimit fix_limit_cs( int16_t w, int16_t h )
{
   return (csLimit){ .min=size_ui( 0, 0 ), .max=size_ui( w, h ) };
}

/*******************************************************************************

*******************************************************************************/

CMDSCREEN_API inline bool is_fix_limit_cs( csLimit limit )
{
   return limit.min.w == limit.max.w and limit.min.h == limit.max.h;
}

/*******************************************************************************

*******************************************************************************/

#define limit_height_cs_( Limit )                                              \
   limit_height_cs( (Limit), CS_Infinity )
CMDSCREEN_API inline int16_t limit_height_cs( csLimit limit, int16_t h )
{
   return clamp_c_( limit.min.h, h, limit.max.h );
}

#define limit_width_cs_( Limit )                                               \
   limit_width_cs( (Limit), CS_Infinity )
CMDSCREEN_API inline int16_t limit_width_cs( csLimit limit, int16_t w )
{
   return clamp_c_( limit.min.w, w, limit.max.w );
}

CMDSCREEN_API inline uiSize limit_size_ui( csLimit limit, uiSize size )
{
   return size_ui(
      limit_width_cs( limit, size.w ),
      limit_height_cs( limit, size.h )
   );
}

/*******************************************************************************

*******************************************************************************/

#define main_axis_cs_( Limit, Axis )                                           \
   main_axis_cs( (Limit), (Axis), CS_Infinity )
CMDSCREEN_API
inline int16_t main_axis_cs( csLimit limit, ui_Axis axis, int16_t val )
{
   if ( axis == ui_Horizontal )
   {
      return limit_width_cs( limit, val );
   }
   return limit_height_cs( limit, val );
}

#define cross_axis_cs_( Limit, Axis )                                          \
   cross_axis_cs( (Limit), (Axis), CS_Infinity )
CMDSCREEN_API
inline int16_t cross_axis_cs( csLimit limit, ui_Axis axis, int16_t val )
{
   if ( axis == ui_Horizontal )
   {
      return limit_height_cs( limit, val );
   }
   return limit_width_cs( limit, val );
}

/*******************************************************************************

*******************************************************************************/

#endif