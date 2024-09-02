#include "cmdscreen/csSize.h"

#include "clingo/lang/algo.h"
#include "clingo/io/write.h"

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

extern inline csSize size_cs( int16_t w, int16_t h );

extern inline csSize axis_size_cs( ui_Axis axis, int16_t main, int16_t cross );

/*******************************************************************************

*******************************************************************************/

extern inline bool eq_size_cs( csSize size, csSize oth );

extern inline bool is_null_size_cs( csSize size );

bool write_size_cs( cRecorder rec[static 1],
                    csSize size,
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

static TAPE_C_( tape_func, csSize, write_size_cs, do_deref_c_ )
cTape size_tape_cs( csSize const* size )
{
   return (cTape){ .i=size, .f=tape_func };
}