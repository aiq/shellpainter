#include "uiinabox/uiRect.h"

#include "clingo/lang/algo.h"
#include "clingo/io/write.h"

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

extern inline uiRect rect_ui( int16_t x, int16_t y, int16_t w, int16_t h );

extern inline uiRect make_rect_ui( uiPoint topLeft, uiSize size );

extern inline uiRect null_rect_ui( void );

/*******************************************************************************

*******************************************************************************/

extern inline int16_t rect_left_ui( uiRect rect );
extern inline int16_t rect_right_ui( uiRect rect );
extern inline int16_t rect_top_ui( uiRect rect );
extern inline int16_t rect_bottom_ui( uiRect rect );

/*******************************************************************************

*******************************************************************************/

extern inline uiPoint top_left_corner_ui( uiRect rect );
extern inline uiPoint top_right_corner_ui( uiRect rect );
extern inline uiPoint bottom_left_corner_ui( uiRect rect );
extern inline uiPoint bottom_right_corner_ui( uiRect rect );

extern inline uiSize rect_size_ui( uiRect rect );

/*******************************************************************************

*******************************************************************************/

extern inline bool eq_rect_ui( uiRect rect, uiRect oth );

extern inline bool is_null_rect_ui( uiRect rect );

extern inline bool has_null_size_ui( uiRect rect );

/*******************************************************************************

*******************************************************************************/

extern inline bool in_rect_ui( uiRect rect, uiPoint point );

extern inline uiRect intersection_ui( uiRect a, uiRect b );

extern inline bool overlap_ui( uiRect a, uiRect b );

/*******************************************************************************

*******************************************************************************/

bool write_rect_ui( cRecorder rec[static 1],
                    uiRect rect,
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

static TAPE_C_( tape_func, uiRect, write_rect_ui, do_deref_c_ )
cTape rect_tape_ui( uiRect const* rect )
{
   return (cTape){ .i=rect, .f=tape_func };
}