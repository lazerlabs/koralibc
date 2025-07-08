/**
 * KoraLibC getchar.c - getchar implementation
 */

#include "stdio_internal.h"

int getchar(void) {
  init_stdio();
  return getc(stdin);
}
