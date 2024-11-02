#ifndef UIINABOX_UIVIEWPORT_H
#define UIINABOX_UIVIEWPORT_H

#include "uiinabox/uiRect.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

struct uiViewport
{
   uiSize world;
   uiRect view;
};
typedef struct uiViewport uiViewport;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

UIINABOX_API inline uiViewport viewport_ui( uiSize world, uiSize viewSize )
{
   uiRect view = make_rect_ui( point_ui( 0, 0 ), viewSize );
   return (uiViewport){ .world=world, .view=view };
}

UIINABOX_API inline uiViewport null_viewport_ui( void )
{
   return (uiViewport){ .world=size_ui( 0, 0 ), .view=null_rect_ui() };
}

/*******************************************************************************

*******************************************************************************/

UIINABOX_API inline void move_viewport_ui( uiViewport vp[static 1],
                                           int16_t x,
                                           int16_t y )
{
   vp->view.x += x;
   vp->view.y += y;

   vp->view.x = imax16_c( 0, vp->view.x );
   vp->view.y = imax16_c( 0, vp->view.y );
   vp->view.x = imin16_c( vp->world.w - vp->view.w, vp->view.x );
   vp->view.y = imin16_c( vp->world.h - vp->view.h, vp->view.y );
}

/*******************************************************************************

*******************************************************************************/

UIINABOX_API inline bool eq_viewport_ui( uiViewport const a[static 1],
                                         uiViewport const b[static 1] )
{
   return eq_size_ui( a->world, b->world ) and
          eq_rect_ui( a->view, b->view );
}

UIINABOX_API inline bool is_null_viewport_ui( uiViewport const vp[static 1] )
{
   uiViewport nullViewport = null_viewport_ui();
   return eq_viewport_ui( vp, &nullViewport );
}

#endif