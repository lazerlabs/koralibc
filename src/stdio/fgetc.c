/**
 * KoraLibC fgetc.c - fgetc implementation
 */

#include "stdio_internal.h"

int fgetc(FILE *stream) {
    return getc(stream);
}
