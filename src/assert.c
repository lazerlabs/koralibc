/**
 * KoraLibC assert.c - Assertion Failure Handler Implementation
 */

#include <kora/stdio.h>

/**
 * __kora_assert_fail - Internal assertion failure handler
 *
 * This function is called when an assertion fails. In a freestanding
 * environment, we provide a basic implementation that prints the error
 * and enters an infinite loop (similar to abort()).
 */
void __kora_assert_fail(const char *assertion, const char *file,
                        unsigned int line, const char *function) {
  /* Print assertion failure information to stderr */
  fprintf(stderr, "Assertion failed: %s\n", assertion);
  fprintf(stderr, "File: %s, Line: %u\n", file, line);
  fprintf(stderr, "Function: %s\n", function);

  /* In a freestanding environment, we can't call abort() or exit(),
   * so we enter an infinite loop to halt execution */
  while (1) {
    /* Infinite loop to halt execution */
    __asm__ volatile("" ::: "memory"); /* Prevent optimization */
  }
}
