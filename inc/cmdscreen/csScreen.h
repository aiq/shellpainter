#ifndef CMDSCREEN_CSSCREEN_H
#define CMDSCREEN_CSSCREEN_H

#include "cmdscreen/apidecl.h"
#include "cmdscreen/csStyle.h"
#include "uiinabox/uiinabox.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

#define SHOW_CS_( FuncName, Type, ShowFunc )                                   \
bool FuncName( void const* i, uiRect area )                                    \
{                                                                              \
   must_exist_c_( i );                                                         \
   Type const* val = i;                                                        \
   return ShowFunc( val, area );                                           \
}

#define INTERN_SCREEN_CS_( FuncSuffix, Type, ShowFunc )                        \
static bool show_##FuncSuffix( void const* i, uiRect area )                    \
{                                                                              \
   must_exist_c_( i );                                                         \
   Type const* val = i;                                                        \
   return ShowFunc( val, area );                                               \
}                                                                              \
static csScreen* screen_##FuncSuffix( Type const* i )                          \
{                                                                              \
   return screen_cs( i, show_##FuncSuffix );                                   \
}

typedef bool ( *cs_show )( void const* i, uiRect area );

struct csScreen
{
   void const* i;
   cs_show f;
};
typedef struct csScreen csScreen;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

CMDSCREEN_API csScreen* screen_cs( void const* i, cs_show f );

CMDSCREEN_API csScreen* cmdscreen_cs( void );

CMDSCREEN_API void cleanup_cmdscreen_cs();

#endif