#include <cmocka.h>
#include <kora/string.h>
#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>

/* Test strlen function */
static void test_strlen_empty_string(void **state) {
  (void)state;
  assert_int_equal(strlen(""), 0);
}

static void test_strlen_normal_string(void **state) {
  (void)state;
  assert_int_equal(strlen("hello"), 5);
  assert_int_equal(strlen("world"), 5);
  assert_int_equal(strlen("test string"), 11);
}

/* Test strcpy function */
static void test_strcpy_normal(void **state) {
  (void)state;
  char dest[20];
  char *result = strcpy(dest, "hello");

  assert_ptr_equal(result, dest);
  assert_string_equal(dest, "hello");
}

static void test_strcpy_empty(void **state) {
  (void)state;
  char dest[10] = "test";
  strcpy(dest, "");
  assert_string_equal(dest, "");
}

/* Test strncpy function */
static void test_strncpy_normal(void **state) {
  (void)state;
  char dest[20];
  strncpy(dest, "hello world", 5);
  dest[5] = '\0'; /* Null terminate manually */
  assert_memory_equal(dest, "hello", 5);
}

static void test_strncpy_padding(void **state) {
  (void)state;
  char dest[10];
  strncpy(dest, "hi", 5);

  assert_int_equal(dest[0], 'h');
  assert_int_equal(dest[1], 'i');
  assert_int_equal(dest[2], '\0');
  assert_int_equal(dest[3], '\0');
  assert_int_equal(dest[4], '\0');
}

/* Test strcmp function */
static void test_strcmp_equal(void **state) {
  (void)state;
  assert_int_equal(strcmp("hello", "hello"), 0);
  assert_int_equal(strcmp("", ""), 0);
}

static void test_strcmp_different(void **state) {
  (void)state;
  assert_true(strcmp("hello", "world") < 0);
  assert_true(strcmp("world", "hello") > 0);
  assert_true(strcmp("hello", "hello world") < 0);
}

/* Test strncmp function */
static void test_strncmp_equal(void **state) {
  (void)state;
  assert_int_equal(strncmp("hello", "hello", 5), 0);
  assert_int_equal(strncmp("hello world", "hello test", 5), 0);
}

static void test_strncmp_different(void **state) {
  (void)state;
  assert_true(strncmp("hello", "world", 5) < 0);
  assert_true(strncmp("world", "hello", 5) > 0);
}

/* Test strcat function */
static void test_strcat_normal(void **state) {
  (void)state;
  char dest[20] = "hello";
  char *result = strcat(dest, " world");

  assert_ptr_equal(result, dest);
  assert_string_equal(dest, "hello world");
}

static void test_strcat_empty_src(void **state) {
  (void)state;
  char dest[20] = "hello";
  strcat(dest, "");
  assert_string_equal(dest, "hello");
}

/* Test strchr function */
static void test_strchr_found(void **state) {
  (void)state;
  const char *str = "hello world";
  char *result = strchr(str, 'o');

  assert_ptr_equal(result, str + 4); /* First 'o' at position 4 */
}

static void test_strchr_not_found(void **state) {
  (void)state;
  char *result = strchr("hello", 'x');
  assert_null(result);
}

static void test_strchr_null_terminator(void **state) {
  (void)state;
  const char *str = "hello";
  char *result = strchr(str, '\0');
  assert_ptr_equal(result, str + 5);
}

/* Test strrchr function */
static void test_strrchr_found(void **state) {
  (void)state;
  const char *str = "hello world";
  char *result = strrchr(str, 'o');

  assert_ptr_equal(result, str + 7); /* Last 'o' at position 7 */
}

static void test_strrchr_not_found(void **state) {
  (void)state;
  char *result = strrchr("hello", 'x');
  assert_null(result);
}

/* Test strstr function */
static void test_strstr_found(void **state) {
  (void)state;
  const char *haystack = "hello world";
  char *result = strstr(haystack, "world");

  assert_ptr_equal(result, haystack + 6);
}

static void test_strstr_not_found(void **state) {
  (void)state;
  char *result = strstr("hello world", "xyz");
  assert_null(result);
}

static void test_strstr_empty_needle(void **state) {
  (void)state;
  const char *haystack = "hello";
  char *result = strstr(haystack, "");
  assert_ptr_equal(result, haystack);
}

/* Test memory functions */
static void test_memcpy_normal(void **state) {
  (void)state;
  char src[] = "hello";
  char dest[10];

  void *result = memcpy(dest, src, 6); /* Include null terminator */

  assert_ptr_equal(result, dest);
  assert_memory_equal(dest, src, 6);
}

static void test_memset_normal(void **state) {
  (void)state;
  char buffer[10];
  void *result = memset(buffer, 'A', 5);

  assert_ptr_equal(result, buffer);
  assert_int_equal(buffer[0], 'A');
  assert_int_equal(buffer[1], 'A');
  assert_int_equal(buffer[2], 'A');
  assert_int_equal(buffer[3], 'A');
  assert_int_equal(buffer[4], 'A');
}

static void test_memcmp_equal(void **state) {
  (void)state;
  char buf1[] = "hello";
  char buf2[] = "hello";

  assert_int_equal(memcmp(buf1, buf2, 5), 0);
}

