#ifndef ADDLIB_GLOBAL_H
#define ADDLIB_GLOBAL_H

#ifdef _WIN32
    #if defined(SCHEDULER_LIBRARY)
    #  define SCHEDULERSHARED_EXPORT __declspec(dllexport)
    #else
    #  define SCHEDULERSHARED_EXPORT __declspec(dllimport)
    #endif
#else
    #define SCHEDULERSHARED_EXPORT
#endif

#endif // ADDLIB_GLOBAL_H