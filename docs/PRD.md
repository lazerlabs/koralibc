# KoraLibC Product Requirements Document

This document outlines the remaining tasks to complete the KoraLibC
implementation. It serves as a guide for future work and provides context for
any contributor using GPT Codex.

## Background

KoraLibC is a minimal C standard library tailored for KoraOS. It relies on the
syscall ABI exposed by the [KoraLayer](https://github.com/lazerlabs/koralayer)
project. The library is currently functional for basic string handling, ctype,
stdlib utilities and a partial stdio implementation.

## Goals

1. Provide a freestanding libc for KoraOS that offers a familiar set of C99
   APIs.
2. Keep the implementation small and easy to audit.
3. Remain compatible with the KoraLayer syscall interface.
4. Include unit tests wherever possible.

## Phase 2 Roadmap

The following features are planned next:

1. **Memory Management** – implement `malloc`, `free`, `realloc` and friends
   using KoraLayer syscalls.
2. **File I/O** – support for `fopen`, `fread`, `fwrite`, etc.
3. **Process Control** – implement `exit` and process management calls.
4. **Environment Management** – functions like `getenv`, `setenv`, `unsetenv`.
5. **Math Library** – add `math.h` with common math functions.
6. **Time Functions** – provide `time.h` functionality (clocks, timestamps).

These areas depend on the underlying kernel facilities and will evolve as the
KoraLayer API stabilises.

## Development Guidelines

- Follow the coding style used in the existing source files (spaces for
  indentation, ANSI C99).
- Keep functions simple and well commented.
- Where functionality depends on yet-to-be-defined syscalls, provide stubs with
  clear TODO comments.
- Extend unit tests in `tests/` as new modules are added.

## References

More information on the guiding principles can be found in the chat thread:
<https://chatgpt.com/g/g-p-677ac79d60d48191b1c0684b10248485-kora/c/67b38599-d1cc-800a-91d3-bb6e12a295e3>

