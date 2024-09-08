#ifndef CMDSCREEN_COLORS_H
#define CMDSCREEN_COLORS_H

#include "cmdscreen/apidecl.h"
#include "clingo/clingo.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/
/*
#define csCOLOR_                                                               \
   XMAP_C_( cs_Black, 0, "black" )                                                      \
   XMAP_C_( cs_Maroon, 1, "maroon" )                                                     \
   XMAP_C_( cs_Green, 2, "green" )                                                      \
   XMAP_C_( cs_Olive, 3, "olive" )                                                      \
   XMAP_C_( cs_Navy, 4, "navy" )                                                       \
   XMAP_C_( cs_Purple, 5, "purple" )                                                     \
   XMAP_C_( cs_Teal, 6, "teal" )                                                       \
   XMAP_C_( cs_Silver, 7, "silver" )                                                     \
                                                                               \
   XMAP_C_( cs_Grey, 8, "grey" )        \
   XMAP_C_( cs_Red, 9 )         \
   XMAP_C_( cs_Lime, 10 )       \
   XMAP_C_( cs_Yellow, 11 )     \
   XMAP_C_( cs_Blue, 12 )       \
   XMAP_C_( cs_Fuchsia, 13 )        \
   XMAP_C_( cs_Aqua, 14 )       \
   XMAP_C_( cs_White, 15 )      \
   \
   XMAP_C_( cs_Grey0, 16 )      \
   XMAP_C_( cs_NavyBlue, 17 )       \
   XMAP_C_( cs_DarkBlue, 18 )       \
   XMAP_C_( cs_Blue3 )

#define XMAP_C_( N, I ) N = I,
enum cs_Color { csCOLOR_ };
#undef XMAP_C_

typedef enum o_EbmlType o_EbmlType;
*/
/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

CMDSCREEN_API cColor init_colors_cs( cColors colors );

CMDSCREEN_API bool clear_colors_cs( void );

CMDSCREEN_API cColor get_color_cs( int16_t idx );

#endif