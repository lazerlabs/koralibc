# KoraLibC - Minimal C Standard Library

KoraLibC is a minimal, freestanding C standard library implementation designed for KoraOS. It provides essential C library functions without depending on the host operating system's libc.

## Features

### Phase 1: Core Functions (Implemented)

#### String Functions (`kora/string.h`)
- **Length**: `strlen()`, `strnlen()`
- **Copying**: `strcpy()`, `strncpy()`, `strdup()`, `strndup()`
- **Concatenation**: `strcat()`, `strncat()`
- **Comparison**: `strcmp()`, `strncmp()`, `strcasecmp()`, `strncasecmp()`
- **Searching**: `strchr()`, `strrchr()`, `strstr()`, `strcasestr()`, `strspn()`, `strcspn()`, `strpbrk()`
- **Tokenization**: `strtok()`, `strtok_r()`
- **Error handling**: `strerror()`

#### Memory Functions (`kora/string.h`)
- **Manipulation**: `memcpy()`, `memmove()`, `memset()`, `memchr()`, `memcmp()`
- **Allocation**: `malloc()`, `calloc()`, `realloc()`, `free()` (stubs for now)

#### Character Classification (`kora/ctype.h`)
- **Classification**: `isalnum()`, `isalpha()`, `isblank()`, `iscntrl()`, `isdigit()`, `isgraph()`, `islower()`, `isprint()`, `ispunct()`, `isspace()`, `isupper()`, `isxdigit()`
- **Conversion**: `tolower()`, `toupper()`

#### Standard Library (`kora/stdlib.h`)
- **String conversion**: `atoi()`, `atol()`, `atoll()`, `atof()`, `strtol()`, `strtoul()`, `strtoll()`, `strtoull()`, `strtod()`
- **Number to string**: `itoa()`, `ltoa()`, `lltoa()`, `utoa()`, `ultoa()`, `ulltoa()`
- **Math**: `abs()`, `labs()`, `llabs()`, `div()`, `ldiv()`, `lldiv()`
- **Random**: `rand()`, `srand()`
- **Search/Sort**: `bsearch()`, `qsort()`
- **Process control**: `exit()`, `abort()`, `atexit()` (stubs for now)
- **Environment**: `getenv()`, `putenv()`, `setenv()`, `unsetenv()` (stubs for now)

#### Type Definitions (`kora/sys/types.h`)
**Target Architecture: ARM64 (AARCH64) - Raspberry Pi 3/4/5**
- Basic integer types: `int8_t` (1 byte), `uint8_t` (1 byte), `int16_t` (2 bytes), `uint16_t` (2 bytes)
- 32-bit types: `int32_t`, `uint32_t` (using `int` - 4 bytes on AARCH64)
- 64-bit types: `int64_t`, `uint64_t` (using `long` - 8 bytes on AARCH64 LP64 model)
- Size types: `size_t`, `ssize_t`, `ptrdiff_t` (8 bytes - 64-bit pointers)
- Character types: `wchar_t`, `char16_t`, `char32_t`
- Boolean type: `bool` (for C)
- File system types: `fd_t`, `pid_t`, `uid_t`, `gid_t`, `time_t`, `clock_t`, etc.

The type system is designed specifically for our target platform and includes compile-time assertions to ensure compatibility when cross-compiling or testing on other systems.

## Building

### Prerequisites
- CMake 3.16 or later
- GCC or compatible C compiler
- CMocka (optional, for unit tests)

### Build Instructions

```bash
mkdir build
cd build
cmake ..
make
```

This will create:
- `libkoralibc.a` - Static library
- `libkoralibc.so` - Shared library

### Testing

A simple test program is included to verify functionality:

```bash
gcc -o test_simple test_simple.c -Iinclude build/libkoralibc.a
./test_simple
```

Expected output:
```
Testing KoraLibC...
✓ strlen tests passed
✓ strcmp tests passed
✓ strcpy tests passed
✓ memset tests passed
✓ memcpy tests passed
✓ ctype tests passed
✓ stdlib tests passed
All tests passed! KoraLibC is working correctly.
```

