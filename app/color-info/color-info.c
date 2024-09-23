#include <stdlib.h>

#include "clingo/io/read_type.h"
#include "clingo/io/write.h"
#include "cmdscreen/colors.h"
#include "cmdscreen/csScreen.h"

int main( int argc, char* argv[] )
{
   csScreen* main = cmdscreen_cs();
   cleanup_cmdscreen_cs();

   return EXIT_SUCCESS;
}