/**
 * Test program to verify new standard C headers functionality
 */

#include <assert.h>
#include <errno.h>
#include <limits.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/* Test function for stdint.h */
static void test_stdint(void) {
  uint8_t u8 = UINT8_MAX;
  int16_t i16 = INT16_MIN;
  uint32_t u32 = UINT32_MAX;
  int64_t i64 = INT64_MAX;

  /* Test pointer types */
  uintptr_t ptr_val = (uintptr_t)&u8;
  intmax_t max_val = INTMAX_MAX;

  /* Suppress unused variable warnings */
  (void)u8;
  (void)i16;
  (void)u32;
  (void)i64;
  (void)ptr_val;
  (void)max_val;
}

/* Test function for stdbool.h */
static bool test_stdbool(void) {
  bool result = true;
  bool test = false;

  if (__bool_true_false_are_defined != 1) {
    return false;
  }

  return result && !test;
}

/* Test function for limits.h */
static void test_limits(void) {
  /* Test that limits are defined correctly */
  int char_bits = CHAR_BIT;
  int max_int = INT_MAX;
  long max_long = LONG_MAX;

  /* Basic sanity checks */
  assert(char_bits == 8);
  assert(max_int > 0);
  assert(max_long > max_int);

  (void)char_bits;
  (void)max_int;
  (void)max_long;
}

/* Test function for errno.h */
static void test_errno(void) {
  /* Test errno manipulation */
  KORA_ERRNO_CLEAR();
  assert(errno == 0);

  KORA_ERRNO_SET(EINVAL);
  assert(KORA_ERRNO_CHECK(EINVAL));
  assert(errno == EINVAL);

  errno = ENOMEM;
  assert(errno == ENOMEM);
}

/* Test function using stdarg.h */
static int sum_ints(int count, ...) {
  va_list ap;
  int sum = 0;
  int i;

  va_start(ap, count);
  for (i = 0; i < count; i++) {
    sum += va_arg(ap, int);
  }
  va_end(ap);

  return sum;
}

/* Test function for assert.h */
static void test_assert(void) {
  /* Test assertions that should pass */
  assert(1 == 1);
  assert(true);
  assert(CHAR_BIT == 8);

  /* Test static_assert (compile-time) */
  static_assert(sizeof(int) >= 4, "int must be at least 4 bytes");
  static_assert(UINT8_MAX == 255, "uint8_t max value must be 255");
}

int main(void) {
  /* Test stdint.h */
  test_stdint();

  /* Test stdbool.h */
  bool bool_result = test_stdbool();
  assert(bool_result == true);

  /* Test limits.h */
  test_limits();

  /* Test errno.h */
  test_errno();

  /* Test stdarg.h */
  int sum = sum_ints(4, 10, 20, 30, 40);
  assert(sum == 100);

  /* Test assert.h */
  test_assert();

  /* Test constant macros */
  assert(INT8_C(127) == 127);
  assert(UINT64_C(18446744073709551615) == UINT64_MAX);

  /* Clean up object files */
  return 0;
}
