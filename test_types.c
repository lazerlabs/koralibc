#include <kora/sys/types.h>
#include <stdio.h>

int main() {
  printf("KoraLibC Type Sizes (targeting AARCH64):\n");
  printf("========================================\n");

  printf("Basic types:\n");
  printf("  int8_t:    %zu bytes\n", sizeof(int8_t));
  printf("  int16_t:   %zu bytes\n", sizeof(int16_t));
  printf("  int32_t:   %zu bytes\n", sizeof(int32_t));
  printf("  int64_t:   %zu bytes\n", sizeof(int64_t));

  printf("\nUnsigned types:\n");
  printf("  uint8_t:   %zu bytes\n", sizeof(uint8_t));
  printf("  uint16_t:  %zu bytes\n", sizeof(uint16_t));
  printf("  uint32_t:  %zu bytes\n", sizeof(uint32_t));
  printf("  uint64_t:  %zu bytes\n", sizeof(uint64_t));

  printf("\nSize types:\n");
  printf("  size_t:    %zu bytes\n", sizeof(size_t));
  printf("  ssize_t:   %zu bytes\n", sizeof(ssize_t));
  printf("  ptrdiff_t: %zu bytes\n", sizeof(ptrdiff_t));

  printf("\nPointer types:\n");
  printf("  void*:     %zu bytes\n", sizeof(void *));
  printf("  char*:     %zu bytes\n", sizeof(char *));

  printf("\nOther types:\n");
  printf("  bool:      %zu bytes\n", sizeof(bool));
  printf("  wchar_t:   %zu bytes\n", sizeof(wchar_t));

  printf("\nExpected for AARCH64: int32_t=4, int64_t=8, size_t=8, void*=8\n");

  return 0;
}
