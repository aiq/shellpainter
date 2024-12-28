#include "cmdscreen/CSTextArea.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/



/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

CSTextArea* new_text_area_cs( void )
{
   return NULL;
}

uiBox text_area_box_cs( CSTextArea const* area )
{
   return (uiBox){0};
}

bool show_text_area_cs( CSTextArea const* area, uiRect term )
{
   return false;
}

bool update_text_area_cs( CSTextArea const* area, CObject const* msg )
{
   return false;
}

/*******************************************************************************

*******************************************************************************/

bool command_text_area_cs( CSTextArea* area, cs_KeyCmd cmd )
{
   must_exist_c_( area );
   return false;
}

bool get_text_area_value_cs( CSTextArea const* area, cRecorder rec[static 1] )
{
   must_exist_c_( area );
   return false;
}

bool set_text_area_value_cs( CSTextArea* area, cChars vlaue )
{
   must_exist_c_( area );
   return false;
}