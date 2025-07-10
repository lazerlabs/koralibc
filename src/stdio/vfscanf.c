/**
 * KoraLibC vfscanf.c - simplified vfscanf implementation
 */

#include "stdio_internal.h"
#include <stdarg.h>
#include <kora/ctype.h>

static int read_char(FILE *stream) {
    return getc(stream);
}

static void unread_char(int c, FILE *stream) {
    if (c != EOF)
        ungetc(c, stream);
}

int vfscanf(FILE *stream, const char *format, va_list ap) {
    if (!stream || !format)
        return EOF;
    int assigned = 0;
    const char *p = format;
    while (*p) {
        if (isspace((unsigned char)*p)) {
            int c;
            while (isspace(c = read_char(stream)))
                ;
            unread_char(c, stream);
            p++;
            continue;
        }
        if (*p != '%') {
            int c = read_char(stream);
            if (c != (unsigned char)*p)
                return assigned ? assigned : EOF;
            p++;
            continue;
        }
        p++; /* skip '%' */
        switch (*p) {
        case 'd': {
            int c = read_char(stream);
            int sign = 0;
            while (isspace(c)) c = read_char(stream);
            if (c == '-' || c == '+') {
                sign = (c == '-');
                c = read_char(stream);
            }
            int val = 0;
            int got = 0;
            while (c >= '0' && c <= '9') {
                val = val * 10 + (c - '0');
                c = read_char(stream);
                got = 1;
            }
            unread_char(c, stream);
            if (!got)
                return assigned ? assigned : EOF;
            if (sign)
                val = -val;
            int *ip = va_arg(ap, int *);
            *ip = val;
            assigned++;
            break;
        }
        case 'c': {
            int c = read_char(stream);
            if (c == EOF)
                return assigned ? assigned : EOF;
            char *cp = va_arg(ap, char *);
            *cp = (char)c;
            assigned++;
            break;
        }
        case 's': {
            char *out = va_arg(ap, char *);
            int c = read_char(stream);
            while (isspace(c)) c = read_char(stream);
            if (c == EOF)
                return assigned ? assigned : EOF;
            while (c != EOF && !isspace(c)) {
                *out++ = (char)c;
                c = read_char(stream);
            }
            *out = '\0';
            unread_char(c, stream);
            assigned++;
            break;
        }
        case '%': {
            int c = read_char(stream);
            if (c != '%')
                return assigned ? assigned : EOF;
            break;
        }
        default:
            /* unsupported specifier */
            return assigned;
        }
        p++;
    }
    return assigned;
}
