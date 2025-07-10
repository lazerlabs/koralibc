/**
 * KoraLibC fclose.c - fclose implementation
 */

#include "stdio_internal.h"

int fclose(FILE *stream) {
  if (!stream || stream->fd < 0)
    return EOF;

  /* Don't close standard streams */
  if (stream == stdin || stream == stdout || stream == stderr) {
    return 0;
  }

  int result = sys_close(stream->fd);

  /* Mark as closed */
  stream->fd = -1;
  stream->eof_flag = 0;
  stream->error_flag = 0;
  stream->position = 0;
  stream->buffer = NULL;
  stream->buffer_size = 0;
  stream->buffer_pos = 0;
  stream->buffer_end = 0;
  stream->buffer_mode = 0;
  stream->ungot_char = 0;
  stream->has_unget = 0;

  return (result == 0) ? 0 : EOF;
}
