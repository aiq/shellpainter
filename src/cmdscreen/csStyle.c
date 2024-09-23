#include "cmdscreen/csStyle.h"

/*******************************************************************************

*******************************************************************************/

static inline uint32_t rgb24_as_uint32( cRgb24 rgb )
{
   union { uint32_t i; uint8_t s[ 4 ]; } v;
   v.s[ 0 ] = 0x00;
   v.s[ 1 ] = rgb.red;
   v.s[ 2 ] = rgb.green;
   v.s[ 3 ] = rgb.blue;
   return swap_uint32_from_c( v.i, system_order_c() );
}

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

csStyle CS_DefaultStyle = {
   .f=0xffffff,
   .b=0x0
};

csStyle base_style_cs( cRgb24 front, cRgb24 back )
{
   return (csStyle){
      .f=rgb24_as_uint32( front ),
      .b=rgb24_as_uint32( back )
   };
}