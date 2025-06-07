#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/*
 * KoraOS Type Definitions
 * 
 * Target Architecture: ARM64 (AARCH64) - Raspberry Pi 3/4/5
 * Data Model: LP64 (Long and Pointer are 64-bit)
 * 
 * These types are defined to match our target platform exactly.
 * When cross-compiling or testing on other systems, we verify
 * that the host types match our target expectations.
 */

/* Basic signed and unsigned integer types */
typedef signed char        int8_t;
typedef unsigned char      uint8_t;
typedef signed short       int16_t;
typedef unsigned short     uint16_t;

/* 32-bit types - int is 32-bit on AARCH64 */
typedef signed int         int32_t;
typedef unsigned int       uint32_t;

/* 64-bit types - long is 64-bit on AARCH64 (LP64 model) */
typedef signed long        int64_t;
typedef unsigned long      uint64_t;

/* Size and pointer difference types - 64-bit on AARCH64 */
typedef unsigned long      size_t;
typedef signed long        ssize_t;
typedef signed long        ptrdiff_t;

/* Character types */
typedef int                wchar_t;
typedef uint16_t           char16_t;
typedef uint32_t           char32_t;

/* Boolean type */
#ifndef __cplusplus
typedef int                bool;
#define true               1
#define false              0
#endif

/* NULL pointer */
#ifndef NULL
#ifdef __cplusplus
#define NULL               0
#else
#define NULL               ((void*)0)
#endif
#endif

/* File descriptor type */
typedef int                fd_t;

/* Process and user ID types */
typedef int                pid_t;
typedef int                uid_t;
typedef int                gid_t;

/* Time types */
typedef long               time_t;
typedef long               clock_t;

/* File system types */
typedef unsigned long      ino_t;    /* inode number */
typedef unsigned long      dev_t;    /* device number */
typedef unsigned short     mode_t;   /* file mode */
typedef unsigned short     nlink_t;  /* link count */
typedef long               off_t;    /* file offset */
typedef long               blksize_t;/* block size */
typedef long               blkcnt_t; /* block count */

/* 
 * Compile-time assertions to verify host system matches our target expectations
 * 
 * These will cause compilation to fail if the host system's type sizes
 * don't match what we expect for AARCH64. This ensures consistency
 * between development/testing environment and target platform.
 */
typedef char _static_assert_int8_size[(sizeof(int8_t) == 1) ? 1 : -1];
typedef char _static_assert_int16_size[(sizeof(int16_t) == 2) ? 1 : -1]; 
typedef char _static_assert_int32_size[(sizeof(int32_t) == 4) ? 1 : -1];
typedef char _static_assert_int64_size[(sizeof(int64_t) == 8) ? 1 : -1];
typedef char _static_assert_size_t_size[(sizeof(size_t) == 8) ? 1 : -1];
typedef char _static_assert_ptr_size[(sizeof(void*) == 8) ? 1 : -1];

#ifndef __aarch64__
/* Warning: We're not compiling for AARCH64 target */
/* This is OK for development/testing, but final binary must be AARCH64 */
#pragma message "Warning: Compiling KoraLibC for non-AARCH64 host. Types verified for compatibility."
#endif

#ifdef __cplusplus
}
#endif 
