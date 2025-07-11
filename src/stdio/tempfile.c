/**
 * KoraLibC tempfile.c - temporary file stubs
 */

#include "stdio_internal.h"

FILE *tmpfile(void) { return NULL; }
char *tmpnam(char *s) {
  (void)s;
  return NULL;
}
