/**
 * KoraLibC vprintf.c - vprintf implementation
 */

#include "stdio_internal.h"
#include <stdarg.h>

int vprintf(const char *format, va_list ap) {
  init_stdio();
  return vfprintf(stdout, format, ap);
}
