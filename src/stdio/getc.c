/**
 * KoraLibC getc.c - getc implementation
 */

#include "stdio_internal.h"

int getc(FILE *stream) {
  if (!stream || stream->error_flag || stream->eof_flag) {
    return EOF;
  }

  if (stream->has_unget) {
    stream->has_unget = 0;
    return stream->ungot_char;
  }

  char c;
  int result = sys_read(stream->fd, &c, 1);

  if (result == 0) {
    stream->eof_flag = 1;
    return EOF;
  } else if (result < 0) {
    stream->error_flag = 1;
    return EOF;
  }

  stream->position++;
  return (unsigned char)c;
}
