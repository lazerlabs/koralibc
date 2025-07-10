/**
 * KoraLibC sscanf.c - sscanf implementation
 */

#include "stdio_internal.h"
#include <stdarg.h>

extern int vsscanf(const char *str, const char *format, va_list ap);

int sscanf(const char *str, const char *format, ...) {
    va_list ap;
    va_start(ap, format);
    int r = vsscanf(str, format, ap);
    va_end(ap);
    return r;
}
