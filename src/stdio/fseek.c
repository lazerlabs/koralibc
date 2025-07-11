/**
 * KoraLibC fseek.c - fseek, ftell, and rewind implementations
 */

#include "stdio_internal.h"

int fseek(FILE *stream, long offset, int whence) {
  if (!stream)
    return -1;

  int kora_whence;
  switch (whence) {
  case SEEK_SET:
    kora_whence = KORA_SEEK_SET;
    break;
  case SEEK_CUR:
    kora_whence = KORA_SEEK_CUR;
    break;
  case SEEK_END:
    kora_whence = KORA_SEEK_END;
    break;
  default:
    return -1;
  }

  long result = sys_seek(stream->fd, offset, kora_whence);
  if (result < 0) {
    stream->error_flag = 1;
    return -1;
  }

  stream->position = result;
  stream->eof_flag = 0;
  return 0;
}

long ftell(FILE *stream) { return stream ? stream->position : -1L; }

void rewind(FILE *stream) {
  if (stream) {
    fseek(stream, 0L, SEEK_SET);
    stream->error_flag = 0;
  }
}
