/**
 * KoraLibC stdbool.h - Boolean Type and Values
 *
 * This header provides the boolean type and related macros as specified
 * by the C99 standard. This makes boolean operations more readable and
 * standardized in C code.
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/* Only define bool if we're in C mode and not C++ */
#ifndef __cplusplus

/**
 * bool - Boolean type
 * 
 * In C99 and later, _Bool is a built-in type. We provide a more
 * convenient alias as 'bool' for better readability.
 */
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
/* C99 and later have _Bool built-in */
#define bool _Bool
#else
/* Pre-C99: Define bool as an unsigned char */
typedef unsigned char bool;
#endif

/**
 * true - Boolean true value
 */
#define true 1

/**
 * false - Boolean false value
 */
#define false 0

#else
/* In C++, bool is a built-in type, but we still define the macros */
#define true true
#define false false
#endif /* __cplusplus */

/**
 * __bool_true_false_are_defined - Standard compliance macro
 * 
 * This macro indicates that bool, true, and false are defined.
 * Some code checks for this macro to determine boolean support.
 */
#define __bool_true_false_are_defined 1

#ifdef __cplusplus
}
#endif 
