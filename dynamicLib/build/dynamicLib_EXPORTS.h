
#ifndef dynamicLib_EXPORTS_H
#define dynamicLib_EXPORTS_H

#ifdef dynamicLib_EXPORTS_BUILD_AS_STATIC
#  define dynamicLib_EXPORTS
#  define DYNAMICLIB_NO_EXPORT
#else
#  ifndef dynamicLib_EXPORTS
#    ifdef dynamicLib_EXPORTS
        /* We are building this library */
#      define dynamicLib_EXPORTS __declspec(dllexport)
#    else
        /* We are using this library */
#      define dynamicLib_EXPORTS __declspec(dllimport)
#    endif
#  endif

#  ifndef DYNAMICLIB_NO_EXPORT
#    define DYNAMICLIB_NO_EXPORT 
#  endif
#endif

#ifndef DYNAMICLIB_DEPRECATED
#  define DYNAMICLIB_DEPRECATED __declspec(deprecated)
#endif

#ifndef DYNAMICLIB_DEPRECATED_EXPORT
#  define DYNAMICLIB_DEPRECATED_EXPORT dynamicLib_EXPORTS DYNAMICLIB_DEPRECATED
#endif

#ifndef DYNAMICLIB_DEPRECATED_NO_EXPORT
#  define DYNAMICLIB_DEPRECATED_NO_EXPORT DYNAMICLIB_NO_EXPORT DYNAMICLIB_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef DYNAMICLIB_NO_DEPRECATED
#    define DYNAMICLIB_NO_DEPRECATED
#  endif
#endif

#endif /* dynamicLib_EXPORTS_H */
