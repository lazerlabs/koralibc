/**
 * KoraLibC setvbuf.c - setvbuf implementation
 */

#include "stdio_internal.h"

int setvbuf(FILE *stream, char *buf, int mode, size_t size) {
    if (!stream)
        return -1;

    stream->buffer = buf;
    stream->buffer_size = buf ? size : 0;
    stream->buffer_pos = 0;
    stream->buffer_end = 0;
    stream->buffer_mode = mode;
    return 0;
}
