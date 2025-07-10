/**
 * KoraLibC fscanf.c - fscanf implementation
 */

#include "stdio_internal.h"
#include <stdarg.h>

extern int vfscanf(FILE *stream, const char *format, va_list ap);

int fscanf(FILE *stream, const char *format, ...) {
    va_list ap;
    va_start(ap, format);
    int r = vfscanf(stream, format, ap);
    va_end(ap);
    return r;
}
