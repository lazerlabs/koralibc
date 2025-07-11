/**
 * KoraLibC perror.c - perror implementation
 */

#include "stdio_internal.h"

void perror(const char *s) {
  init_stdio();
  if (s && *s) {
    fputs(s, stderr);
    fputs(": ", stderr);
  }
  fputs("Error occurred\n", stderr);
}
