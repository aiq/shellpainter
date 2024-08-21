#include <stdlib.h>

#include "clingo/io/read_type.h"
#include "clingo/io/write.h"
#include "cmdscreen/colors.h"
#include "cmdscreen/csScreen.h"

int main( int argc, char* argv[] )
{
   csScreen* main = new_main_screen_cs();
   box( main, 0, 0 );

   mvwprintw( main, 2, 1, "select a number from 0 to %d or write exit", COLORS );

   int i = 3;
   while ( true )
   {
      cVarChars buf = var_chars_c_( 1024 );
      getnstr( buf.v, buf.s );
      mvwprintw( main, 3, 1, "the number %d is to high" );
      refresh();
   }

   remove_main_screen_cs();

   return EXIT_SUCCESS;
}