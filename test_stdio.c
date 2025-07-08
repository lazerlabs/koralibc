/**
 * Simple test program for KoraLibC stdio implementation
 */

#include <fcntl.h>
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

/* Temporary definitions until headers are properly structured */
#define EOF (-1)
#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2
#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2
#define BUFSIZ 8192
#define FOPEN_MAX 20
#define FILENAME_MAX 4096
#define NULL ((void *)0)

typedef struct kora_file FILE;
typedef long fpos_t;

/* Function declarations */
int putchar(int c);
int puts(const char *s);
int printf(const char *format, ...);

/* KoraLayer syscall stubs for testing */
int sys_putc(char c) {
  /* Simple stub - just write to stdout using write syscall */
  return (int)write(1, &c, 1);
}

int sys_getc(void) {
  char c;
  if (read(0, &c, 1) == 1) {
    return (unsigned char)c;
  }
  return EOF;
}

int sys_open(const char *path, int flags) {
  /* TODO: Map KoraLayer flags to POSIX flags */
  return open(path, flags);
}

int sys_close(int fd) { return close(fd); }

int sys_read(int fd, void *buf, size_t count) { return read(fd, buf, count); }

int sys_write(int fd, const void *buf, size_t count) {
  return write(fd, buf, count);
}

long sys_seek(int fd, long offset, int whence) {
  return lseek(fd, offset, whence);
}

int sys_unlink(const char *path) { return unlink(path); }

int main(void) {
  /* Test basic character output */
  putchar('H');
  putchar('e');
  putchar('l');
  putchar('l');
  putchar('o');
  putchar('\n');

  /* Test string output */
  puts("Hello from KoraLibC stdio!");

  /* Test basic printf */
  printf("Number: %d\n", 42);
  printf("String: %s\n", "KoraOS");
  printf("Character: %c\n", 'K');
  printf("Hex: %x\n", 255);

  puts("stdio test completed successfully!");

  return 0;
}
