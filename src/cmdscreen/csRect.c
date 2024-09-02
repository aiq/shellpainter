#include "cmdscreen/csRect.h"

#include "clingo/lang/algo.h"
#include "clingo/io/write.h"

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

extern inline csRect rect_cs( int16_t x, int16_t y, int16_t w, int16_t h );

extern inline csRect make_rect_cs( uiPoint topLeft, uiSize size );

extern inline csRect null_rect_cs( void );

/*******************************************************************************

*******************************************************************************/

extern inline uiPoint top_left_corner_cs( csRect rect );

extern inline uiPoint top_right_corner_cs( csRect rect );

extern inline uiPoint bottom_left_corner_cs( csRect rect );

extern inline uiPoint bottom_right_corner_cs( csRect rect );

extern inline uiSize rect_size_ui( csRect rect );

/*******************************************************************************

*******************************************************************************/

extern inline bool eq_rect_cs( csRect rect, csRect oth );

extern inline bool is_null_rect_cs( csRect rect );

extern inline bool has_null_size_ui( csRect rect );

bool write_rect_cs( cRecorder rec[static 1],
                                  csRect rect,
                                  char const fmt[static 1] )
{
   cChars format = c_c( fmt );

   if ( chars_is_any_c_( format, "", "dbg" ) )
   {
      int64_t const oldPos = rec->pos;
      bool ok = write_c_( rec, "{{ .x={i16}", rect.x,
                               ", .y={i16}", rect.y,
                               ", .w={i16}", rect.w,
                               ", .h={i16} }", rect.h );
      if ( not ok )
      {
         move_recorder_to_c( rec, oldPos );
      }
      return ok;
   }

   return set_recorder_error_c( rec, c_InvalidWriteFormat );
}

static TAPE_C_( tape_func, csRect, write_rect_cs, do_deref_c_ )
cTape rect_tape_cs( csRect const* rect )
{
   return (cTape){ .i=rect, .f=tape_func };
}