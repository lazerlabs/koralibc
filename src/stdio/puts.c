/**
 * KoraLibC puts.c - puts implementation
 */

#include "stdio_internal.h"

int puts(const char *s) {
  if (!s)
    return EOF;

  init_stdio();

  /* Write the string */
  while (*s) {
    if (putc(*s, stdout) == EOF) {
      return EOF;
    }
    s++;
  }

  /* Write newline */
  if (putc('\n', stdout) == EOF) {
    return EOF;
  }

  return 1; /* Non-negative return for success */
}
