#include <cmocka.h>
#include <kora/ctype.h>
#include <setjmp.h>
#include <stddef.h>

/* Test isdigit function */
static void test_isdigit(void **state) {
  (void)state;
  assert_true(isdigit('0'));
  assert_true(isdigit('5'));
  assert_true(isdigit('9'));
  assert_false(isdigit('a'));
  assert_false(isdigit(' '));
}

/* Test isalpha function */
static void test_isalpha(void **state) {
  (void)state;
  assert_true(isalpha('a'));
  assert_true(isalpha('Z'));
  assert_false(isalpha('0'));
  assert_false(isalpha(' '));
}

/* Test tolower function */
static void test_tolower(void **state) {
  (void)state;
  assert_int_equal(tolower('A'), 'a');
  assert_int_equal(tolower('Z'), 'z');
  assert_int_equal(tolower('a'), 'a');
  assert_int_equal(tolower('0'), '0');
}

/* Test toupper function */
static void test_toupper(void **state) {
  (void)state;
  assert_int_equal(toupper('a'), 'A');
  assert_int_equal(toupper('z'), 'Z');
  assert_int_equal(toupper('A'), 'A');
  assert_int_equal(toupper('0'), '0');
}

/* Main test function */
int main(void) {
  const struct CMUnitTest ctype_tests[] = {
      cmocka_unit_test(test_isdigit),
      cmocka_unit_test(test_isalpha),
      cmocka_unit_test(test_tolower),
      cmocka_unit_test(test_toupper),
  };

  return cmocka_run_group_tests(ctype_tests, NULL, NULL);
}
#include <stdarg.h>
