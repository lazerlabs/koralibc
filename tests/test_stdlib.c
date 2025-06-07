#include <cmocka.h>
#include <kora/stdlib.h>
#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>

/* Test atoi function */
static void test_atoi(void **state) {
  (void)state;
  assert_int_equal(atoi("123"), 123);
  assert_int_equal(atoi("-456"), -456);
  assert_int_equal(atoi("0"), 0);
}

/* Test abs function */
static void test_abs(void **state) {
  (void)state;
  assert_int_equal(abs(5), 5);
  assert_int_equal(abs(-5), 5);
  assert_int_equal(abs(0), 0);
}

/* Test rand function */
static void test_rand(void **state) {
  (void)state;
  srand(1);
  int r1 = rand();
  int r2 = rand();
  assert_true(r1 >= 0 && r1 <= RAND_MAX);
  assert_true(r2 >= 0 && r2 <= RAND_MAX);
  assert_true(r1 != r2); /* Very likely to be different */
}

/* Main test function */
int main(void) {
  const struct CMUnitTest stdlib_tests[] = {
      cmocka_unit_test(test_atoi),
      cmocka_unit_test(test_abs),
      cmocka_unit_test(test_rand),
  };

  return cmocka_run_group_tests(stdlib_tests, NULL, NULL);
}
