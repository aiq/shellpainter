#ifndef UIINABOX_SIZED_H
#define UIINABOX_SIZED_H

#include "uiinabox/uiBox.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

UIINABOX_API extern int16_t const UI_Shrink;

UIINABOX_API extern int16_t const UI_Grow;

UIINABOX_API extern uiBoxType const UI_Sized;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

#define sized_ui_( Size, Child )                                               \
   sized_ui( (Size), NULL, (Child) )
UIINABOX_API uiBox sized_ui( uiSize size, uiContent const* content, uiBox child );

UIINABOX_API bool layout_sized_ui( uiBox box[static 1],
                                   uiLimit limit,
                                   uiSize size,
                                   cErrorStack es[static 1] );

/*******************************************************************************

*******************************************************************************/

UIINABOX_API inline uiSize shrink_ui( void )
{
   return size_ui( UI_Shrink, UI_Shrink );
}

UIINABOX_API inline uiSize grow_ui( void )
{
   return size_ui( UI_Grow, UI_Grow );
}

#endif