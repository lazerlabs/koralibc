/**
 * Syscall stubs for testing KoraLibC stdio
 */

#include <stddef.h>

/* External syscall implementations (would be provided by host for testing) */
extern int write(int fd, const void *buf, unsigned long count);
extern int read(int fd, void *buf, unsigned long count);
extern int open(const char *path, int flags);
extern int close(int fd);
extern long lseek(int fd, long offset, int whence);
extern int unlink(const char *path);

/* KoraLayer syscall implementations */
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

int sys_read(int fd, void *buf, size_t count) { return read(fd, buf, count); }

int sys_write(int fd, const void *buf, size_t count) {
  return write(fd, buf, count);
}

long sys_seek(int fd, long offset, int whence) {
  return lseek(fd, offset, whence);
}

int sys_unlink(const char *path) { return unlink(path); }
