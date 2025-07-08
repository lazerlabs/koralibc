/**
 * Test program to verify stdarg.h functionality
 */

#include <stdarg.h>
#include <stddef.h>

/* Simple function to test va_list, va_start, va_arg, va_end */
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

/* Function to test va_copy */
static int sum_twice(int count, ...) {
  va_list ap1, ap2;
  int sum1 = 0, sum2 = 0;
  int i;

  va_start(ap1, count);
  va_copy(ap2, ap1);

  /* Process first copy */
  for (i = 0; i < count; i++) {
    sum1 += va_arg(ap1, int);
  }

  /* Process second copy */
  for (i = 0; i < count; i++) {
    sum2 += va_arg(ap2, int);
  }

  va_end(ap1);
  va_end(ap2);

  return sum1 + sum2;
}

int main(void) {
  /* Test basic functionality */
  int result1 = sum_ints(3, 10, 20, 30); /* Should be 60 */
  int result2 = sum_twice(2, 5, 15);     /* Should be 40 (20+20) */

  /* Simple validation */
  if (result1 == 60 && result2 == 40) {
    return 0; /* Success */
  }

  return 1; /* Failure */
}
