#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/* Character classification functions */
int isalnum(int c);
int isalpha(int c);
int isblank(int c);
int iscntrl(int c);
int isdigit(int c);
int isgraph(int c);
int islower(int c);
int isprint(int c);
int ispunct(int c);
int isspace(int c);
int isupper(int c);
int isxdigit(int c);

/* Character conversion functions */
int tolower(int c);
int toupper(int c);

/* ASCII character classification macros for performance */
#define _KORA_CTYPE_UPPER   0x01
#define _KORA_CTYPE_LOWER   0x02
#define _KORA_CTYPE_DIGIT   0x04
#define _KORA_CTYPE_SPACE   0x08
#define _KORA_CTYPE_PUNCT   0x10
#define _KORA_CTYPE_CNTRL   0x20
#define _KORA_CTYPE_BLANK   0x40
#define _KORA_CTYPE_HEX     0x80

/* Character classification table (internal) */
extern const unsigned char _kora_ctype_table[256];

#ifdef __cplusplus
}
#endif 
