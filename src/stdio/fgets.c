/**
 * KoraLibC fgets.c - fgets implementation
 */

#include "stdio_internal.h"

char *fgets(char *s, int size, FILE *stream) {
  if (!s || size <= 0 || !stream)
    return NULL;

  char *ptr = s;
  int c;
  int count = 0;

  while (count < size - 1 && (c = getc(stream)) != EOF) {
    *ptr++ = c;
    count++;

    if (c == '\n')
      break;
  }

  if (count == 0 && c == EOF) {
    return NULL; /* No characters read */
  }

  *ptr = '\0';
  return s;
}
