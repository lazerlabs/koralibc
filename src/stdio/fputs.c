/**
 * KoraLibC fputs.c - fputs implementation
 */

#include "stdio_internal.h"

int fputs(const char *s, FILE *stream) {
  if (!s || !stream)
    return EOF;

  while (*s) {
    if (putc(*s, stream) == EOF) {
      return EOF;
    }
    s++;
  }

  return 1;
}
