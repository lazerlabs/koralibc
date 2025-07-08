/**
 * KoraLibC putc.c - putc implementation
 */

#include "stdio_internal.h"

int putc(int c, FILE *stream) {
  if (!stream || stream->error_flag) {
    return EOF;
  }

  char ch = (char)c;
  int result = sys_write(stream->fd, &ch, 1);

  if (result != 1) {
    stream->error_flag = 1;
    return EOF;
  }

  stream->position++;
  return (unsigned char)c;
}
