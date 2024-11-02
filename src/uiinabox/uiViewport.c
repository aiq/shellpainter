#include "uiinabox/uiViewport.h"

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

extern inline uiViewport viewport_ui( uiSize world, uiSize viewSize );

extern inline uiViewport null_viewport_ui( void );

/*******************************************************************************

*******************************************************************************/

extern inline void move_viewport_ui( uiViewport vp[static 1],
                                     int16_t x,
                                     int16_t y );

/*******************************************************************************

*******************************************************************************/

extern inline bool eq_viewport_ui( uiViewport const a[static 1],
                                   uiViewport const b[static 1] );

extern inline bool is_null_viewport_ui( uiViewport const vp[static 1] );
