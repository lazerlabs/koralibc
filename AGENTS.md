# Guidelines for GPT Codex

This repository contains **KoraLibC**, a minimal C standard library for KoraOS.
All contributions should follow these principles:

- **Language**: C99. Avoid compiler extensions and keep the code freestanding.
- **Style**: Use spaces for indentation (no tabs) and match the formatting of the
  existing source files.
- **Build**: Use CMake. Typical steps are `mkdir build && cd build && cmake .. && make`.
- **Testing**: If CMocka is installed, run `ctest` from the `build/` directory
  after building.
- **Scope**: The library depends on the syscalls defined in the
  [KoraLayer](https://github.com/lazerlabs/koralayer) project. When features rely
  on missing syscalls, provide stub implementations with TODO comments.
- **Documentation**: Keep `docs/README.md` and `docs/PRD.md` up to date when
  relevant changes occur.

