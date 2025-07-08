/**
 * KoraLibC errno.h - Error Number Definitions
 *
 * This header provides error number definitions and the errno variable
 * for error reporting. This is essential for proper error handling in
 * a C library implementation.
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/**
 * errno - Global error number variable
 * 
 * This variable is set by system calls and library functions to indicate
 * what error occurred. It should be checked immediately after a function
 * that might set it, as subsequent function calls may overwrite it.
 */
extern int errno;

/* ==== Standard POSIX Error Codes ==== */

#define EPERM              1    /* Operation not permitted */
#define ENOENT             2    /* No such file or directory */
#define ESRCH              3    /* No such process */
#define EINTR              4    /* Interrupted system call */
#define EIO                5    /* I/O error */
#define ENXIO              6    /* No such device or address */
#define E2BIG              7    /* Argument list too long */
#define ENOEXEC            8    /* Exec format error */
#define EBADF              9    /* Bad file number */
#define ECHILD            10    /* No child processes */
#define EAGAIN            11    /* Try again */
#define ENOMEM            12    /* Out of memory */
#define EACCES            13    /* Permission denied */
#define EFAULT            14    /* Bad address */
#define ENOTBLK           15    /* Block device required */
#define EBUSY             16    /* Device or resource busy */
#define EEXIST            17    /* File exists */
#define EXDEV             18    /* Cross-device link */
#define ENODEV            19    /* No such device */
#define ENOTDIR           20    /* Not a directory */
#define EISDIR            21    /* Is a directory */
#define EINVAL            22    /* Invalid argument */
#define ENFILE            23    /* File table overflow */
#define EMFILE            24    /* Too many open files */
#define ENOTTY            25    /* Not a typewriter */
#define ETXTBSY           26    /* Text file busy */
#define EFBIG             27    /* File too large */
#define ENOSPC            28    /* No space left on device */
#define ESPIPE            29    /* Illegal seek */
#define EROFS             30    /* Read-only file system */
#define EMLINK            31    /* Too many links */
#define EPIPE             32    /* Broken pipe */
#define EDOM              33    /* Math argument out of domain of func */
#define ERANGE            34    /* Math result not representable */

/* ==== Additional Error Codes ==== */

#define EDEADLK           35    /* Resource deadlock would occur */
#define ENAMETOOLONG      36    /* File name too long */
#define ENOLCK            37    /* No record locks available */
#define ENOSYS            38    /* Function not implemented */
#define ENOTEMPTY         39    /* Directory not empty */
#define ELOOP             40    /* Too many symbolic links encountered */
#define EWOULDBLOCK       EAGAIN /* Operation would block */
#define ENOMSG            42    /* No message of desired type */
#define EIDRM             43    /* Identifier removed */
#define ECHRNG            44    /* Channel number out of range */
#define EL2NSYNC          45    /* Level 2 not synchronized */
#define EL3HLT            46    /* Level 3 halted */
#define EL3RST            47    /* Level 3 reset */
#define ELNRNG            48    /* Link number out of range */
#define EUNATCH           49    /* Protocol driver not attached */
#define ENOCSI            50    /* No CSI structure available */
#define EL2HLT            51    /* Level 2 halted */

/* ==== Network-related Error Codes ==== */

#define EADDRINUSE        98    /* Address already in use */
#define EADDRNOTAVAIL     99    /* Cannot assign requested address */
#define ENETDOWN         100    /* Network is down */
#define ENETUNREACH      101    /* Network is unreachable */
#define ENETRESET        102    /* Network dropped connection because of reset */
#define ECONNABORTED     103    /* Software caused connection abort */
#define ECONNRESET       104    /* Connection reset by peer */
#define ENOBUFS          105    /* No buffer space available */
#define EISCONN          106    /* Transport endpoint is already connected */
#define ENOTCONN         107    /* Transport endpoint is not connected */
#define ESHUTDOWN        108    /* Cannot send after transport endpoint shutdown */
#define ETOOMANYREFS     109    /* Too many references: cannot splice */
#define ETIMEDOUT        110    /* Connection timed out */
#define ECONNREFUSED     111    /* Connection refused */
#define EHOSTDOWN        112    /* Host is down */
#define EHOSTUNREACH     113    /* No route to host */
#define EALREADY         114    /* Operation already in progress */
#define EINPROGRESS      115    /* Operation now in progress */

/* ==== KoraOS-specific Error Codes ==== */

#define EKORA_BASE       200    /* Base for KoraOS-specific errors */
#define EKORA_INVALID    201    /* Invalid KoraOS operation */
#define EKORA_NOTIMPL    202    /* KoraOS feature not implemented */
#define EKORA_RESOURCES  203    /* KoraOS resource exhaustion */
#define EKORA_HARDWARE   204    /* KoraOS hardware error */

/* ==== Maximum Error Number ==== */

#define EMAXERRNO        255    /* Maximum error number */

/**
 * Helper macros for error checking
 */
#define KORA_ERRNO_SET(err)    (errno = (err))
#define KORA_ERRNO_CLEAR()     (errno = 0)
#define KORA_ERRNO_CHECK(err)  (errno == (err))

#ifdef __cplusplus
}
#endif 
