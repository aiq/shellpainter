#ifndef CMDSCREEN_TERM_H
#define CMDSCREEN_TERM_H

#include "cmdscreen/apidecl.h"
#include "clingo/clingo.h"
#include "cmdscreen/csStyle.h"
#include "uiinabox/uiinabox.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

typedef bool ( *cs_set_hline )( uiPoint cord, cChars text, csStyle style );
typedef bool ( *cs_set_vline )( uiPoint cord, cChars text, csStyle style );
typedef bool ( *cs_set_cell )( uiPoint cord, cRune rune, csStyle style );

struct csTerm
{
   cs_set_hline set_hline;
   cs_set_vline set_vline;
   cs_set_cell set_cell;
   uiRect area;
   uiRect term;
};
typedef struct csTerm csTerm;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

CMDSCREEN_API bool init_term_cs( void );

CMDSCREEN_API void cleanup_term_cs( void );

/*******************************************************************************

*******************************************************************************/

CMDSCREEN_API bool set_hline_cs( uiPoint cord, cChars text, csStyle style );

CMDSCREEN_API bool set_vline_cs( uiPoint cord, cChars text, csStyle style );

#define set_cell_cs_( X, Y, Rune, Style )                                      \
   set_cell_cs( point_ui( (X), (Y) ), (Rune), (Style) )
CMDSCREEN_API bool set_cell_cs( uiPoint cord, cRune rune, csStyle style );

#define set_cursor_cs_( X, Y )                                                 \
   set_cursor_cs( point_ui( (X), (Y) ) )
CMDSCREEN_API bool set_cursor_cs( uiPoint cord );

CMDSCREEN_API bool clear_cs( void );

CMDSCREEN_API bool refresh_cs( void );

CMDSCREEN_API uiSize term_size_cs( void );

#endif