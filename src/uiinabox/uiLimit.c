#include "uiinabox/uiLimit.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

int16_t const UI_Infinity = INT16_MAX;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

extern inline uiLimit no_limit_ui( void );

extern inline uiLimit fix_limit_ui( int16_t w, int16_t h );

/*******************************************************************************

*******************************************************************************/

extern inline int16_t limit_height_ui( uiLimit limit, int16_t h );

extern inline int16_t limit_width_ui( uiLimit limit, int16_t w );

extern inline uiSize limit_size_ui( uiLimit limit, uiSize size );

/*******************************************************************************

*******************************************************************************/

extern inline uiRect set_rect_size_ui( uiRect rect, uiSize size );

/*******************************************************************************

*******************************************************************************/

extern inline int16_t main_axis_ui( uiLimit limit, ui_Axis axis, int16_t val );

extern inline int16_t cross_axis_ui( uiLimit limit, ui_Axis axis, int16_t val );

/*******************************************************************************

*******************************************************************************/

bool write_limit_ui( cRecorder rec[static 1],
                     uiLimit limit,
                     char const fmt[static 1] )
{
   cChars format = c_c( fmt );

   if ( chars_is_any_c_( format, "", "dbg" ) )
   {
      int64_t const oldPos = rec->pos;
      bool ok = write_c_( rec, "{{ .w=[{i16},{i16}]", limit.min.w, limit.max.w,
                               ", .h=[{i16},{i16}] }", limit.min.h, limit.max.h );
      if ( not ok )
      {
         move_recorder_to_c( rec, oldPos );
      }
      return ok;
   }

   return set_recorder_error_c( rec, c_InvalidWriteFormat );
}

static TAPE_C_( tape_func, uiLimit, write_limit_ui, do_deref_c_ )
cTape limit_tape_ui( uiLimit const* limit )
{
   return (cTape){ .i=limit, .f=tape_func };
}
