#include "cmdscreen/CSLabel.h"

#include "cmdscreen/term.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

static inline void cleanup( void* instance )
{
   CSLabel* label = instance;
   release_c( label->text );
}

cMeta const CS_Label = {
   .desc = stringify_c_( CSLabel ),
   .cleanup = &cleanup
};

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

void mimic_label_cs( CSLabel label[static 1], CSLabel const src[static 1] )
{
   replace_c_( label->text, src->text );
   label->style = src->style;
   label->alignment = src->alignment;
}

INTERN_SCREEN_CS_( it, CSLabel, show_label_cs )
uiBox label_box_cs( CSLabel const* label )
{
   must_exist_c_( label );
   return sized_ui( size_ui( UI_Grow, 1 ), screen_it( label ), none_ui() );
}

bool show_label_cs( CSLabel const* label, uiRect area )
{
   uiPoint cord = top_left_corner_ui( area );
   if ( not set_hline_cs( cord, sc_c( label->text ), label->style ) )
   {
      return false;
   }
   return true;
}