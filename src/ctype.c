#include <kora/ctype.h>

/* Character classification table for ASCII characters */
const unsigned char _kora_ctype_table[256] = {
    /* 0x00-0x0F */
    _KORA_CTYPE_CNTRL, _KORA_CTYPE_CNTRL, _KORA_CTYPE_CNTRL, _KORA_CTYPE_CNTRL,
    _KORA_CTYPE_CNTRL, _KORA_CTYPE_CNTRL, _KORA_CTYPE_CNTRL, _KORA_CTYPE_CNTRL,
    _KORA_CTYPE_CNTRL,
    _KORA_CTYPE_CNTRL | _KORA_CTYPE_SPACE | _KORA_CTYPE_BLANK,
    _KORA_CTYPE_CNTRL | _KORA_CTYPE_SPACE,
    _KORA_CTYPE_CNTRL | _KORA_CTYPE_SPACE,
    _KORA_CTYPE_CNTRL | _KORA_CTYPE_SPACE,
    _KORA_CTYPE_CNTRL | _KORA_CTYPE_SPACE, _KORA_CTYPE_CNTRL, _KORA_CTYPE_CNTRL,

    /* 0x10-0x1F */
    _KORA_CTYPE_CNTRL, _KORA_CTYPE_CNTRL, _KORA_CTYPE_CNTRL, _KORA_CTYPE_CNTRL,
    _KORA_CTYPE_CNTRL, _KORA_CTYPE_CNTRL, _KORA_CTYPE_CNTRL, _KORA_CTYPE_CNTRL,
    _KORA_CTYPE_CNTRL, _KORA_CTYPE_CNTRL, _KORA_CTYPE_CNTRL, _KORA_CTYPE_CNTRL,
    _KORA_CTYPE_CNTRL, _KORA_CTYPE_CNTRL, _KORA_CTYPE_CNTRL, _KORA_CTYPE_CNTRL,

    /* 0x20-0x2F */
    _KORA_CTYPE_SPACE | _KORA_CTYPE_BLANK, _KORA_CTYPE_PUNCT, _KORA_CTYPE_PUNCT,
    _KORA_CTYPE_PUNCT, _KORA_CTYPE_PUNCT, _KORA_CTYPE_PUNCT, _KORA_CTYPE_PUNCT,
    _KORA_CTYPE_PUNCT, _KORA_CTYPE_PUNCT, _KORA_CTYPE_PUNCT, _KORA_CTYPE_PUNCT,
    _KORA_CTYPE_PUNCT, _KORA_CTYPE_PUNCT, _KORA_CTYPE_PUNCT, _KORA_CTYPE_PUNCT,
    _KORA_CTYPE_PUNCT,

    /* 0x30-0x3F (digits 0-9) */
    _KORA_CTYPE_DIGIT | _KORA_CTYPE_HEX, _KORA_CTYPE_DIGIT | _KORA_CTYPE_HEX,
    _KORA_CTYPE_DIGIT | _KORA_CTYPE_HEX, _KORA_CTYPE_DIGIT | _KORA_CTYPE_HEX,
    _KORA_CTYPE_DIGIT | _KORA_CTYPE_HEX, _KORA_CTYPE_DIGIT | _KORA_CTYPE_HEX,
    _KORA_CTYPE_DIGIT | _KORA_CTYPE_HEX, _KORA_CTYPE_DIGIT | _KORA_CTYPE_HEX,
    _KORA_CTYPE_DIGIT | _KORA_CTYPE_HEX, _KORA_CTYPE_DIGIT | _KORA_CTYPE_HEX,
    _KORA_CTYPE_PUNCT, _KORA_CTYPE_PUNCT, _KORA_CTYPE_PUNCT, _KORA_CTYPE_PUNCT,
    _KORA_CTYPE_PUNCT, _KORA_CTYPE_PUNCT,

    /* 0x40-0x4F */
    _KORA_CTYPE_PUNCT, _KORA_CTYPE_UPPER | _KORA_CTYPE_HEX,
    _KORA_CTYPE_UPPER | _KORA_CTYPE_HEX, _KORA_CTYPE_UPPER | _KORA_CTYPE_HEX,
    _KORA_CTYPE_UPPER | _KORA_CTYPE_HEX, _KORA_CTYPE_UPPER | _KORA_CTYPE_HEX,
    _KORA_CTYPE_UPPER | _KORA_CTYPE_HEX, _KORA_CTYPE_UPPER, _KORA_CTYPE_UPPER,
    _KORA_CTYPE_UPPER, _KORA_CTYPE_UPPER, _KORA_CTYPE_UPPER, _KORA_CTYPE_UPPER,
    _KORA_CTYPE_UPPER, _KORA_CTYPE_UPPER, _KORA_CTYPE_UPPER,

    /* 0x50-0x5F */
    _KORA_CTYPE_UPPER, _KORA_CTYPE_UPPER, _KORA_CTYPE_UPPER, _KORA_CTYPE_UPPER,
    _KORA_CTYPE_UPPER, _KORA_CTYPE_UPPER, _KORA_CTYPE_UPPER, _KORA_CTYPE_UPPER,
    _KORA_CTYPE_UPPER, _KORA_CTYPE_UPPER, _KORA_CTYPE_UPPER, _KORA_CTYPE_PUNCT,
    _KORA_CTYPE_PUNCT, _KORA_CTYPE_PUNCT, _KORA_CTYPE_PUNCT, _KORA_CTYPE_PUNCT,

    /* 0x60-0x6F */
    _KORA_CTYPE_PUNCT, _KORA_CTYPE_LOWER | _KORA_CTYPE_HEX,
    _KORA_CTYPE_LOWER | _KORA_CTYPE_HEX, _KORA_CTYPE_LOWER | _KORA_CTYPE_HEX,
    _KORA_CTYPE_LOWER | _KORA_CTYPE_HEX, _KORA_CTYPE_LOWER | _KORA_CTYPE_HEX,
    _KORA_CTYPE_LOWER | _KORA_CTYPE_HEX, _KORA_CTYPE_LOWER, _KORA_CTYPE_LOWER,
    _KORA_CTYPE_LOWER, _KORA_CTYPE_LOWER, _KORA_CTYPE_LOWER, _KORA_CTYPE_LOWER,
    _KORA_CTYPE_LOWER, _KORA_CTYPE_LOWER, _KORA_CTYPE_LOWER,

    /* 0x70-0x7F */
    _KORA_CTYPE_LOWER, _KORA_CTYPE_LOWER, _KORA_CTYPE_LOWER, _KORA_CTYPE_LOWER,
    _KORA_CTYPE_LOWER, _KORA_CTYPE_LOWER, _KORA_CTYPE_LOWER, _KORA_CTYPE_LOWER,
    _KORA_CTYPE_LOWER, _KORA_CTYPE_LOWER, _KORA_CTYPE_LOWER, _KORA_CTYPE_PUNCT,
    _KORA_CTYPE_PUNCT, _KORA_CTYPE_PUNCT, _KORA_CTYPE_PUNCT, _KORA_CTYPE_CNTRL,

    /* 0x80-0xFF (extended ASCII - all zeros for now) */
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0};

