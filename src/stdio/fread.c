/**
 * KoraLibC fread.c - fread implementation
 */

#include "stdio_internal.h"

size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream) {
  if (!ptr || !stream || size == 0 || nmemb == 0)
    return 0;

  size_t total_bytes = size * nmemb;
  size_t bytes_read = 0;
  char *buffer = (char *)ptr;

  while (bytes_read < total_bytes) {
    int result =
        sys_read(stream->fd, buffer + bytes_read, total_bytes - bytes_read);

    if (result == 0) {
      stream->eof_flag = 1;
      break;
    } else if (result < 0) {
      stream->error_flag = 1;
      break;
    }

    bytes_read += result;
    stream->position += result;
  }

  return bytes_read / size; /* Return number of complete elements read */
}
