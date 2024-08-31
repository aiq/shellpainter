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

struct csBoxType
{
   char const* desc;
   cs_layout layout;
};

typedef struct csBoxType csBoxType;

struct csBox
{
   csRect rect;
   csLayout layout;
   csStyle const* style;
   int16_t fill;
   csVarBoxes children;
};

#define children_cs_( ... )                                                    \
   (csBoxes)slice_c_( csBox, __VA_ARGS__ )

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

#define layouted_box_cs_( Rect, ... )                                          \
(csBox){                                                                       \
   .rect=(Rect),                                                               \
   .layout=none_layout_cs(),                                                   \
   .style=NULL,                                                                \
   .children=slice_c_( csBox, __VA_ARGS__ )                                    \
}

#define none_cs_()                                                             \
(csBox){                                                                       \
   .rect=(csRect){ .x=0, .y=0, .w=0, .h=0 },                                   \
   .layout=none_layout_cs(),                                                   \
   .style=NULL,                                                                \
   .children=(csVarBoxes){ .s=0, .v=NULL }                                     \
}



/*******************************************************************************

*******************************************************************************/

CMDSCREEN_API void as_global_box_cs( csBox box[static 1] );

CMDSCREEN_API bool dump_box_layout_cs( cChars path,
                                       csBox box[static 1],
                                       cErrorStack es[static 1] );

#define csDIFF_CONFIG_DEFINITION_                                              \
   XMAP_C_( cs_CheckRect, 1 << 0 )                                             \
   XMAP_C_( cs_CheckStyle, 1 << 1 )                                            \
   XMAP_C_( cs_CheckAll, cs_CheckRect|cs_CheckStyle )

#define XMAP_C_( N, I ) N = I,
enum cs_DiffConfig { csDIFF_CONFIG_DEFINITION_ };
#undef XMAP_C_
typedef enum cs_DiffConfig cs_DiffConfig;

#define record_box_diff_cs_( Rec, Box, Oth )                                   \
   record_box_diff_cs( (Rec), cs_CheckAll, (Box), (Oth) )
CMDSCREEN_API bool record_box_diff_cs( cRecorder rec[static 1],
                                       cs_DiffConfig cfg,
                                       csBox const box[static 1],
                                       csBox const oth[static 1] );

#endif