#include <stdlib.h>

#include "clingo/io/read_type.h"
#include "clingo/io/write.h"
#include "cmdscreen/colors.h"
#include "cmdscreen/csScreen.h"

int main( int argc, char* argv[] )
{
   csScreen* main = cmdscreen_cs();
   box( main, 0, 0 );
   mvwprintw( main, 1, 1, "select a number from 0 to %d or write exit", COLORS );
   refresh();

   csScreen* out = new_screen_cs( rect_cs( 4, 4, 80, 4 ) );

   while ( true )
   {
      wclear( out );
      cVarChars buf = var_chars_c_( 1024 );
      getnstr( buf.v, buf.s );
      cScanner* sca = &cstr_scanner_c_( buf.v );
      int32_t idx;
      mvwprintw( out, 0, 0, "input: %s can_change_color: %d", buf.v, can_change_color() );
      if ( cstr_is_c( buf.v, "exit") )
      {
         break;
      }
      if ( not read_int32_c_( sca, &idx ) )
      {
         mvwprintw( out, 1, 1, "not able to read index from: %s", buf.v );
         wrefresh( out );
         continue;
      }
      if ( not in_range_c_( 0, idx, COLORS ) )
      {
         mvwprintw( out, 1, 1, "the number %d is to high", idx );
         wrefresh( out );
         continue;
      }

      cRecorder* rec = &recorder_c_( 512 );
      init_pair( idx, idx, 0 );
      wattron( out, COLOR_PAIR( idx ) );

      cColor col = get_color_cs( idx );
      writeln_c_( rec, "red:{u8} green:{u8} blue:{u8}", col.r, col.g, col.b );
      mvwprintw( out, 1, 1, "%s", turn_into_cstr_c( rec ) );

      short red, green, blue;
      color_content( idx, &red, &green, &blue );
      writeln_c_( rec, "red:{i} green:{i} blue:{i}", red, green, blue );
      mvwprintw( out, 2, 1, "%s", turn_into_cstr_c( rec ) );
      wattroff( out, COLOR_PAIR( idx ) );
    
      init_pair( 255, 255, 0 );
      wattron( out, COLOR_PAIR( 255 ) );
      init_color( 255, 500, 0, 0 );
      color_content( 255, &red, &green, &blue );
      writeln_c_( rec, "red:{i} green:{i} blue:{i}", red, green, blue );
      mvwprintw( out, 3, 1, "%s", turn_into_cstr_c( rec ) );
      wattroff( out, COLOR_PAIR( 255 ) );
      wrefresh( out );
   }

   remove_screen_cs( out );
   cleanup_cmdscreen_cs();

   return EXIT_SUCCESS;
}