/* Character classification functions */
int isalnum(int c) {
  if (c < 0 || c > 255)
    return 0;
  return (_kora_ctype_table[c] &
          (_KORA_CTYPE_UPPER | _KORA_CTYPE_LOWER | _KORA_CTYPE_DIGIT)) != 0;
}

int isalpha(int c) {
  if (c < 0 || c > 255)
    return 0;
  return (_kora_ctype_table[c] & (_KORA_CTYPE_UPPER | _KORA_CTYPE_LOWER)) != 0;
}

int isblank(int c) {
  if (c < 0 || c > 255)
    return 0;
  return (_kora_ctype_table[c] & _KORA_CTYPE_BLANK) != 0;
}

int iscntrl(int c) {
  if (c < 0 || c > 255)
    return 0;
  return (_kora_ctype_table[c] & _KORA_CTYPE_CNTRL) != 0;
}

int isdigit(int c) {
  if (c < 0 || c > 255)
    return 0;
  return (_kora_ctype_table[c] & _KORA_CTYPE_DIGIT) != 0;
}

int isgraph(int c) {
  if (c < 0 || c > 255)
    return 0;
  return (_kora_ctype_table[c] & (_KORA_CTYPE_UPPER | _KORA_CTYPE_LOWER |
                                  _KORA_CTYPE_DIGIT | _KORA_CTYPE_PUNCT)) != 0;
}

int islower(int c) {
  if (c < 0 || c > 255)
    return 0;
  return (_kora_ctype_table[c] & _KORA_CTYPE_LOWER) != 0;
}

int isprint(int c) {
  if (c < 0 || c > 255)
    return 0;
  return (_kora_ctype_table[c] &
          (_KORA_CTYPE_UPPER | _KORA_CTYPE_LOWER | _KORA_CTYPE_DIGIT |
           _KORA_CTYPE_PUNCT | _KORA_CTYPE_BLANK)) != 0;
}

int ispunct(int c) {
  if (c < 0 || c > 255)
    return 0;
  return (_kora_ctype_table[c] & _KORA_CTYPE_PUNCT) != 0;
}

int isspace(int c) {
  if (c < 0 || c > 255)
    return 0;
  return (_kora_ctype_table[c] & _KORA_CTYPE_SPACE) != 0;
}

int isupper(int c) {
  if (c < 0 || c > 255)
    return 0;
  return (_kora_ctype_table[c] & _KORA_CTYPE_UPPER) != 0;
}

int isxdigit(int c) {
  if (c < 0 || c > 255)
    return 0;
  return (_kora_ctype_table[c] & _KORA_CTYPE_HEX) != 0;
}

/* Character conversion functions */
int tolower(int c) {
  if (c >= 'A' && c <= 'Z') {
    return c + ('a' - 'A');
  }
  return c;
}

int toupper(int c) {
  if (c >= 'a' && c <= 'z') {
    return c - ('a' - 'A');
  }
  return c;
}
