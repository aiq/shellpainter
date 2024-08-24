#include "clingo/io/write.h"
#include "clingo/lang/expect.h"
#include "cmdscreen/csLayout.h"
#include "cmdscreen/layout/align.h"
#include "cmdscreen/layout/fixed.h"
#include "cmdscreen/layout/none.h"
#include "cmdscreen/layout/pad.h"

#define cDISTINCT_RED_      rgb24_c_( 230,  25,  75 )
#define cDISTINCT_GREEN_    rgb24_c_(  60, 180,  75 )
#define cDISTINCT_YELLOW_   rgb24_c_( 255, 255,  25 )
#define cDISTINCT_BLUE_     rgb24_c_(   0, 130, 200 )
#define cDISTINCT_ORANGE_   rgb24_c_( 245, 130,  48 )

#define cDISTINCT_PURPLE_   rgb24_c_( 145,  30, 180 )
#define cDISTINCT_CYAN_     rgb24_c_(  70, 240, 240 )
#define cDISTINCT_MAGENTA_  rgb24_c_( 240,  50, 230 )
#define cDISTINCT_LIME_     rgb24_c_( 210, 245,  60 )
#define cDISTINCT_PINK_     rgb24_c_( 250, 190, 212 )

#define cDISTINCT_TEAL_     rgb24_c_(   0, 128, 128 )
#define cDISTINCT_LAVENDER_ rgb24_c_( 220, 190, 255 )
#define cDISTINCT_BROWN_    rgb24_c_( 170, 110,  40 )
#define cDISTINCT_BEIGE_    rgb24_c_( 255, 250, 200 )
#define cDISTINCT_MAROON_   rgb24_c_( 128,   0,   0 )

#define cDISTINCT_MINT_     rgb24_c_( 170, 255, 195 )
#define cDISTINCT_OLIVE_    rgb24_c_( 128, 128,   0 )
#define cDISTINCT_APRICOT_  rgb24_c_( 255, 215, 180 )
#define cDISTINCT_NAVY_     rgb24_c_(   0,   0, 128 )
#define cDISTINCT_GREY_     rgb24_c_( 128, 128, 128 )

#define cDISTINCT_WHITE_    rgb24_c_( 255, 255, 255 )
#define cDISTINCT_BLACK_    rgb24_c_(   0,   0,   0 )

#define TEAL_STYLE_ style_cs_( .front=cDISTINCT_TEAL_, .back=cDISTINCT_TEAL_ )
#define MAROON_STYLE_ style_cs_( .front=cDISTINCT_MAROON_, .back=cDISTINCT_MAROON_ )
#define GREY_STYLE_ style_cs_( .front=cDISTINCT_GREY_, .back=cDISTINCT_GREY_ )
#define NAVY_STYLE_ style_cs_( .front=cDISTINCT_NAVY_, .back=cDISTINCT_NAVY_ )

int main( void )
{
   init_tap_c_();

   csBox root = box_cs_(
      pad_layout_cs_( padding_cs( 2, 2, 2, 2 ) ),
      TEAL_STYLE_,
      box_cs_(
         align_layout_cs_( center_cs_() ),
         MAROON_STYLE_,
         box_cs_(
            fixed_layout_cs_( size_cs( 5, 5 ) ),
            GREY_STYLE_,
            box_cs_(
               align_layout_cs_( center_cs_() ),
               GREY_STYLE_,
               box_cs_(
                  fixed_layout_cs_( size_cs( 3, 3 ) ),
                  NAVY_STYLE_,
                  none_cs_()
               )
            )
         )
      )
   );

   csLimit limit = fix_limit_cs( 20, 15 );
   cErrorStack* es = &error_stack_c_( 256 );
   layout_box_cs_( &root, limit, es );
   as_global_box_cs( &root );

   csBox exp = layouted_box_cs_(
      rect_cs( 0, 0, 20, 15 ),   // padding
      layouted_box_cs_(
         rect_cs( 2, 2, 16, 11 ),   // align
         layouted_box_cs_(
            rect_cs( 8, 5, 5, 5 ),    // fixed
            layouted_box_cs_(
               rect_cs( 8, 5, 5, 5 ), // align
               layouted_box_cs_(
                  rect_cs( 9, 6, 3, 3 ), // fixed
                  none_cs_()
               )
            )
         )
      )
   );

   dump_box_layout_cs( c_c( "layout_box.ppm" ), &root, es );

   cRecorder* rec = &dyn_recorder_c_( 0 );
   record_box_diff_cs( rec, cs_CheckRect, &exp, &root );
   print_recorded_c( rec );
   free_recorder_mem_c( rec );

   return finish_tap_c_();
}