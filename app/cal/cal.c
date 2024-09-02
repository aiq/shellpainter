#include <stdlib.h>

#include "cmdscreen/csScreen.h"

int main( int argc, char* argv[] )
{
   csScreen* main = cmdscreen_cs();
   box( main, 0, 0 );

   csScreen* dlg1 = new_screen_cs( rect_ui( 2, 4, 5, 20 ) );
   box( dlg1, 0, 0 );
   mvwaddstr( dlg1, 1, 1, "test with to much text" );

   uiSize dlg1Size = screen_size_ui( dlg1 );
   cRecorder* rec = &recorder_c_( 256 );
   write_size_ui( rec, dlg1Size, "" );
   mvwaddstr( main, 1, 1, turn_into_cstr_c( rec ) );

   mvwprintw( main, 2, 1, "has colors: %d, COLORS: %d COLOR_PAIRS %d", has_colors(), COLORS, COLOR_PAIRS );
   times_c_( COLOR_PAIRS, i )
   {
      init_pair( i, i, 0 );
      attron( COLOR_PAIR( i ) );
      wprintw( main, "%d", i );
      attroff( COLOR_PAIR( i ) );
   }

   refresh();
   wrefresh( dlg1 );

   getch();

   remove_screen_cs( dlg1 );
   cleanup_cmdscreen_cs();

   return EXIT_SUCCESS;
}