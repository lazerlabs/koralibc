/**
 * KoraLibC fopen.c - fopen implementation
 */

#include "stdio_internal.h"

FILE *fopen(const char *filename, const char *mode) {
  if (!filename || !mode)
    return NULL;

  init_stdio();

  FILE *file = alloc_file();
  if (!file)
    return NULL;

  /* Parse mode string */
  int flags = 0;
  switch (mode[0]) {
  case 'r':
    flags = KORA_O_RDONLY;
    if (mode[1] == '+')
      flags = KORA_O_RDWR;
    break;
  case 'w':
    flags = KORA_O_WRONLY | KORA_O_CREAT | KORA_O_TRUNC;
    if (mode[1] == '+')
      flags = KORA_O_RDWR | KORA_O_CREAT | KORA_O_TRUNC;
    break;
  case 'a':
    flags = KORA_O_WRONLY | KORA_O_CREAT | KORA_O_APPEND;
    if (mode[1] == '+')
      flags = KORA_O_RDWR | KORA_O_CREAT | KORA_O_APPEND;
    break;
  default:
    return NULL;
  }

  int fd = sys_open(filename, flags);
  if (fd < 0) {
    return NULL;
  }

  /* Initialize FILE structure */
  file->fd = fd;
  file->flags = flags;
  file->eof_flag = 0;
  file->error_flag = 0;
  file->position = 0;
  file->buffer = NULL;
  file->buffer_size = 0;
  file->buffer_pos = 0;
  file->buffer_end = 0;
  file->buffer_mode = 0;
  file->ungot_char = 0;
  file->has_unget = 0;

  return file;
}
