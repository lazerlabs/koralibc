/**
 * stddef.h - Standard type definitions
 * 
 * This header is required by the C standard (C99 Section 7.17)
 * and must be available even in freestanding implementations.
 * 
 * Defines fundamental types and macros used throughout the C standard library.
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/* Include our platform-specific type definitions */
#include "kora/sys/types.h"

/* 
 * The C standard requires stddef.h to define these types.
 * We get them from our sys/types.h to maintain consistency.
 */

/* Size type - result of sizeof operator */
#ifndef _SIZE_T_DEFINED
#define _SIZE_T_DEFINED
/* size_t is defined in kora/sys/types.h */
#endif

/* Signed integer type for pointer arithmetic */
#ifndef _PTRDIFF_T_DEFINED  
#define _PTRDIFF_T_DEFINED
/* ptrdiff_t is defined in kora/sys/types.h */
#endif

/* Wide character type */
#ifndef _WCHAR_T_DEFINED
#define _WCHAR_T_DEFINED
/* wchar_t is defined in kora/sys/types.h */
#endif

/* Null pointer constant */
#ifndef NULL
#if defined(__cplusplus)
#define NULL               0
#else
#define NULL               ((void*)0)
#endif
#endif

/* Offset of member in structure */
#ifndef offsetof
#define offsetof(type, member) __builtin_offsetof(type, member)
#endif

#ifdef __cplusplus
}
#endif 
