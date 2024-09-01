#ifndef CMDSCREEN_LAYOUT_INTERN_UTIL_H
#define CMDSCREEN_LAYOUT_INTERN_UTIL_H

#include "cmdscreen/csBox.h"
#include "clingo/lang/error_type.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

static inline bool has_just_single_child( char const name[static 1],
                                          csVarBoxes children,
                                          cErrorStack es[static 1] )
{
   int64_t const size = children.s;
   if ( size != 1 )
   {
      return push_text_error_c_( es, "{s:q} works just with one children, got {i}", name, size );
   }
   return true;
}

static inline int16_t alignx( cs_AlignX x, int16_t boxw, int16_t childw )
{
   if ( x == cs_CenterX )
   {
      return ( boxw / 2 ) - ( childw / 2 );
   }
   else if ( x == cs_Right )
   {
      return boxw - childw;
   }
   else  // cs_Left
   {
      return 0;
   }
}

static inline int16_t aligny( cs_AlignY y, int16_t boxh, int16_t childh )
{
   if ( y == cs_CenterY )
   {
      return ( boxh / 2 ) - ( childh / 2 );
   }
   else if ( y == cs_Bottom )
   {
      return boxh - childh;
   }
   else  // cs_Top
   {
      return 0;
   }
}

#endif