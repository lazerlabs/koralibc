/**
 * KoraLibC vsnprintf.c - vsnprintf implementation
 */

#include "stdio_internal.h"
#include <stdarg.h>

static int buffer_putc(char c, char **buf, size_t *remaining, int *count) {
    if (*remaining > 1) {
        **buf = c;
        (*buf)++;
        (*remaining)--;
    }
    (*count)++;
    return 0;
}

int vsnprintf(char *str, size_t size, const char *format, va_list ap) {
    char *out = str;
    size_t remaining = size;
    int written = 0;
    const char *ptr = format;

    while (*ptr) {
        if (*ptr != '%') {
            buffer_putc(*ptr++, &out, &remaining, &written);
            continue;
        }
        ptr++;
        switch (*ptr) {
        case 'd': {
            int value = va_arg(ap, int);
            char tmp[32];
            int len = int_to_str(value, tmp, 10);
            for (int i = 0; i < len; i++)
                buffer_putc(tmp[i], &out, &remaining, &written);
            break;
        }
        case 'x': {
            int value = va_arg(ap, int);
            char tmp[32];
            int len = int_to_str(value, tmp, 16);
            for (int i = 0; i < len; i++)
                buffer_putc(tmp[i], &out, &remaining, &written);
            break;
        }
        case 'c': {
            int value = va_arg(ap, int);
            buffer_putc((char)value, &out, &remaining, &written);
            break;
        }
        case 's': {
            const char *s = va_arg(ap, const char *);
            if (!s)
                s = "(null)";
            while (*s)
                buffer_putc(*s++, &out, &remaining, &written);
            break;
        }
        case '%':
            buffer_putc('%', &out, &remaining, &written);
            break;
        default:
            buffer_putc('%', &out, &remaining, &written);
            buffer_putc(*ptr, &out, &remaining, &written);
            break;
        }
        ptr++;
    }

    if (size > 0) {
        if (remaining > 0)
            *out = '\0';
        else
            str[size - 1] = '\0';
    }

    return written;
}
