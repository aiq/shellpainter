#include "cmdscreen/colors.h"

#include "curses.h"
#include "clingo/type/int32.h"
#include "clingo/type/uint8.h"

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

cColor get_color_cs( int16_t idx )
{
   short red;
   short green;
   short blue;
   color_content( idx, &red, &green, &blue );

   int32_t r = int32_c_( red ) * 255;
   int32_t g = int32_c_( green ) * 255;
   int32_t b = int32_c_( blue ) * 255;
   r /= 999;
   g /= 999;
   b /= 999;
   return color_c_( uint8_c_( r ), uint8_c_( g ), uint8_c_( b ), 255 );
}