## Usage

Include the appropriate headers and link with the library:

```c
#include <kora/string.h>
#include <kora/ctype.h>
#include <kora/stdlib.h>

int main() {
    char buffer[100];
    strcpy(buffer, "Hello, KoraOS!");
    
    if (isalpha(buffer[0])) {
        printf("First character is alphabetic\n");
    }
    
    int num = atoi("42");
    return 0;
}
```

Compile with:
```bash
gcc -o program program.c -Ikoralibc/include -Lkoralibc/build -lkoralibc
```

## Design Principles

1. **Freestanding**: No dependencies on host system libc
2. **Minimal**: Only essential functions implemented
3. **Portable**: Works across different platforms
4. **Standards Compliant**: Follows C99 standard where applicable
5. **Well Tested**: Comprehensive unit tests for all functions

## Implementation Details

### Target Architecture Strategy
KoraLibC is designed specifically for **ARM64 (AARCH64)** architecture, targeting Raspberry Pi 3/4/5:

- **Data Model**: LP64 (Long and Pointer are 64-bit)
- **Type Mapping**: 
  - `int32_t` → `int` (4 bytes)
  - `int64_t` → `long` (8 bytes) 
  - `size_t` → `unsigned long` (8 bytes)
- **Compile-time Verification**: Assertions ensure host system compatibility during development
- **Cross-platform Development**: Warning message when compiling on non-AARCH64 hosts

This approach provides:
1. **Predictable ABI**: Consistent types across development and target platforms
2. **Optimal Performance**: Uses native AARCH64 word sizes
3. **Development Safety**: Catches type size mismatches at compile time

### Compiler Flags
The library is compiled with freestanding flags:
- `-nostdlib`: Don't use standard system libraries
- `-ffreestanding`: Freestanding environment
- `-fno-builtin`: Don't use builtin functions

### Memory Management
Currently, memory allocation functions (`malloc`, `free`, etc.) are stubs that return NULL. These will be implemented in Phase 2 using KoraLayer syscalls.

### Character Classification
Uses a lookup table approach for efficient character classification, supporting full ASCII range (0-255).

### String Functions
All string functions are implemented from scratch without using any system library functions.

### Header Guard Strategy
To prevent duplicate function declarations across headers, we use conditional compilation guards:

- **Memory allocation functions** (`malloc`, `free`, etc.) are primarily declared in `stdlib.h`
- **String functions** that need malloc (`strdup`, `strndup`) conditionally declare minimal malloc prototypes in `string.h` only if `stdlib.h` hasn't been included
- This allows any inclusion order (`string.h` → `stdlib.h` or `stdlib.h` → `string.h`) without compilation errors

```c
/* In string.h */
#ifndef _KORA_STDLIB_H_INCLUDED
void *malloc(size_t size);
void free(void *ptr);
#endif
```

## Future Work (Phase 2)

1. **Memory Management**: Implement `malloc()`, `free()`, etc. using KoraLayer syscalls
2. **File I/O**: Implement `fopen()`, `fread()`, `fwrite()`, etc.
3. **Process Control**: Implement `exit()`, process management functions
4. **Environment**: Implement environment variable functions
5. **Math Library**: Add `math.h` with mathematical functions
6. **Time Functions**: Add `time.h` with time/date functions

## Directory Structure

```
koralibc/
├── include/kora/          # Public headers
│   ├── sys/types.h       # Type definitions
│   ├── string.h          # String functions
│   ├── ctype.h           # Character classification
│   └── stdlib.h          # Standard library functions
├── src/                  # Implementation files
│   ├── string.c          # String function implementations
│   ├── ctype.c           # Character function implementations
│   └── stdlib.c          # Standard library implementations
├── tests/                # Unit tests (CMocka)
├── build/                # Build directory
├── CMakeLists.txt        # Build configuration
├── test_simple.c         # Simple test program
└── README.md             # This file
```

## License

This project is part of KoraOS and follows the same licensing terms. 
