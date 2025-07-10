/**
 * KoraLibC stdio_internal.h - Internal definitions for stdio implementation
 */

#pragma once

#include <stddef.h>
#include "../../include/kora/stdio.h"

/* KoraLayer syscall declarations */
extern int sys_putc(char c);
extern int sys_getc(void);
extern int sys_open(const char *path, int flags);
extern int sys_close(int fd);
extern int sys_read(int fd, void *buf, size_t count);
extern int sys_write(int fd, const void *buf, size_t count);
extern long sys_seek(int fd, long offset, int whence);
extern int sys_unlink(const char *path);

/* KoraLayer flag mappings */
#define KORA_O_RDONLY 0x0001
#define KORA_O_WRONLY 0x0002
#define KORA_O_RDWR (KORA_O_RDONLY | KORA_O_WRONLY)
#define KORA_O_CREAT 0x0100
#define KORA_O_TRUNC 0x0200
#define KORA_O_APPEND 0x0400

#define KORA_SEEK_SET 0
#define KORA_SEEK_CUR 1
#define KORA_SEEK_END 2

/* FILE structure implementation */
struct kora_file {
    int fd;             /* File descriptor */
    int flags;          /* File open flags */
    int eof_flag;       /* End-of-file flag */
    int error_flag;     /* Error flag */
    long position;      /* Current file position */
    char *buffer;       /* I/O buffer */
    size_t buffer_size; /* Buffer size */
    size_t buffer_pos;  /* Position in buffer */
    size_t buffer_end;  /* End of valid data in buffer */
    int buffer_mode;    /* Buffering mode */
    int ungot_char;     /* Character pushed back with ungetc */
    int has_unget;      /* Flag indicating ungot_char is valid */
};

/* Internal functions */
void init_stdio(void);
FILE *alloc_file(void);
int int_to_str(int value, char *str, int base);

/* File table */
extern FILE file_table[FOPEN_MAX];
extern int file_table_init; 
