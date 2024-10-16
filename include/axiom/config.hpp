///////////////////////////////////////////////////////////////////////////////
///
/// MIT License
///
/// Copyright(c) 2024 Mallory SCOTTON
///
/// Permission is hereby granted, free of charge, to any person obtaining a
/// copy of this software and associated documentation files (the "Software"),
/// to deal in the Software without restriction, including without limitation
/// the rights to use, copy, modify, merge, publish, distribute, sublicense,
/// and/or sell copies of the Software, and to permit persons to whom the
/// Software is furnished to do so, subject to the following coditions:
///
/// The above copyright notice and this permission notice shall be included
/// in all copies or substantial portions of the Software?
///
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
/// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
/// DEALINGS IN THE SOFTWARE.
///
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Pragma once
///////////////////////////////////////////////////////////////////////////////
#pragma once

///////////////////////////////////////////////////////////////////////////////
// Define the Axiom version
///////////////////////////////////////////////////////////////////////////////
#define AXIOM_VERSION_MAJOR         0
#define AXIOM_VERSION_MINOR         1
#define AXIOM_VERSION_PATCH         0
#define AXIOM_VERSION_IS_RELEASE    false

///////////////////////////////////////////////////////////////////////////////
// Identify the operating system
///////////////////////////////////////////////////////////////////////////////
#if defined(_WIN32) || defined(_WIN64)
    #define AXIOM_SYSTEM_WINDOWS
    #ifndef NOMINMAX
        #define NOMINMAX
    #endif
#elif defined(__APPLE__) || defined(__MACH__)
    #if defined(TARGET_OS_PHONE) || defined(TARGET_IPHONE_SIMULATOR)
        #define AXIOM_SYSTEM_IOS
    #elif defined(TARGET_OS_MAC)
        #define AXIOM_SYSTEM_MACOS
    #else
        #error This Apple OS is not supported by Axiom Library
    #endif
#elif defined(__unix__) || defined(__unix)
    #ifdef __ANDROID__
        #define AXIOM_SYSTEM_ANDROID
    #elif defined(__linux__) || defined(__linux)
        #define AXIOM_SYSTEM_LINUX
    #elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
        #define AXIOM_SYSTEM_FREEBSD
    #elif defined(__OpenBSD__)
        #define AXIOM_SYSTEM_OPENBSD
    #elif defined(__NetBSD__)
        #define AXIOM_SYSTEM_NETBSD
    #else
        #error This Unix OS is not supported by Axiom Library
    #endif
#else
    #error This OS is not supported by Axiom Library
#endif

///////////////////////////////////////////////////////////////////////////////
// Define helpers to create portable import / export macros for each module
///////////////////////////////////////////////////////////////////////////////
#ifndef AXIOM_STATIC
    #ifdef AXIOM_SYSTEM_WINDOWS
        #define AXIOM_API_EXPORT __declspec(dllexport)
        #define AXIOM_API_IMPORT __declspec(dllimport)
        #ifdef _MSC_VER
            #pragma warning(disable: 4251)
        #endif
    #else
        #define AXIOM_API_EXPORT __attribute__((__visibility__("default")))
        #define AXIOM_API_IMPORT __attribute__((__visibility__("default")))
    #endif
#else
    #define AXIOM_API_EXPORT
    #define AXIOM_API_IMPORT
#endif

///////////////////////////////////////////////////////////////////////////////
// Define an helper to create a nodiscard macro
///////////////////////////////////////////////////////////////////////////////
#if __cplusplus >= 201703L
    #define AXIOM_NODISCARD [[nodiscard]]
#else
    #define AXIOM_NODISCARD
#endif

///////////////////////////////////////////////////////////////////////////////
// Define an helper to create a deprecated macro
///////////////////////////////////////////////////////////////////////////////
#if __cplusplus >= 201402L
    #define AXIOM_DEPRECATED [[deprecated]]
#else
    #define AXIOM_DEPRECATED
#endif

///////////////////////////////////////////////////////////////////////////////
// Define a portable check macro to throw an exception on false
///////////////////////////////////////////////////////////////////////////////
#if !defined(NO_CHECK)
    #if !defined(CHECK)
        #define CHECK(expr) if (!(expr)) { throw (std::exception()); }
    #endif
#else
    #define CHECK(expr)
#endif
