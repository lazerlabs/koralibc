/**
 * KoraLibC fwrite.c - fwrite implementation
 */

#include "stdio_internal.h"

size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream) {
  if (!ptr || !stream || size == 0 || nmemb == 0)
    return 0;

  size_t total_bytes = size * nmemb;
  size_t bytes_written = 0;
  const char *buffer = (const char *)ptr;

  while (bytes_written < total_bytes) {
    int result = sys_write(stream->fd, buffer + bytes_written,
                           total_bytes - bytes_written);

    if (result <= 0) {
      stream->error_flag = 1;
      break;
    }

    bytes_written += result;
    stream->position += result;
  }

  return bytes_written / size;
}
