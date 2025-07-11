/**
 * KoraLibC fpos.c - file position functions
 */

#include "stdio_internal.h"

int fgetpos(FILE *stream, fpos_t *pos) {
  if (!stream || !pos)
    return -1;
  *pos = stream->position;
  return 0;
}

int fsetpos(FILE *stream, const fpos_t *pos) {
  if (!stream || !pos)
    return -1;
  return fseek(stream, *pos, SEEK_SET);
}
