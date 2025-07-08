/**
 * KoraLibC gets.c - gets implementation
 */

#include "stdio_internal.h"

char *gets(char *s) {
  /* NOTE: gets() is unsafe and deprecated, but included for completeness */
  if (!s)
    return NULL;

  init_stdio();

  char *ptr = s;
  int c;

  while ((c = getc(stdin)) != EOF && c != '\n') {
    *ptr++ = c;
  }

  if (c == EOF && ptr == s) {
    return NULL; /* No characters read */
  }

  *ptr = '\0';
  return s;
}