static void test_memcmp_different(void **state) {
  (void)state;
  char buf1[] = "hello";
  char buf2[] = "world";

  assert_true(memcmp(buf1, buf2, 5) < 0);
}

static void test_memchr_found(void **state) {
  (void)state;
  char buffer[] = "hello world";
  void *result = memchr(buffer, 'w', 11);

  assert_ptr_equal(result, buffer + 6);
}

static void test_memchr_not_found(void **state) {
  (void)state;
  char buffer[] = "hello";
  void *result = memchr(buffer, 'x', 5);

  assert_null(result);
}

/* Test memmove function */
static void test_memmove_non_overlapping(void **state) {
  (void)state;
  char src[] = "hello";
  char dest[10];

  void *result = memmove(dest, src, 6);

  assert_ptr_equal(result, dest);
  assert_memory_equal(dest, src, 6);
}

static void test_memmove_overlapping_forward(void **state) {
  (void)state;
  char buffer[] = "hello world";

  /* Move "world" to overwrite "hello" */
  memmove(buffer, buffer + 6, 5);
  buffer[5] = '\0';

  assert_string_equal(buffer, "world");
}

static void test_memmove_overlapping_backward(void **state) {
  (void)state;
  char buffer[] = "hello world";

  /* Move "hello" to position 2 */
  memmove(buffer + 2, buffer, 5);

  assert_memory_equal(buffer + 2, "hello", 5);
}

/* Test strtok function */
static void test_strtok_basic(void **state) {
  (void)state;
  char str[] = "hello,world,test";
  char *token;

  token = strtok(str, ",");
  assert_string_equal(token, "hello");

  token = strtok(NULL, ",");
  assert_string_equal(token, "world");

  token = strtok(NULL, ",");
  assert_string_equal(token, "test");

  token = strtok(NULL, ",");
  assert_null(token);
}

static void test_strtok_multiple_delimiters(void **state) {
  (void)state;
  char str[] = "hello, world ; test";
  char *token;

  token = strtok(str, ", ;");
  assert_string_equal(token, "hello");

  token = strtok(NULL, ", ;");
  assert_string_equal(token, "world");

  token = strtok(NULL, ", ;");
  assert_string_equal(token, "test");
}

/* Test strtok_r function */
static void test_strtok_r_basic(void **state) {
  (void)state;
  char str[] = "hello,world,test";
  char *saveptr;
  char *token;

  token = strtok_r(str, ",", &saveptr);
  assert_string_equal(token, "hello");

  token = strtok_r(NULL, ",", &saveptr);
  assert_string_equal(token, "world");

  token = strtok_r(NULL, ",", &saveptr);
  assert_string_equal(token, "test");

  token = strtok_r(NULL, ",", &saveptr);
  assert_null(token);
}

/* Test fixture setup and teardown */
static int setup(void **state) {
  (void)state;
  return 0;
}

static int teardown(void **state) {
  (void)state;
  return 0;
}

/* Main test function */
int main(void) {
  const struct CMUnitTest string_tests[] = {
      /* strlen tests */
      cmocka_unit_test(test_strlen_empty_string),
      cmocka_unit_test(test_strlen_normal_string),

      /* strcpy tests */
      cmocka_unit_test(test_strcpy_normal),
      cmocka_unit_test(test_strcpy_empty),

      /* strncpy tests */
      cmocka_unit_test(test_strncpy_normal),
      cmocka_unit_test(test_strncpy_padding),

      /* strcmp tests */
      cmocka_unit_test(test_strcmp_equal),
      cmocka_unit_test(test_strcmp_different),

      /* strncmp tests */
      cmocka_unit_test(test_strncmp_equal),
      cmocka_unit_test(test_strncmp_different),

      /* strcat tests */
      cmocka_unit_test(test_strcat_normal),
      cmocka_unit_test(test_strcat_empty_src),

      /* strchr tests */
      cmocka_unit_test(test_strchr_found),
      cmocka_unit_test(test_strchr_not_found),
      cmocka_unit_test(test_strchr_null_terminator),

      /* strrchr tests */
      cmocka_unit_test(test_strrchr_found),
      cmocka_unit_test(test_strrchr_not_found),

      /* strstr tests */
      cmocka_unit_test(test_strstr_found),
      cmocka_unit_test(test_strstr_not_found),
      cmocka_unit_test(test_strstr_empty_needle),

      /* Memory function tests */
      cmocka_unit_test(test_memcpy_normal),
      cmocka_unit_test(test_memset_normal),
      cmocka_unit_test(test_memcmp_equal),
      cmocka_unit_test(test_memcmp_different),
      cmocka_unit_test(test_memchr_found),
      cmocka_unit_test(test_memchr_not_found),
      cmocka_unit_test(test_memmove_non_overlapping),
      cmocka_unit_test(test_memmove_overlapping_forward),
      cmocka_unit_test(test_memmove_overlapping_backward),

      /* Token function tests */
      cmocka_unit_test(test_strtok_basic),
      cmocka_unit_test(test_strtok_multiple_delimiters),
      cmocka_unit_test(test_strtok_r_basic),
  };

  return cmocka_run_group_tests(string_tests, setup, teardown);
}
