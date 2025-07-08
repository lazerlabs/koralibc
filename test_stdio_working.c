/**
 * Working test program for KoraLibC stdio implementation
 */

#include <fcntl.h>  /* For open */
#include <unistd.h> /* For real write/read syscalls */

/* KoraLayer syscall implementations that actually work */
int sys_putc(char c) { return (int)write(1, &c, 1); }

int sys_getc(void) {
  char c;
  if (read(0, &c, 1) == 1) {
    return (unsigned char)c;
  }
  return -1; /* EOF */
}

int sys_open(const char *path, int flags) { return open(path, flags); }

int sys_close(int fd) { return close(fd); }

int sys_read(int fd, void *buf, unsigned long count) {
  return read(fd, buf, count);
}

int sys_write(int fd, const void *buf, unsigned long count) {
  return write(fd, buf, count);
}

long sys_seek(int fd, long offset, int whence) {
  return lseek(fd, offset, whence);
}

int sys_unlink(const char *path) { return unlink(path); }

/* Now include our stdio functions */
extern int putchar(int c);
extern int puts(const char *s);
extern int printf(const char *format, ...);

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
