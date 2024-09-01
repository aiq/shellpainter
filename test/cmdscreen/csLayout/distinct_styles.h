#ifndef DISTINCT_STYLES_H
#define DISTINCT_STYLES_H

#include "cmdscreen/csStyle.h"

#define DISTINCT_RED_      rgb24_c_( 230,  25,  75 )
#define DISTINCT_GREEN_    rgb24_c_(  60, 180,  75 )
#define DISTINCT_YELLOW_   rgb24_c_( 255, 255,  25 )
#define DISTINCT_BLUE_     rgb24_c_(   0, 130, 200 )
#define DISTINCT_ORANGE_   rgb24_c_( 245, 130,  48 )

#define DISTINCT_PURPLE_   rgb24_c_( 145,  30, 180 )
#define DISTINCT_CYAN_     rgb24_c_(  70, 240, 240 )
#define DISTINCT_MAGENTA_  rgb24_c_( 240,  50, 230 )
#define DISTINCT_LIME_     rgb24_c_( 210, 245,  60 )
#define DISTINCT_PINK_     rgb24_c_( 250, 190, 212 )

#define DISTINCT_TEAL_     rgb24_c_(   0, 128, 128 )
#define DISTINCT_LAVENDER_ rgb24_c_( 220, 190, 255 )
#define DISTINCT_BROWN_    rgb24_c_( 170, 110,  40 )
#define DISTINCT_BEIGE_    rgb24_c_( 255, 250, 200 )
#define DISTINCT_MAROON_   rgb24_c_( 128,   0,   0 )

#define DISTINCT_MINT_     rgb24_c_( 170, 255, 195 )
#define DISTINCT_OLIVE_    rgb24_c_( 128, 128,   0 )
#define DISTINCT_APRICOT_  rgb24_c_( 255, 215, 180 )
#define DISTINCT_NAVY_     rgb24_c_(   0,   0, 128 )
#define DISTINCT_GREY_     rgb24_c_( 128, 128, 128 )

#define DISTINCT_WHITE_    rgb24_c_( 255, 255, 255 )
#define DISTINCT_BLACK_    rgb24_c_(   0,   0,   0 )

#define RED_        style_cs_( .front=DISTINCT_WHITE_,  .back=DISTINCT_RED_ )
#define GREEN_      style_cs_( .front=DISTINCT_WHITE_,  .back=DISTINCT_GREEN_ )
#define YELLOW_     style_cs_( .front=DISTINCT_BLACK_,  .back=DISTINCT_YELLOW_ )
#define BLUE_       style_cs_( .front=DISTINCT_WHITE_,  .back=DISTINCT_BLUE_ )
#define ORANGE_     style_cs_( .front=DISTINCT_WHITE_,  .back=DISTINCT_ORANGE_ )

#define PURPLE_     style_cs_( .front=DISTINCT_WHITE_,  .back=DISTINCT_PURPLE_ )
#define CYAN_       style_cs_( .front=DISTINCT_BLACK_,  .back=DISTINCT_CYAN_ )
#define MAGENTA_    style_cs_( .front=DISTINCT_BLACK_,  .back=DISTINCT_MAGENTA_ )
#define LIME_       style_cs_( .front=DISTINCT_BLACK_,  .back=DISTINCT_LIME_ )
#define PINK_       style_cs_( .front=DISTINCT_BLACK_,  .back=DISTINCT_PINK_ )

#define TEAL_       style_cs_( .front=DISTINCT_WHITE_,  .back=DISTINCT_TEAL_ )
#define LAVENDER_   style_cs_( .front=DISTINCT_WHITE_,  .back=DISTINCT_LAVENDER_ )
#define BROWN_      style_cs_( .front=DISTINCT_WHITE_,  .back=DISTINCT_BROWN_ )
#define BEIGE_      style_cs_( .front=DISTINCT_WHITE_,  .back=DISTINCT_BEIGE_ )
#define MAROON_     style_cs_( .front=DISTINCT_WHITE_,  .back=DISTINCT_MAROON_ )

#define MINT_       style_cs_( .front=DISTINCT_WHITE_,  .back=DISTINCT_MINT_ )
#define OLIVE_      style_cs_( .front=DISTINCT_WHITE_,  .back=DISTINCT_OLIVE_ )
#define APRICOT_    style_cs_( .front=DISTINCT_WHITE_,  .back=DISTINCT_APRICOT_ )
#define NAVY_       style_cs_( .front=DISTINCT_WHITE_,  .back=DISTINCT_NAVY_ )
#define GREY_       style_cs_( .front=DISTINCT_BLACK_,  .back=DISTINCT_GREY_ )

#define WHITE_      style_cs_( .front=DISTINCT_BLACK_,  .back=DISTINCT_WHITE_ )
#define BLACK_      style_cs_( .front=DISTINCT_WHITE_,  .back=DISTINCT_BLACK_ )

#endif