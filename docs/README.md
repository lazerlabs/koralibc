# KoraLibC Documentation

KoraLibC is a freestanding implementation of the C standard library for **KoraOS**. The
project provides a minimal subset of libc written in C99 and relies on the
syscall interface defined in [KoraLayer](https://github.com/lazerlabs/koralayer).

This document describes the repository layout, how to build the library, and the
interfaces currently available.

## Repository layout

```
include/       Public headers
src/           Library implementation
tests/         Unit tests (optional, requires CMocka)
docs/          Project documentation
```

The root `README.md` provides an overview of the implemented features and design
philosophy. This `docs/README.md` focuses on how to work with the codebase.

## Building

KoraLibC uses CMake. A standard build looks like this:

```bash
mkdir build
cd build
cmake ..
make
```

If [CMocka](https://cmocka.org/) is available, the tests will be compiled and can
be executed with `ctest`:

```bash
ctest
```

The build produces both static (`libkoralibc.a`) and shared (`libkoralibc.so`)
libraries in the `build/` directory.

## Headers and API

The library exposes a subset of the standard C headers under `include/`:

- `stddef.h` – C99 definitions like `size_t` and `NULL`.
- `stdint.h` – fixed width integer types.
- `stdbool.h` – the `bool` type and constants.
- `stdarg.h` – variable argument handling.
- `limits.h` – fundamental limits.
- `errno.h` – error codes.
- `assert.h` – runtime assertions.
- `kora/sys/types.h` – platform specific typedefs used throughout KoraOS.
- `kora/string.h` – basic string and memory helpers.
- `kora/ctype.h` – character classification helpers.
- `kora/stdlib.h` – minimal standard library functions.
- `kora/stdio.h` – partial stdio implementation.

These headers implement familiar C interfaces. Many functions are still
incomplete or stubbed out while the syscall layer is being finalised. See the
source files in `src/` for details.

## Example

A minimal program using KoraLibC might look like:

```c
#include <kora/string.h>
#include <kora/stdio.h>

int main(void) {
    char msg[] = "Hello from KoraLibC";
    kora_printf("%s\n", msg);
    return 0;
}
```

Compile it with:

```bash
gcc -o hello hello.c -Iinclude build/libkoralibc.a
```

## Further reading

For a more detailed discussion of architecture decisions, see `README.md` in the
repository root. The [Product Requirements Document](PRD.md) outlines the plan
for completing the rest of the library.

