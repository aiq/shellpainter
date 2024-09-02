#ifndef UIINABOX_CSBOX_H
#define UIINABOX_CSBOX_H

#include "clingo/color/cP3Builder.h"
#include "clingo/lang/algo.h"
#include "uiinabox/uiLimit.h"
#include "cmdscreen/csStyle.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

#define LAYOUT_CS_( FuncName, Type, LayoutFunc, DoDeref )                      \
bool FuncName( csBox box[static 1],                                            \
               uiLimit limit,                                                  \
               void const* i,                                                  \
               cErrorStack es[static 1] )                                      \
{                                                                              \
   must_exist_c_( i );                                                         \
   Type const* val = i;                                                        \
   return LayoutFunc( box, limit, DoDeref( val ), es );                       \
}

struct csBox;
typedef struct csBox csBox;

SLICES_C_(
   csBox,       // Type
   csBoxes,     // SliceType
   csVarBoxes   // VarSliceType
)

typedef bool ( *cs_layout )( csBox* box,
                             uiLimit limit,
                             void const* val,
                             cErrorStack es[static 1] );

struct csBoxType
{
   char const* desc;
   cs_layout layout;
};
typedef struct csBoxType csBoxType;

struct csBox
{
   uiRect rect;
   void* data;
   csBoxType const* type;
   csStyle const* style;
   csVarBoxes children;
};

#define boxes_cs_( ... )                                                       \
   (csBoxes)slice_c_( csBox, __VA_ARGS__ )

UIINABOX_API inline bool layout_box_cs( csBox box[static 1],
                                         uiLimit limit,
                                         cErrorStack es[static 1] )
{
   must_exist_c_( box->type );
   return box->type->layout( box, limit, box->data, es );
}

/*******************************************************************************

*******************************************************************************/

UIINABOX_API csBox box_cs( void* data,
                            csBoxType const type[static 1],
                            csStyle const* style,
                            csBoxes children );

UIINABOX_API void globalise_cs( csBox box[static 1] );

UIINABOX_API bool dump_box_layout_cs( cChars path,
                                       csBox box[static 1],
                                       cErrorStack es[static 1] );

UIINABOX_API bool record_box_diff_cs( cRecorder rec[static 1],
                                       csBox const box[static 1],
                                       csBox const oth[static 1] );

#endif