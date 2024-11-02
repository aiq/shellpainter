#ifndef UIINABOX_UILIMIT_H
#define UIINABOX_UILIMIT_H

#include "uiinabox/ui_Axis.h"
#include "uiinabox/uiRect.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

UIINABOX_API extern int16_t const UI_Infinity;

struct uiLimit
{
   uiSize min;
   uiSize max;
};
typedef struct uiLimit uiLimit;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

UIINABOX_API inline uiLimit no_limit_ui( void )
{
   return (uiLimit){
      .min=size_ui( 0, 0 ),
      .max=size_ui( UI_Infinity, UI_Infinity )
   };
}

UIINABOX_API inline uiLimit fix_limit_ui( int16_t w, int16_t h )
{
   return (uiLimit){ .min=size_ui( 0, 0 ), .max=size_ui( w, h ) };
}

/*******************************************************************************

*******************************************************************************/

#define limit_height_ui_( Limit )                                              \
   limit_height_ui( (Limit), UI_Infinity )
UIINABOX_API inline int16_t limit_height_ui( uiLimit limit, int16_t h )
{
   return clamp_c_( limit.min.h, h, limit.max.h );
}

#define limit_width_ui_( Limit )                                               \
   limit_width_ui( (Limit), UI_Infinity )
UIINABOX_API inline int16_t limit_width_ui( uiLimit limit, int16_t w )
{
   return clamp_c_( limit.min.w, w, limit.max.w );
}

UIINABOX_API inline uiSize limit_size_ui( uiLimit limit, uiSize size )
{
   return size_ui(
      limit_width_ui( limit, size.w ),
      limit_height_ui( limit, size.h )
   );
}

/*******************************************************************************

*******************************************************************************/

#define main_axis_ui_( Limit, Axis )                                           \
   main_axis_ui( (Limit), (Axis), UI_Infinity )
UIINABOX_API
inline int16_t main_axis_ui( uiLimit limit, ui_Axis axis, int16_t val )
{
   if ( axis == ui_Horizontal )
   {
      return limit_width_ui( limit, val );
   }
   return limit_height_ui( limit, val );
}

#define cross_axis_ui_( Limit, Axis )                                          \
   cross_axis_ui( (Limit), (Axis), UI_Infinity )
UIINABOX_API
inline int16_t cross_axis_ui( uiLimit limit, ui_Axis axis, int16_t val )
{
   if ( axis == ui_Horizontal )
   {
      return limit_height_ui( limit, val );
   }
   return limit_width_ui( limit, val );
}

/*******************************************************************************

*******************************************************************************/

UIINABOX_API bool write_limit_ui( cRecorder rec[static 1],
                                  uiLimit limit,
                                  char const fmt[static 1] );

#define limit_tape_ui_( Limit )                                                \
   limit_tape_ui( ref_c_( uiLimit, (Limit) ) )
UIINABOX_API cTape limit_tape_ui( uiLimit const* limit );

#endif