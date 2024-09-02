#ifndef CMDSCREEN_CSBOX_H
#define CMDSCREEN_CSBOX_H

#include "clingo/color/cP3Builder.h"
#include "clingo/lang/algo.h"
#include "cmdscreen/csAlignment.h"
#include "cmdscreen/csPadding.h"
#include "cmdscreen/csLimit.h"
#include "cmdscreen/csStyle.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

#define LAYOUT_CS_( FuncName, Type, LayoutFunc, DoDeref )                      \
bool FuncName( csBox box[static 1],                                            \
               csLimit limit,                                                  \
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
                             csLimit limit,
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
   csRect rect;
   void* data;
   csBoxType const* type;
   csStyle const* style;
   csVarBoxes children;
};

#define boxes_cs_( ... )                                                       \
   (csBoxes)slice_c_( csBox, __VA_ARGS__ )

CMDSCREEN_API inline bool layout_box_cs( csBox box[static 1],
                                         csLimit limit,
                                         cErrorStack es[static 1] )
{
   must_exist_c_( box->type );
   return box->type->layout( box, limit, box->data, es );
}

/*******************************************************************************

*******************************************************************************/

CMDSCREEN_API csBox box_cs( void* data,
                            csBoxType const type[static 1],
                            csStyle const* style,
                            csBoxes children );

CMDSCREEN_API void globalise_cs( csBox box[static 1] );

CMDSCREEN_API bool dump_box_layout_cs( cChars path,
                                       csBox box[static 1],
                                       cErrorStack es[static 1] );

CMDSCREEN_API bool record_box_diff_cs( cRecorder rec[static 1],
                                       csBox const box[static 1],
                                       csBox const oth[static 1] );

#endif