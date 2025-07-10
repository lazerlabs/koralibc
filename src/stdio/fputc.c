/**
 * KoraLibC fputc.c - fputc implementation
 */

#include "stdio_internal.h"

int fputc(int c, FILE *stream) {
    return putc(c, stream);
}
