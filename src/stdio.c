/**
 * KoraLibC stdio.c - Standard Input/Output Library Implementation
 *
 * This file includes all the individual stdio function implementations
 * from the stdio/ directory to provide a single compilation unit.
 */

#include <stdarg.h>
#include <stddef.h>

/* Include all individual function implementations */
#include "stdio/stdio_internal.c"

/* Character I/O */
#include "stdio/getc.c"
#include "stdio/getchar.c"
#include "stdio/putc.c"
#include "stdio/putchar.c"

/* String I/O */
#include "stdio/fgets.c"
#include "stdio/fputs.c"
#include "stdio/gets.c"
#include "stdio/puts.c"

/* Formatted output */
#include "stdio/fprintf.c"
#include "stdio/printf.c"
#include "stdio/vfprintf.c"
#include "stdio/vprintf.c"

/* File operations */
#include "stdio/fclose.c"
#include "stdio/fopen.c"
#include "stdio/fread.c"
#include "stdio/fwrite.c"

/* Stub implementations for unimplemented functions */

int sprintf(char *str, const char *format, ...) {
  (void)str;
  (void)format;
  return -1; /* TODO: Implement */
}

int snprintf(char *str, size_t size, const char *format, ...) {
  (void)str;
  (void)size;
  (void)format;
  return -1; /* TODO: Implement */
}

int vsprintf(char *str, const char *format, va_list ap) {
  (void)str;
  (void)format;
  (void)ap;
  return -1; /* TODO: Implement */
}

int vsnprintf(char *str, size_t size, const char *format, va_list ap) {
  (void)str;
  (void)size;
  (void)format;
  (void)ap;
  return -1; /* TODO: Implement */
}

/* File operations stubs */

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

/* File status functions */
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

/* File management stubs */
int remove(const char *filename) {
  return filename ? sys_unlink(filename) : -1;
}

int rename(const char *old_filename, const char *new_filename) {
  (void)old_filename;
  (void)new_filename;
  return -1; /* TODO: Implement */
}

/* Position functions */
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

/* Formatted input stubs */
int scanf(const char *format, ...) {
  (void)format;
  return EOF;
}
int fscanf(FILE *stream, const char *format, ...) {
  (void)stream;
  (void)format;
  return EOF;
}
int sscanf(const char *str, const char *format, ...) {
  (void)str;
  (void)format;
  return EOF;
}

/* Temporary file stubs */
FILE *tmpfile(void) { return NULL; }
char *tmpnam(char *s) {
  (void)s;
  return NULL;
}

/* Error handling */
void perror(const char *s) {
  init_stdio();
  if (s && *s) {
    fputs(s, stderr);
    fputs(": ", stderr);
  }
  fputs("Error occurred\n", stderr);
}
