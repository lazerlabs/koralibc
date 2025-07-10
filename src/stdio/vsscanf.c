/**
 * KoraLibC vsscanf.c - simplified vsscanf implementation
 */

#include "stdio_internal.h"
#include <stdarg.h>
#include <kora/ctype.h>

struct str_ctx {
    const char *s;
    size_t pos;
};

static int s_read(void *ctx) {
    struct str_ctx *c = (struct str_ctx *)ctx;
    char ch = c->s[c->pos];
    if (ch == '\0')
        return EOF;
    c->pos++;
    return (unsigned char)ch;
}

static void s_unread(int ch, void *ctx) {
    struct str_ctx *c = (struct str_ctx *)ctx;
    if (ch == EOF || c->pos == 0)
        return;
    c->pos--;
}

static int scan_core(int (*reader)(void *), void (*unreader)(int, void *), void *ctx, const char *format, va_list ap) {
    int assigned = 0;
    const char *p = format;
    while (*p) {
        if (isspace((unsigned char)*p)) {
            int c;
            while (isspace(c = reader(ctx)))
                ;
            unreader(c, ctx);
            p++;
            continue;
        }
        if (*p != '%') {
            int c = reader(ctx);
            if (c != (unsigned char)*p)
                return assigned ? assigned : EOF;
            p++;
            continue;
        }
        p++;
        switch (*p) {
        case 'd': {
            int c = reader(ctx);
            int sign = 0;
            while (isspace(c)) c = reader(ctx);
            if (c == '-' || c == '+') { sign = (c == '-'); c = reader(ctx); }
            int val = 0; int got = 0;
            while (c >= '0' && c <= '9') { val = val*10 + (c-'0'); c = reader(ctx); got = 1; }
            unreader(c, ctx);
            if (!got) return assigned ? assigned : EOF;
            if (sign) val = -val;
            int *ip = va_arg(ap, int*); *ip = val; assigned++; break; }
        case 'c': {
            int c = reader(ctx);
            if (c == EOF) return assigned ? assigned : EOF;
            char *cp = va_arg(ap, char*); *cp = (char)c; assigned++; break; }
        case 's': {
            char *out = va_arg(ap, char*); int c = reader(ctx);
            while (isspace(c)) c = reader(ctx);
            if (c == EOF) return assigned ? assigned : EOF;
            while (c != EOF && !isspace(c)) { *out++ = (char)c; c = reader(ctx); }
            *out = '\0'; unreader(c, ctx); assigned++; break; }
        case '%': {
            int c = reader(ctx); if (c != '%') return assigned ? assigned : EOF; break; }
        default: return assigned; }
        p++;
    }
    return assigned;
}

int vsscanf(const char *str, const char *format, va_list ap) {
    struct str_ctx ctx = { str, 0 };
    return scan_core(s_read, s_unread, &ctx, format, ap);
}
