/**
 * KoraLibC setbuf.c - setbuf implementation
 */

#include "stdio_internal.h"

void setbuf(FILE *stream, char *buf) {
    if (!stream)
        return;
    if (buf) {
        stream->buffer = buf;
        stream->buffer_size = BUFSIZ;
    } else {
        stream->buffer = NULL;
        stream->buffer_size = 0;
    }
    stream->buffer_pos = 0;
    stream->buffer_end = 0;
}
