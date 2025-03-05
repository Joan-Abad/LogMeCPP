#pragma once

#define LOGGING_EXPORTS

#ifdef LOGGING_EXPORTS
    #define LOGGING_API __declspec(dllexport)
#else
    #define LOGGING_API __declspec(dllimport)
#endif

