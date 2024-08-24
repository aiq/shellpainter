#ifndef CMDSCREEN_LAYOUT_INTERN_UTIL_H
#define CMDSCREEN_LAYOUT_INTERN_UTIL_H

#include "cmdscreen/csLayout.h"
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


#endif