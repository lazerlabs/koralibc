#include <kora/ctype.h>
#include <kora/string.h>

/* String length functions */
size_t strlen(const char *s) {
  const char *p = s;
  while (*p)
    p++;
  return p - s;
}

size_t strnlen(const char *s, size_t maxlen) {
  const char *p = s;
  while (maxlen-- && *p)
    p++;
  return p - s;
}

/* String copying functions */
char *strcpy(char *dest, const char *src) {
  char *d = dest;
  while ((*d++ = *src++))
    ;
  return dest;
}

char *strncpy(char *dest, const char *src, size_t n) {
  char *d = dest;
  while (n-- && (*d++ = *src++))
    ;
  while (n-- > 0)
    *d++ = '\0';
  return dest;
}

/* String concatenation functions */
char *strcat(char *dest, const char *src) {
  char *d = dest;
  while (*d)
    d++; /* Find end of dest */
  while ((*d++ = *src++))
    ;
  return dest;
}

char *strncat(char *dest, const char *src, size_t n) {
  char *d = dest;
  while (*d)
    d++; /* Find end of dest */
  while (n-- && (*d++ = *src++))
    ;
  if (n == (size_t)-1)
    *d = '\0';
  return dest;
}

/* String comparison functions */
int strcmp(const char *s1, const char *s2) {
  while (*s1 && (*s1 == *s2)) {
    s1++;
    s2++;
  }
  return *(unsigned char *)s1 - *(unsigned char *)s2;
}

int strncmp(const char *s1, const char *s2, size_t n) {
  while (n-- && *s1 && (*s1 == *s2)) {
    s1++;
    s2++;
  }
  if (n == (size_t)-1)
    return 0;
  return *(unsigned char *)s1 - *(unsigned char *)s2;
}

int strcasecmp(const char *s1, const char *s2) {
  while (*s1 && (tolower(*s1) == tolower(*s2))) {
    s1++;
    s2++;
  }
  return tolower(*(unsigned char *)s1) - tolower(*(unsigned char *)s2);
}

int strncasecmp(const char *s1, const char *s2, size_t n) {
  while (n-- && *s1 && (tolower(*s1) == tolower(*s2))) {
    s1++;
    s2++;
  }
  if (n == (size_t)-1)
    return 0;
  return tolower(*(unsigned char *)s1) - tolower(*(unsigned char *)s2);
}

/* String searching functions */
char *strchr(const char *s, int c) {
  while (*s) {
    if (*s == c)
      return (char *)s;
    s++;
  }
  return (c == '\0') ? (char *)s : NULL;
}

char *strrchr(const char *s, int c) {
  const char *last = NULL;
  while (*s) {
    if (*s == c)
      last = s;
    s++;
  }
  if (c == '\0')
    return (char *)s;
  return (char *)last;
}

char *strstr(const char *haystack, const char *needle) {
  if (!*needle)
    return (char *)haystack;

  while (*haystack) {
    const char *h = haystack;
    const char *n = needle;

    while (*h && *n && (*h == *n)) {
      h++;
      n++;
    }

    if (!*n)
      return (char *)haystack;
    haystack++;
  }
  return NULL;
}

char *strcasestr(const char *haystack, const char *needle) {
  if (!*needle)
    return (char *)haystack;

  while (*haystack) {
    const char *h = haystack;
    const char *n = needle;

    while (*h && *n && (tolower(*h) == tolower(*n))) {
      h++;
      n++;
    }

    if (!*n)
      return (char *)haystack;
    haystack++;
  }
  return NULL;
}

size_t strspn(const char *s, const char *accept) {
  const char *p, *a;
  size_t count = 0;

  for (p = s; *p; p++) {
    for (a = accept; *a; a++) {
      if (*p == *a)
        break;
    }
    if (!*a)
      break;
    count++;
  }
  return count;
}

size_t strcspn(const char *s, const char *reject) {
  const char *p, *r;
  size_t count = 0;

  for (p = s; *p; p++) {
    for (r = reject; *r; r++) {
      if (*p == *r)
        return count;
    }
    count++;
  }
  return count;
}

char *strpbrk(const char *s, const char *accept) {
  const char *a;

  while (*s) {
    for (a = accept; *a; a++) {
      if (*s == *a)
        return (char *)s;
    }
    s++;
  }
  return NULL;
}

/* String tokenization */
static char *strtok_state = NULL;

char *strtok(char *str, const char *delim) {
  return strtok_r(str, delim, &strtok_state);
}

char *strtok_r(char *str, const char *delim, char **saveptr) {
  char *token;

  if (str == NULL)
    str = *saveptr;
  if (str == NULL)
    return NULL;

  /* Skip leading delimiters */
  str += strspn(str, delim);
  if (*str == '\0') {
    *saveptr = NULL;
    return NULL;
  }

  /* Find end of token */
  token = str;
  str = strpbrk(token, delim);
  if (str == NULL) {
    *saveptr = NULL;
  } else {
    *str = '\0';
    *saveptr = str + 1;
  }

  return token;
}

/* Memory manipulation functions */
void *memcpy(void *dest, const void *src, size_t n) {
  unsigned char *d = (unsigned char *)dest;
  const unsigned char *s = (const unsigned char *)src;

  while (n--)
    *d++ = *s++;
  return dest;
}

void *memmove(void *dest, const void *src, size_t n) {
  unsigned char *d = (unsigned char *)dest;
  const unsigned char *s = (const unsigned char *)src;

  if (d < s) {
    while (n--)
      *d++ = *s++;
  } else {
    d += n;
    s += n;
    while (n--)
      *--d = *--s;
  }
  return dest;
}

void *memset(void *s, int c, size_t n) {
  unsigned char *p = (unsigned char *)s;
  while (n--)
    *p++ = (unsigned char)c;
  return s;
}

void *memchr(const void *s, int c, size_t n) {
  const unsigned char *p = (const unsigned char *)s;
  while (n--) {
    if (*p == (unsigned char)c)
      return (void *)p;
    p++;
  }
  return NULL;
}

int memcmp(const void *s1, const void *s2, size_t n) {
  const unsigned char *p1 = (const unsigned char *)s1;
  const unsigned char *p2 = (const unsigned char *)s2;

  while (n--) {
    if (*p1 != *p2)
      return *p1 - *p2;
    p1++;
    p2++;
  }
  return 0;
}

/* Memory allocation functions are implemented in stdlib.c */

/* String duplication functions (depend on malloc) */
char *strdup(const char *s) {
  size_t len = strlen(s) + 1;
  char *dup = malloc(len);
  if (dup)
    memcpy(dup, s, len);
  return dup;
}

char *strndup(const char *s, size_t n) {
  size_t len = strnlen(s, n);
  char *dup = malloc(len + 1);
  if (dup) {
    memcpy(dup, s, len);
    dup[len] = '\0';
  }
  return dup;
}

/* Error string function (basic implementation) */
char *strerror(int errnum) {
  static char error_buf[32];

  switch (errnum) {
  case 0:
    return "Success";
  case 1:
    return "Operation not permitted";
  case 2:
    return "No such file or directory";
  case 3:
    return "No such process";
  case 4:
    return "Interrupted system call";
  case 5:
    return "Input/output error";
  default:
    /* Simple number to string conversion */
    strcpy(error_buf, "Unknown error ");
    /* Add error number - simplified implementation */
    return error_buf;
  }
}
