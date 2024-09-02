#ifndef UIINABOX_GLOBAL_H
#define UIINABOX_GLOBAL_H

#include "inttypes.h"
#include "stdbool.h"
#include "uiinabox/apidecl.h"

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

UIINABOX_API bool init_ui( void );

#define alloc_ui_( Type )                                                      \
   alloc_ui( sizeof_c_( Type ) )
UIINABOX_API void* alloc_ui( int64_t size );

#define alloc_array_ui_( Number, Type )                                        \
   alloc_array_ui( (Number), sizeof_c_( Type ) )
UIINABOX_API void* alloc_array_ui( int64_t num, int64_t size );

UIINABOX_API void cleanup_ui( void );

#endif