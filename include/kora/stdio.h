/**
 * KoraLibC stdio.h - Standard Input/Output Library
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdarg.h>

#define EOF (-1)
#define STDIN_FILENO  0
#define STDOUT_FILENO 1  
#define STDERR_FILENO 2
#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2
#define BUFSIZ 8192
#define FOPEN_MAX 20
#define FILENAME_MAX 4096

typedef struct kora_file FILE;
typedef long fpos_t;

extern FILE *stdin;
extern FILE *stdout; 
extern FILE *stderr;

/* Character I/O */
int putchar(int c);
int getchar(void);
int putc(int c, FILE *stream);
int getc(FILE *stream);
int fputc(int c, FILE *stream);
int fgetc(FILE *stream);
int ungetc(int c, FILE *stream);

/* String I/O */
int puts(const char *s);
char *gets(char *s);
char *fgets(char *s, int size, FILE *stream);
int fputs(const char *s, FILE *stream);

/* Formatted output */
int printf(const char *format, ...);
int fprintf(FILE *stream, const char *format, ...);
int sprintf(char *str, const char *format, ...);
int snprintf(char *str, size_t size, const char *format, ...);
int vprintf(const char *format, va_list ap);
int vfprintf(FILE *stream, const char *format, va_list ap);
int vsprintf(char *str, const char *format, va_list ap);
int vsnprintf(char *str, size_t size, const char *format, va_list ap);

/* Formatted input */
int scanf(const char *format, ...);
int fscanf(FILE *stream, const char *format, ...);
int sscanf(const char *str, const char *format, ...);

/* File operations */
FILE *fopen(const char *filename, const char *mode);
FILE *freopen(const char *filename, const char *mode, FILE *stream);
int fclose(FILE *stream);
size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
int fseek(FILE *stream, long offset, int whence);
long ftell(FILE *stream);
void rewind(FILE *stream);
int fgetpos(FILE *stream, fpos_t *pos);
int fsetpos(FILE *stream, const fpos_t *pos);
void setbuf(FILE *stream, char *buf);
int setvbuf(FILE *stream, char *buf, int mode, size_t size);

/* File status */
int feof(FILE *stream);
int ferror(FILE *stream);
void clearerr(FILE *stream);
int fflush(FILE *stream);

/* File management */
int remove(const char *filename);
int rename(const char *old_filename, const char *new_filename);
FILE *tmpfile(void);
char *tmpnam(char *s);

/* Error handling */
void perror(const char *s);

#ifdef __cplusplus
}
#endif
