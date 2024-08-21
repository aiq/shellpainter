#ifndef CMDSCREEN_APIDECL_H
#define CMDSCREEN_APIDECL_H

#ifdef CMDSCREEN_STATIC_DEFINE
#  define CMDSCREEN_API
#  define CMDSCREEN_NO_EXPORT
#else
#  ifdef _WIN32
#    ifndef CMDSCREEN_API
#      ifdef cmdscreen_EXPORTS
#        define CMDSCREEN_API __declspec(dllexport)
#      else
#        define CMDSCREEN_API __declspec(dllimport)
#      endif
#    endif
#  else
#    define CMDSCREEN_API
#    define CMDSCREEN_NO_EXPORT
#  endif
#
#  ifndef CMDSCREEN_NO_EXPORT
#    define CMDSCREEN_NO_EXPORT 
#  endif
#endif

#endif