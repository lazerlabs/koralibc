/**
 * KoraLibC vfprintf.c - vfprintf implementation
 */

#include "stdio_internal.h"
#include <stdarg.h>

/* Basic printf implementation - supports %d, %s, %c, %x, %% */
int vfprintf(FILE *stream, const char *format, va_list ap) {
  if (!stream || !format)
    return -1;

  int count = 0;
  const char *ptr = format;

  while (*ptr) {
    if (*ptr != '%') {
      if (putc(*ptr, stream) == EOF)
        return -1;
      count++;
      ptr++;
      continue;
    }

    ptr++; /* Skip '%' */

    switch (*ptr) {
    case 'd': {
      int value = va_arg(ap, int);
      char buffer[32];
      int len = int_to_str(value, buffer, 10);
      for (int i = 0; i < len; i++) {
        if (putc(buffer[i], stream) == EOF)
          return -1;
        count++;
      }
      break;
    }
    case 'x': {
      int value = va_arg(ap, int);
      char buffer[32];
      int len = int_to_str(value, buffer, 16);
      for (int i = 0; i < len; i++) {
        if (putc(buffer[i], stream) == EOF)
          return -1;
        count++;
      }
      break;
    }
    case 'c': {
      int value = va_arg(ap, int);
      if (putc(value, stream) == EOF)
        return -1;
      count++;
      break;
    }
    case 's': {
      const char *str = va_arg(ap, const char *);
      if (!str)
        str = "(null)";
      while (*str) {
        if (putc(*str, stream) == EOF)
          return -1;
        count++;
        str++;
      }
      break;
    }
    case '%': {
      if (putc('%', stream) == EOF)
        return -1;
      count++;
      break;
    }
    default: {
      /* Unknown format specifier, just print it */
      if (putc('%', stream) == EOF)
        return -1;
      if (putc(*ptr, stream) == EOF)
        return -1;
      count += 2;
      break;
    }
    }
    ptr++;
  }

  return count;
}
