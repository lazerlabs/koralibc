/**
 * KoraLibC fprintf.c - fprintf implementation
 */

#include "stdio_internal.h"
#include <stdarg.h>

int fprintf(FILE *stream, const char *format, ...) {
  va_list ap;
  va_start(ap, format);
  int result = vfprintf(stream, format, ap);
  va_end(ap);
  return result;
}
