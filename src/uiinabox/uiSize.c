#include "uiinabox/uiSize.h"

#include "clingo/lang/algo.h"
#include "clingo/io/write.h"

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

extern inline uiSize size_ui( int16_t w, int16_t h );

extern inline uiSize axis_size_ui( ui_Axis axis, int16_t main, int16_t cross );

/*******************************************************************************

*******************************************************************************/

extern inline bool eq_size_ui( uiSize size, uiSize oth );

extern inline bool is_null_size_ui( uiSize size );

bool write_size_ui( cRecorder rec[static 1],
                    uiSize size,
                    char const fmt[static 1] )
{
   cChars format = c_c( fmt );

   if ( chars_is_any_c_( format, "", "dbg" ) )
   {
      int64_t const oldPos = rec->pos;
      bool ok = write_c_( rec, "{{ .w={i16}", size.w,
                               ", .h={i16} }", size.h );
      if ( not ok )
      {
         move_recorder_to_c( rec, oldPos );
      }
      return ok;
   }

   return set_recorder_error_c( rec, c_InvalidWriteFormat );
}

static TAPE_C_( tape_func, uiSize, write_size_ui, do_deref_c_ )
cTape size_tape_cs( uiSize const* size )
{
   return (cTape){ .i=size, .f=tape_func };
}