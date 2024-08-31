#include "cmdscreen/layout/align.h"

#include "cmdscreen/_/CS_MainScreen.h"
#include "cmdscreen/layout/_/util.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

static LAYOUT_CS_( do_align, csAlignment, layout_align_cs, do_deref_c_ )
csBoxType const CS_Align = {
   .desc = "align",
   .layout = &do_align
};

/*******************************************************************************

*******************************************************************************/

static inline int16_t alignx( cs_AlignX x, int16_t boxw, int16_t childw )
{
   if ( x == cs_CenterX )
   {
      return ( boxw / 2 ) - ( childw / 2 );
   }
   else if ( x == cs_Right )
   {
      return boxw - childw;
   }
   else  // cs_Left
   {
      return 0;
   }
}

static inline int16_t aligny( cs_AlignY y, int16_t boxh, int16_t childh )
{
   if ( y == cs_CenterY )
   {
      return ( boxh / 2 ) - ( childh / 2 );
   }
   else if ( y == cs_Bottom )
   {
      return boxh - childh;
   }
   else  // cs_Top
   {
      return 0;
   }
}

/******************************************************************************/

static bool layout_alignx( csBox box[static 1],
                           csLimit limit,
                           csAlignment alignment,
                           cErrorStack es[static 1] )
{
   if ( not has_just_single_child( "alignx", box->children, es ) )
   {
      return false;
   }
   box->rect.x = 0;
   box->rect.y = 0;

   csBox* child = box->children.v;
   if ( not layout_box_cs( child, limit, es ) )
   {
      return false;
   }
   box->rect.w = limit_height_cs_( limit );
   box->rect.h = child->rect.h;

   child->rect.x = alignx( alignment.x, box->rect.w, child->rect.w );
   child->rect.y = aligny( alignment.y, box->rect.h, child->rect.h );

   return true;
}
static LAYOUT_CS_( alignx_func, csAlignment, layout_alignx, do_deref_c_ )
static csLayout alignx_layout( csAlignment const* align )
{
   return (csLayout){ .i=align, .f=alignx_func };
}

/******************************************************************************/

static bool layout_aligny( csBox box[static 1],
                           csLimit limit,
                           csAlignment alignment,
                           cErrorStack es[static 1] )
{
   if ( not has_just_single_child( "aligny", box->children, es ) )
   {
      return false;
   }
   box->rect.x = 0;
   box->rect.y = 0;

   csBox* child = box->children.v;
   if ( not layout_box_cs( child, limit, es ) )
   {
      return false;
   }
   box->rect.w = child->rect.w;
   box->rect.h = limit_height_cs_( limit );

   child->rect.x = alignx( alignment.x, box->rect.w, child->rect.w );
   child->rect.y = aligny( alignment.y, box->rect.h, child->rect.h );

   return true;
}
static LAYOUT_CS_( aligny_func, csAlignment, layout_aligny, do_deref_c_ )
static csLayout aligny_layout( csAlignment const* align )
{
   return (csLayout){ .i=align, .f=aligny_func };
}

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

csBox left_cs( csBox box )
{
   return alignx_cs( cs_Left, NULL, box );
}

csBox centerx_cs( csBox box )
{
   return alignx_cs( cs_CenterX, NULL, box );
}

csBox right_cs( csBox box )
{
   return alignx_cs( cs_Right, NULL, box );
}

csBox alignx_cs( cs_AlignX align, csStyle const* style, csBox child )
{
   csAlignment* newAlign = alloc_one_( csAlignment );
   if ( newAlign == NULL ) return (csBox){0};
   else *newAlign = alignment_cs_( align, cs_Top );

   csBox* newChild = alloc_one_( csBox );
   if ( newChild == NULL ) return (csBox){0};
   else *newChild = child;

   return (csBox){
      .layout=alignx_layout( newAlign ),
      .style=style,
      .children=(csVarBoxes){ .s=1, .v=newChild }
   };
}

csBox top_cs( csBox box )
{
   return aligny_cs( cs_Top, NULL, box );
}

csBox centery_cs( csBox box )
{
   return aligny_cs( cs_CenterY, NULL, box );
}

csBox bottom_cs( csBox box )
{
   return aligny_cs( cs_Bottom, NULL, box );
}

csBox aligny_cs( cs_AlignY align, csStyle const* style, csBox child )
{
   csAlignment* newAlign = alloc_one_( csAlignment );
   if ( newAlign == NULL ) return (csBox){0};
   else *newAlign = alignment_cs_( cs_Left, align );

   csBox* newChild = alloc_one_( csBox );
   if ( newChild == NULL ) return (csBox){0};
   else *newChild = child;

   return (csBox){
      .layout=aligny_layout( newAlign ),
      .style=style,
      .children=(csVarBoxes){ .s=1, .v=newChild }
   };
}

csBox align_cs( csAlignment align,
                csStyle const* style,
                csBox child )
{
   csAlignment* newAlign = alloc_one_( csAlignment );
   if ( newAlign == NULL ) return (csBox){0};
   else *newAlign = align;

   csBox* newChild = alloc_one_( csBox );
   if ( newChild == NULL ) return (csBox){0};
   else *newChild = child;

   return (csBox){
      .payload=newAlign,
      .type=&CS_Align,
      .layout=align_layout_cs( newAlign ),
      .style=style,
      .children=(csVarBoxes){ .s=1, .v=newChild }
   };
}

static LAYOUT_CS_( align_func, csAlignment, layout_align_cs, do_deref_c_ )
csLayout align_layout_cs( csAlignment const* align )
{
   return (csLayout){ .i=align, .f=align_func };
}

bool layout_align_cs( csBox box[static 1],
                      csLimit limit,
                      csAlignment alignment,
                      cErrorStack es[static 1] )
{
   if ( not has_just_single_child( "align", box->children, es ) )
   {
      return false;
   }
   box->rect.x = 0;
   box->rect.y = 0;
   box->rect.w = limit_width_cs_( limit );
   box->rect.h = limit_height_cs_( limit );

   csBox* child = box->children.v;
   if ( not layout_box_cs( child, limit, es ) )
   {
      return false;
   }

   child->rect.x = alignx( alignment.x, box->rect.w, child->rect.w );
   child->rect.y = aligny( alignment.y, box->rect.h, child->rect.h );

   return true;
}