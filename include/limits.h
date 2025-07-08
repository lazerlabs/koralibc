/**
 * KoraLibC limits.h - Implementation Limits
 *
 * This header defines implementation limits for integer types and other
 * implementation-defined characteristics as required by the C standard.
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/* ==== Limits of char types ==== */

#define CHAR_BIT           8                    /* bits in a char */

#define SCHAR_MIN          (-128)               /* minimum signed char */
#define SCHAR_MAX          127                  /* maximum signed char */
#define UCHAR_MAX          255                  /* maximum unsigned char */

/* CHAR_MIN and CHAR_MAX depend on whether char is signed or unsigned */
#ifdef __CHAR_UNSIGNED__
#define CHAR_MIN           0
#define CHAR_MAX           UCHAR_MAX
#else
#define CHAR_MIN           SCHAR_MIN
#define CHAR_MAX           SCHAR_MAX
#endif

/* ==== Limits of short types ==== */

#define SHRT_MIN           (-32768)             /* minimum short */
#define SHRT_MAX           32767                /* maximum short */
#define USHRT_MAX          65535                /* maximum unsigned short */

/* ==== Limits of int types ==== */

#define INT_MIN            (-2147483648)        /* minimum int */
#define INT_MAX            2147483647           /* maximum int */
#define UINT_MAX           4294967295U          /* maximum unsigned int */

/* ==== Limits of long types ==== */

#if defined(__LP64__) || defined(_WIN64)
/* 64-bit systems: long is 64-bit */
#define LONG_MIN           (-9223372036854775808L)    /* minimum long */
#define LONG_MAX           9223372036854775807L       /* maximum long */
#define ULONG_MAX          18446744073709551615UL     /* maximum unsigned long */
#else
/* 32-bit systems: long is 32-bit */
#define LONG_MIN           (-2147483648L)       /* minimum long */
#define LONG_MAX           2147483647L          /* maximum long */
#define ULONG_MAX          4294967295UL         /* maximum unsigned long */
#endif

/* ==== Limits of long long types ==== */

#define LLONG_MIN          (-9223372036854775808LL)   /* minimum long long */
#define LLONG_MAX          9223372036854775807LL      /* maximum long long */
#define ULLONG_MAX         18446744073709551615ULL    /* maximum unsigned long long */

/* ==== Multibyte character limits ==== */

#define MB_LEN_MAX         4                    /* maximum bytes in multibyte char */

/* ==== POSIX-compatible aliases (commonly used) ==== */

#ifndef _POSIX_SOURCE
#define SSIZE_MAX          LONG_MAX             /* maximum ssize_t */
#endif

/* ==== Floating-point representation limits ==== */
/* Note: These are defined here for completeness, though float.h is more appropriate */

#define FLT_RADIX          2                    /* radix of floating-point representation */

/* ==== Architecture-specific limits ==== */

#if defined(__aarch64__) || defined(__arm64__)
#define WORD_BIT           64                   /* bits in a word (pointer size) */
#define PTR_SIZE           8                    /* size of pointer in bytes */
#elif defined(__x86_64__) || defined(_M_X64)
#define WORD_BIT           64                   /* bits in a word (pointer size) */
#define PTR_SIZE           8                    /* size of pointer in bytes */
#elif defined(__i386__) || defined(_M_IX86) || defined(__arm__)
#define WORD_BIT           32                   /* bits in a word (pointer size) */
#define PTR_SIZE           4                    /* size of pointer in bytes */
#else
/* Default to 32-bit */
#define WORD_BIT           32                   /* bits in a word (pointer size) */
#define PTR_SIZE           4                    /* size of pointer in bytes */
#endif

/* ==== KoraOS-specific limits ==== */

#define KORA_PATH_MAX      4096                 /* maximum path length */
#define KORA_NAME_MAX      255                  /* maximum filename length */
#define KORA_OPEN_MAX      1024                 /* maximum open files per process */

#ifdef __cplusplus
}
#endif 
