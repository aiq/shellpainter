#ifndef UIINABOX_UIBOX_H
#define UIINABOX_UIBOX_H

#include "clingo/clingo.h"
#include "uiinabox/uiLimit.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

#define LAYOUT_UI_( FuncName, Type, LayoutFunc, DoDeref )                      \
bool FuncName( uiBox box[static 1],                                            \
               uiLimit limit,                                                  \
               cErrorStack es[static 1] )                                      \
{                                                                              \
   Type const* val = box->data;                                                \
   return LayoutFunc( box, limit, DoDeref( val ), es );                        \
}

struct uiBox;
typedef struct uiBox uiBox;

SLICES_C_(
   uiBox,       // Type
   uiBoxes,     // SliceType
   csVarBoxes   // VarSliceType
)

typedef bool ( *ui_layout )( uiBox* box,
                             uiLimit limit,
                             cErrorStack es[static 1] );

struct uiBoxType
{
   char const* desc;
   ui_layout layout;
};
typedef struct uiBoxType uiBoxType;

typedef void uiContent;

struct uiBox
{
   uiRect rect;
   void* data;
   uiBoxType const* type;
   uiContent const* content;
   csVarBoxes children;
};

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

#define boxes_cs_( ... )                                                       \
   (uiBoxes)slice_c_( uiBox, __VA_ARGS__ )

UIINABOX_API inline bool layout_box_ui( uiBox box[static 1],
                                        uiLimit limit,
                                        cErrorStack es[static 1] )
{
   must_exist_c_( box->type );
   bool ok = box->type->layout( box, limit, es );
   if ( not ok )
   {
      return false;
   }
   if ( box->rect.w == UI_Infinity )
   {
      return push_lit_error_c( es, "a w value is infinity" );
   }
   if ( box->rect.h == UI_Infinity )
   {
      return push_lit_error_c( es, "a h value is infitity" );
   }
   return true;
}

/*******************************************************************************

*******************************************************************************/

UIINABOX_API uiBox box_ui( void* data,
                           uiBoxType const type[static 1],
                           uiContent const* content,
                           uiBoxes children );

UIINABOX_API void globalise_ui( uiBox box[static 1] );

UIINABOX_API bool dump_box_layout_ui( cChars path,
                                      uiBox box[static 1],
                                      cErrorStack es[static 1] );

#endif