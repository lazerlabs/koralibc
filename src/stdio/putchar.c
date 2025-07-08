/**
 * KoraLibC putchar.c - putchar implementation
 */

#include "stdio_internal.h"

int putchar(int c) {
  init_stdio();
  return putc(c, stdout);
}
