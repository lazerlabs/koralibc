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

  return (result == 0) ? 0 : EOF;
}
