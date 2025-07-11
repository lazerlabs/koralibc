/**
 * KoraLibC fremove.c - remove and rename implementations
 */

#include "stdio_internal.h"

int remove(const char *filename) {
  return filename ? sys_unlink(filename) : -1;
}

int rename(const char *old_filename, const char *new_filename) {
  (void)old_filename;
  (void)new_filename;
  return -1; /* TODO: Implement */
}
