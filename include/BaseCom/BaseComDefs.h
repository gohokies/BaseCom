#ifndef __BASECOM_H_DEFS__
#define __BASECOM_H_DEFS__

#include <stddef.h>
#include <stdint.h>

#if (WIN32)
    #define WIN32_LEAN_AND_MEAN
    #include <windows.h>
#else
    // Definitions similar to windows
    typedef int32_t HRESULT;    
    #define S_OK                0

    #define E_NOTIMPL           0x80004001L
    #define E_NOINTERFACE       0x80004002L
    #define E_POINTER           0x80004003L
    #define E_ABORT             0x80004004L
    #define E_FAIL              0x80004005L
    #define E_UNEXPECTED        0x8000ffffL

    #define E_ACCESSDENIED      0x80070005L
    #define E_HANDLE            0x80070006L
    #define E_OUTOFMEMORY       0x8007000eL
    #define E_INVALIDARG        0x80070057L
 
    #define SUCCEEDED(hr) (hr >= 0)
    #define FAILED(hr) (hr < 0)
#endif

#define BC_DECLARE_HANDLE(_handle_name_)                                                \
    typedef struct _##_handle_name_                                                     \
    {                                                                                   \
        size_t _DoNotUse; /** Reserved, do not use. */                                  \
    } * _handle_name_;

#endif