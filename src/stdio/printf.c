/**
 * KoraLibC printf.c - printf implementation
 */

#include "stdio_internal.h"
#include <stdarg.h>

int printf(const char *format, ...) {
  init_stdio();
  va_list ap;
  va_start(ap, format);
  int result = vfprintf(stdout, format, ap);
  va_end(ap);
  return result;
}
