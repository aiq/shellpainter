#include "uiinabox/uiPadding.h"

#include "clingo/io/write.h"

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

extern inline
uiPadding padding_ui( int16_t left, int16_t top, int16_t right, int16_t bottom );

/*******************************************************************************

*******************************************************************************/

extern inline uiRect pad_rect_ui( uiRect rect, uiPadding pad );

#define pad_value_( Value, Pad )                                               \
(                                                                              \
    ( (Value) == CS_Infinity ) ? CS_Infinity                                   \
                               : (Value) - (Pad)                               \
)

uiLimit pad_limit_ui( uiLimit limit, uiPadding pad )
{
   int16_t const horizontal = pad.left + pad.right;
   int16_t const vertical = pad.top + pad.bottom;
   uiSize const min = (uiSize){
      .w=imax16_c( 0, limit.min.w - horizontal ),
      .h=imax16_c( 0, limit.min.h - vertical )
   };
   uiSize const max = (uiSize){
      .w=imax16_c( min.w, limit.max.w - horizontal ),
      .h=imax16_c( min.h, limit.max.h - vertical )
   };
   return (uiLimit){
      .min=min,
      .max=max
   };
}
