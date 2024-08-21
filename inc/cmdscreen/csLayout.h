#ifndef CMDSCREEN_CSLAYOUT_H
#define CMDSCREEN_CSLAYOUT_H

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
/*
struct csRule
{
   bool wrap;
   csBox box;
   int16_t fill;
   csPadding padding;
   int16_t space;
   csAlignment alignment;
};
typedef struct csRule csRule;

struct csLayout;
typedef struct csLayout csLayout;

SLICES_C_(
   csLayout,      // Type
   csLayouts,     // SliceType
   csVarLayouts   // VarSliceType
)

#define csLayoutType_                                                          \
   XMAP_C_( cs_Row, 0 )                                                        \
   XMAP_C_( cs_Column, 1 )

#define XMAP_C_( N, I ) N = I,
enum cs_LayoutType { csLayoutType_ };
#undef XMAP_C_
typedef enum cs_LayoutType cs_LayoutType;

struct csLayout
{
   cs_LayoutType type;
   csRule rule;
   csVarLayouts children;
   csRect rect;
};

#define fill_cs_( Fill )

#define row_cs_( Rule , ... )                                       \
(csLayout){                                                         \
   .axis=cs_Row,                                                    \
   .rule=(Rule),                                                    \
   .children=slice_c_( csLayout, __VA_ARGS__ )                      \
}

#define col_cs_( Rule , ... )                                       \
(csLayout){                                                         \
   .axis=cs_Column,                                                 \
   .rule=(Rule),                                                    \
   .children=slice_c_( csLayout, __VA_ARGS__ )                      \
}
*/

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

struct csLayout;
typedef struct csLayout csLayout;

SLICES_C_(
   csLayout,      // Type
   csLayouts,     // SliceType
   csVarLayouts   // VarSliceType
)

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

#define layout_box_cs_( BoxPtr, Limit, Es )                                    \
   (BoxPtr)->layout.f( (BoxPtr), (Limit), (BoxPtr)->layout.i, (Es) )

struct csLayout
{
   void const* i;
   cs_layout f;
};

struct csBox
{
   csRect rect;
   csLayout layout;
   csStyle style;
   csVarBoxes children;
};

/*******************************************************************************

*******************************************************************************/

#define box_cs_( Layout, Style, Child )                                        \
(csBox){                                                                       \
   .rect=(csRect){0},                                                          \
   .layout=(Layout),                                                           \
   .style=(Style),                                                             \
   .children=(csVarBoxes){                                                     \
      .s=1,                                                                    \
      .v=(csBox[]){ Child }                                                    \
   }                                                                           \
}

#define none_cs_()                                                             \
(csBox){                                                                       \
   .rect=(csRect){ .x=-2, .y=-2, .w=0, .h=0 },                                 \
   .layout=none_layout_cs(),                                                   \
   .style=none_style_cs_(),                                                    \
   .children=(csVarBoxes){ .s=0, .v=NULL }                                     \
}

CMDSCREEN_API bool layout_pad_cs( csBox box[static 1],
                                  csLimit limit,
                                  csPadding pad,
                                  cErrorStack es[static 1] );

#define pad_cs_( Pad )                                                         \
   pad_cs( ref_c_( csPadding, (Pad) ) )
CMDSCREEN_API csLayout pad_cs( csPadding const* pad );

CMDSCREEN_API bool layout_align_cs( csBox box[static 1],
                                    csLimit limit,
                                    csAlignment align,
                                    cErrorStack es[static 1] );

#define align_cs_( Align )                                                     \
   align_cs( ref_c_( csAlignment, (Align) ) )
CMDSCREEN_API csLayout align_cs( csAlignment const* align );

CMDSCREEN_API bool layout_fixed_cs( csBox box[static 1],
                                    csLimit limit,
                                    csSize size,
                                    cErrorStack es[static 1] );

#define fixed_cs_( Size )                                                     \
   fixed_cs( ref_c_( csSize, (Size) ) )
CMDSCREEN_API csLayout fixed_cs( csSize const* size );

CMDSCREEN_API csLayout none_layout_cs( void );

/*******************************************************************************

*******************************************************************************/

CMDSCREEN_API void as_global_box_cs( csBox box[static 1] );

CMDSCREEN_API bool dump_box_layout_cs( cChars path,
                                       csBox box[static 1],
                                       cErrorStack es[static 1] );

#endif