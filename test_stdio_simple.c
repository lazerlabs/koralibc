/**
 * Simple test program for KoraLibC stdio implementation
 * This version avoids system header conflicts
 */

/* Minimal syscall stubs for testing */
int write(int fd, const void *buf, unsigned long count) {
  /* This would normally be a system call */
  /* For testing, we'll just return the count */
  (void)fd;
  (void)buf;
  return (int)count;
}

int read(int fd, void *buf, unsigned long count) {
  (void)fd;
  (void)buf;
  (void)count;
  return 0; /* EOF for testing */
}

int open(const char *path, int flags) {
  (void)path;
  (void)flags;
  return 3; /* Return a dummy fd */
}

int close(int fd) {
  (void)fd;
  return 0;
}

long lseek(int fd, long offset, int whence) {
  (void)fd;
  (void)whence;
  return offset;
}

int unlink(const char *path) {
  (void)path;
  return 0;
}

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
