/**
 * KoraLibC scanf.c - scanf implementation
 */

#include "stdio_internal.h"
#include <stdarg.h>

extern int vfscanf(FILE *stream, const char *format, va_list ap);

int scanf(const char *format, ...) {
    va_list ap;
    va_start(ap, format);
    int r = vfscanf(stdin, format, ap);
    va_end(ap);
    return r;
}
