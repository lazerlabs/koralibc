/**
 * KoraLibC ungetc.c - ungetc implementation
 */

#include "stdio_internal.h"

int ungetc(int c, FILE *stream) {
    if (!stream || c == EOF)
        return EOF;

    if (stream->has_unget)
        return EOF; /* only one char buffer */

    stream->ungot_char = (unsigned char)c;
    stream->has_unget = 1;
    if (stream->position > 0)
        stream->position--;
    stream->eof_flag = 0;
    return (unsigned char)c;
}
