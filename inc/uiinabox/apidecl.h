#ifndef UIINABOX_APIDECL_H
#define UIINABOX_APIDECL_H

#ifdef UIINABOX_STATIC_DEFINE
#  define UIINABOX_API
#  define UIINABOX_NO_EXPORT
#else
#  ifdef _WIN32
#    ifndef UIINABOX_API
#      ifdef UIINABOX_EXPORTS
#        define UIINABOX_API __declspec(dllexport)
#      else
#        define UIINABOX_API __declspec(dllimport)
#      endif
#    endif
#  else
#    define UIINABOX_API
#    define UIINABOX_NO_EXPORT
#  endif
#
#  ifndef UIINABOX_NO_EXPORT
#    define UIINABOX_NO_EXPORT 
#  endif
#endif

#endif