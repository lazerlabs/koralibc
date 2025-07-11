/**
 * KoraLibC fstatus.c - status and flush functions
 */

#include "stdio_internal.h"

int feof(FILE *stream) { return stream ? stream->eof_flag : 0; }
int ferror(FILE *stream) { return stream ? stream->error_flag : 0; }
void clearerr(FILE *stream) {
  if (stream) {
    stream->eof_flag = 0;
    stream->error_flag = 0;
  }
}
int fflush(FILE *stream) {
  (void)stream;
  return 0;
}
