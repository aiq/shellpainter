#include "cmdscreen/csPadding.h"

#include "clingo/io/write.h"

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

extern inline
csPadding padding_cs( int16_t left, int16_t top, int16_t right, int16_t bottom );

/*******************************************************************************

*******************************************************************************/

extern inline csRect pad_rect_cs( csRect rect, csPadding pad );

#define pad_value_( Value, Pad )                                               \
(                                                                              \
    ( (Value) == CS_Infinity ) ? CS_Infinity                                   \
                               : (Value) - (Pad)                               \
)

csLimit pad_limit_cs( csLimit limit, csPadding pad )
{
   csSize const min = (csSize){
      .w=imax16_c( 0, limit.min.w - hpadding_cs( pad ) ),
      .h=imax16_c( 0, limit.min.h - vpadding_cs( pad ) )
   };
   csSize const max = (csSize){
      .w=imax16_c( min.w, limit.max.w - hpadding_cs( pad ) ),
      .h=imax16_c( min.h, limit.max.h - vpadding_cs( pad ) )
   };
   return (csLimit){
      .min=min,
      .max=max
   };
}

/*******************************************************************************

*******************************************************************************/

extern inline int16_t hpadding_cs( csPadding pad );
extern inline int16_t vpadding_cs( csPadding pad );
