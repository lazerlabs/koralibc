/**
 * KoraLibC freopen.c - freopen implementation
 */

#include "stdio_internal.h"

FILE *freopen(const char *filename, const char *mode, FILE *stream) {
    if (!filename || !mode || !stream)
        return NULL;

    int flags = 0;
    switch (mode[0]) {
    case 'r':
        flags = KORA_O_RDONLY;
        if (mode[1] == '+')
            flags = KORA_O_RDWR;
        break;
    case 'w':
        flags = KORA_O_WRONLY | KORA_O_CREAT | KORA_O_TRUNC;
        if (mode[1] == '+')
            flags = KORA_O_RDWR | KORA_O_CREAT | KORA_O_TRUNC;
        break;
    case 'a':
        flags = KORA_O_WRONLY | KORA_O_CREAT | KORA_O_APPEND;
        if (mode[1] == '+')
            flags = KORA_O_RDWR | KORA_O_CREAT | KORA_O_APPEND;
        break;
    default:
        return NULL;
    }

    if (stream->fd >= 0 && stream != stdin && stream != stdout && stream != stderr)
        sys_close(stream->fd);

    int fd = sys_open(filename, flags);
    if (fd < 0)
        return NULL;

    stream->fd = fd;
    stream->flags = flags;
    stream->eof_flag = 0;
    stream->error_flag = 0;
    stream->position = 0;
    stream->buffer_pos = 0;
    stream->buffer_end = 0;
    stream->ungot_char = 0;
    stream->has_unget = 0;

    return stream;
}
