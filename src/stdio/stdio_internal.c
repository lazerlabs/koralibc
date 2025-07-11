/**
 * KoraLibC stdio_internal.c - Core stdio implementation
 */

#include "stdio_internal.h"

/* File table for managing open files */
FILE file_table[FOPEN_MAX];
int file_table_init = 0;

/* Standard streams */
FILE *stdin = NULL;
FILE *stdout = NULL;
FILE *stderr = NULL;

/* Initialize standard streams */
void init_stdio(void) {
  if (file_table_init)
    return;

  // Initialize file table
  for (int i = 0; i < FOPEN_MAX; i++) {
    file_table[i].fd = -1;
    file_table[i].eof_flag = 0;
    file_table[i].error_flag = 0;
    file_table[i].position = 0;
    file_table[i].buffer = NULL;
    file_table[i].buffer_size = 0;
    file_table[i].buffer_pos = 0;
    file_table[i].buffer_end = 0;
    file_table[i].buffer_mode = 0;
    file_table[i].ungot_char = 0;
    file_table[i].has_unget = 0;
  }

  // Set up standard streams
  stdin = &file_table[0];
  stdin->fd = STDIN_FILENO;
  stdin->flags = KORA_O_RDONLY;
  stdin->eof_flag = 0;
  stdin->error_flag = 0;
  stdin->position = 0;
  stdin->buffer = NULL;
  stdin->buffer_size = 0;
  stdin->buffer_pos = 0;
  stdin->buffer_end = 0;
  stdin->buffer_mode = 0;
  stdin->ungot_char = 0;
  stdin->has_unget = 0;

  stdout = &file_table[1];
  stdout->fd = STDOUT_FILENO;
  stdout->flags = KORA_O_WRONLY;
  stdout->eof_flag = 0;
  stdout->error_flag = 0;
  stdout->position = 0;
  stdout->buffer = NULL;
  stdout->buffer_size = 0;
  stdout->buffer_pos = 0;
  stdout->buffer_end = 0;
  stdout->buffer_mode = 0;
  stdout->ungot_char = 0;
  stdout->has_unget = 0;

  stderr = &file_table[2];
  stderr->fd = STDERR_FILENO;
  stderr->flags = KORA_O_WRONLY;
  stderr->eof_flag = 0;
  stderr->error_flag = 0;
  stderr->position = 0;
  stderr->buffer = NULL;
  stderr->buffer_size = 0;
  stderr->buffer_pos = 0;
  stderr->buffer_end = 0;
  stderr->buffer_mode = 0;
  stderr->ungot_char = 0;
  stderr->has_unget = 0;

  file_table_init = 1;
}

/* Find free slot in file table */
FILE *alloc_file(void) {
  init_stdio();

  for (int i = 3; i < FOPEN_MAX; i++) { /* Skip stdin, stdout, stderr */
    if (file_table[i].fd == -1) {
      return &file_table[i];
    }
  }
  return NULL;
}

/* Simple integer to string conversion */
int int_to_str(int value, char *str, int base) {
  if (base < 2 || base > 36)
    return 0;

  char *ptr = str;
  int is_negative = 0;

  if (value == 0) {
    *ptr++ = '0';
    *ptr = '\0';
    return 1;
  }

  if (value < 0 && base == 10) {
    is_negative = 1;
    value = -value;
  }

  while (value != 0) {
    int remainder = value % base;
    *ptr++ = (remainder < 10) ? (remainder + '0') : (remainder - 10 + 'a');
    value = value / base;
  }

  if (is_negative) {
    *ptr++ = '-';
  }

  *ptr = '\0';

  /* Reverse the string */
  int len = ptr - str;
  for (int i = 0; i < len / 2; i++) {
    char temp = str[i];
    str[i] = str[len - 1 - i];
    str[len - 1 - i] = temp;
  }

  return len;
}
