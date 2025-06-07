#include <assert.h>
#include <kora/ctype.h>
#include <kora/stdlib.h>
#include <kora/string.h>
#include <stdio.h>

int main() {
  printf("Testing KoraLibC...\n");

  // Test strlen
  assert(strlen("hello") == 5);
  assert(strlen("") == 0);
  printf("✓ strlen tests passed\n");

  // Test strcmp
  assert(strcmp("hello", "hello") == 0);
  assert(strcmp("abc", "def") < 0);
  assert(strcmp("def", "abc") > 0);
  printf("✓ strcmp tests passed\n");

  // Test strcpy
  char buffer[20];
  strcpy(buffer, "test");
  assert(strcmp(buffer, "test") == 0);
  printf("✓ strcpy tests passed\n");

  // Test memset
  char mem[10];
  memset(mem, 'A', 5);
  assert(mem[0] == 'A');
  assert(mem[4] == 'A');
  printf("✓ memset tests passed\n");

  // Test memcpy
  char src[] = "hello";
  char dest[10];
  memcpy(dest, src, 6);
  assert(strcmp(dest, "hello") == 0);
  printf("✓ memcpy tests passed\n");

  // Test ctype functions
  assert(isdigit('5') != 0);
  assert(isdigit('a') == 0);
  assert(isalpha('a') != 0);
  assert(isalpha('5') == 0);
  assert(tolower('A') == 'a');
  assert(toupper('a') == 'A');
  printf("✓ ctype tests passed\n");

  // Test stdlib functions
  assert(atoi("123") == 123);
  assert(atoi("-456") == -456);
  assert(abs(-5) == 5);
  assert(abs(5) == 5);
  printf("✓ stdlib tests passed\n");

  printf("All tests passed! KoraLibC is working correctly.\n");
  return 0;
}
