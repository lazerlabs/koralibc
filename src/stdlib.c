#include <kora/ctype.h>
#include <kora/stdlib.h>
#include <kora/string.h>

/* Random number generation state */
static unsigned long rand_seed = 1;

/* String to number conversion functions */
int atoi(const char *nptr) { return (int)strtol(nptr, NULL, 10); }

long atol(const char *nptr) { return strtol(nptr, NULL, 10); }

long long atoll(const char *nptr) { return strtoll(nptr, NULL, 10); }

double atof(const char *nptr) { return strtod(nptr, NULL); }

long strtol(const char *nptr, char **endptr, int base) {
  const char *s = nptr;
  long result = 0;
  int negative = 0;

  /* Skip whitespace */
  while (isspace(*s))
    s++;

  /* Handle sign */
  if (*s == '-') {
    negative = 1;
    s++;
  } else if (*s == '+') {
    s++;
  }

  /* Handle base prefix */
  if (base == 0) {
    if (*s == '0') {
      if (s[1] == 'x' || s[1] == 'X') {
        base = 16;
        s += 2;
      } else {
        base = 8;
        s++;
      }
    } else {
      base = 10;
    }
  } else if (base == 16 && *s == '0' && (s[1] == 'x' || s[1] == 'X')) {
    s += 2;
  }

  /* Convert digits */
  while (*s) {
    int digit;
    if (isdigit(*s)) {
      digit = *s - '0';
    } else if (isalpha(*s)) {
      digit = tolower(*s) - 'a' + 10;
    } else {
      break;
    }

    if (digit >= base)
      break;

    result = result * base + digit;
    s++;
  }

  if (endptr)
    *endptr = (char *)s;
  return negative ? -result : result;
}

unsigned long strtoul(const char *nptr, char **endptr, int base) {
  const char *s = nptr;
  unsigned long result = 0;

  /* Skip whitespace */
  while (isspace(*s))
    s++;

  /* Handle sign (ignore negative for unsigned) */
  if (*s == '+')
    s++;
  else if (*s == '-')
    s++;

  /* Handle base prefix */
  if (base == 0) {
    if (*s == '0') {
      if (s[1] == 'x' || s[1] == 'X') {
        base = 16;
        s += 2;
      } else {
        base = 8;
        s++;
      }
    } else {
      base = 10;
    }
  } else if (base == 16 && *s == '0' && (s[1] == 'x' || s[1] == 'X')) {
    s += 2;
  }

  /* Convert digits */
  while (*s) {
    int digit;
    if (isdigit(*s)) {
      digit = *s - '0';
    } else if (isalpha(*s)) {
      digit = tolower(*s) - 'a' + 10;
    } else {
      break;
    }

    if (digit >= base)
      break;

    result = result * base + digit;
    s++;
  }

  if (endptr)
    *endptr = (char *)s;
  return result;
}

long long strtoll(const char *nptr, char **endptr, int base) {
  const char *s = nptr;
  long long result = 0;
  int negative = 0;

  /* Skip whitespace */
  while (isspace(*s))
    s++;

  /* Handle sign */
  if (*s == '-') {
    negative = 1;
    s++;
  } else if (*s == '+') {
    s++;
  }

  /* Handle base prefix */
  if (base == 0) {
    if (*s == '0') {
      if (s[1] == 'x' || s[1] == 'X') {
        base = 16;
        s += 2;
      } else {
        base = 8;
        s++;
      }
    } else {
      base = 10;
    }
  } else if (base == 16 && *s == '0' && (s[1] == 'x' || s[1] == 'X')) {
    s += 2;
  }

  /* Convert digits */
  while (*s) {
    int digit;
    if (isdigit(*s)) {
      digit = *s - '0';
    } else if (isalpha(*s)) {
      digit = tolower(*s) - 'a' + 10;
    } else {
      break;
    }

    if (digit >= base)
      break;

    result = result * base + digit;
    s++;
  }

  if (endptr)
    *endptr = (char *)s;
  return negative ? -result : result;
}

unsigned long long strtoull(const char *nptr, char **endptr, int base) {
  const char *s = nptr;
  unsigned long long result = 0;

  /* Skip whitespace */
  while (isspace(*s))
    s++;

  /* Handle sign (ignore negative for unsigned) */
  if (*s == '+')
    s++;
  else if (*s == '-')
    s++;

  /* Handle base prefix */
  if (base == 0) {
    if (*s == '0') {
      if (s[1] == 'x' || s[1] == 'X') {
        base = 16;
        s += 2;
      } else {
        base = 8;
        s++;
      }
    } else {
      base = 10;
    }
  } else if (base == 16 && *s == '0' && (s[1] == 'x' || s[1] == 'X')) {
    s += 2;
  }

  /* Convert digits */
  while (*s) {
    int digit;
    if (isdigit(*s)) {
      digit = *s - '0';
    } else if (isalpha(*s)) {
      digit = tolower(*s) - 'a' + 10;
    } else {
      break;
    }

    if (digit >= base)
      break;

    result = result * base + digit;
    s++;
  }

  if (endptr)
    *endptr = (char *)s;
  return result;
}

/* Simple strtod implementation (basic floating point) */
double strtod(const char *nptr, char **endptr) {
  const char *s = nptr;
  double result = 0.0;
  double fraction = 0.0;
  double divisor = 1.0;
  int negative = 0;
  int in_fraction = 0;

  /* Skip whitespace */
  while (isspace(*s))
    s++;

  /* Handle sign */
  if (*s == '-') {
    negative = 1;
    s++;
  } else if (*s == '+') {
    s++;
  }

  /* Convert digits */
  while (*s) {
    if (isdigit(*s)) {
      if (in_fraction) {
        divisor *= 10.0;
        fraction = fraction * 10.0 + (*s - '0');
      } else {
        result = result * 10.0 + (*s - '0');
      }
    } else if (*s == '.' && !in_fraction) {
      in_fraction = 1;
    } else {
      break;
    }
    s++;
  }

  result += fraction / divisor;

  if (endptr)
    *endptr = (char *)s;
  return negative ? -result : result;
}

/* Number to string conversion functions */
char *itoa(int value, char *str, int base) {
  return ltoa((long)value, str, base);
}

char *ltoa(long value, char *str, int base) {
  char *ptr = str;
  char *ptr1 = str;
  char tmp_char;
  long tmp_value;

  if (base < 2 || base > 36) {
    *str = '\0';
    return str;
  }

  /* Handle negative numbers for base 10 */
  if (value < 0 && base == 10) {
    *ptr++ = '-';
    value = -value;
    ptr1++;
  }

  /* Convert to string (reversed) */
  do {
    tmp_value = value;
    value /= base;
    *ptr++ = "0123456789abcdefghijklmnopqrstuvwxyz"[tmp_value - value * base];
  } while (value);

  *ptr-- = '\0';

  /* Reverse string */
  while (ptr1 < ptr) {
    tmp_char = *ptr;
    *ptr-- = *ptr1;
    *ptr1++ = tmp_char;
  }

  return str;
}

char *lltoa(long long value, char *str, int base) {
  char *ptr = str;
  char *ptr1 = str;
  char tmp_char;
  long long tmp_value;

  if (base < 2 || base > 36) {
    *str = '\0';
    return str;
  }

  /* Handle negative numbers for base 10 */
  if (value < 0 && base == 10) {
    *ptr++ = '-';
    value = -value;
    ptr1++;
  }

  /* Convert to string (reversed) */
  do {
    tmp_value = value;
    value /= base;
    *ptr++ = "0123456789abcdefghijklmnopqrstuvwxyz"[tmp_value - value * base];
  } while (value);

  *ptr-- = '\0';

  /* Reverse string */
  while (ptr1 < ptr) {
    tmp_char = *ptr;
    *ptr-- = *ptr1;
    *ptr1++ = tmp_char;
  }

  return str;
}

char *utoa(unsigned int value, char *str, int base) {
  return ultoa((unsigned long)value, str, base);
}

char *ultoa(unsigned long value, char *str, int base) {
  char *ptr = str;
  char *ptr1 = str;
  char tmp_char;
  unsigned long tmp_value;

  if (base < 2 || base > 36) {
    *str = '\0';
    return str;
  }

  /* Convert to string (reversed) */
  do {
    tmp_value = value;
    value /= base;
    *ptr++ = "0123456789abcdefghijklmnopqrstuvwxyz"[tmp_value - value * base];
  } while (value);

  *ptr-- = '\0';

  /* Reverse string */
  while (ptr1 < ptr) {
    tmp_char = *ptr;
    *ptr-- = *ptr1;
    *ptr1++ = tmp_char;
  }

  return str;
}

char *ulltoa(unsigned long long value, char *str, int base) {
  char *ptr = str;
  char *ptr1 = str;
  char tmp_char;
  unsigned long long tmp_value;

  if (base < 2 || base > 36) {
    *str = '\0';
    return str;
  }

  /* Convert to string (reversed) */
  do {
    tmp_value = value;
    value /= base;
    *ptr++ = "0123456789abcdefghijklmnopqrstuvwxyz"[tmp_value - value * base];
  } while (value);

  *ptr-- = '\0';

  /* Reverse string */
  while (ptr1 < ptr) {
    tmp_char = *ptr;
    *ptr-- = *ptr1;
    *ptr1++ = tmp_char;
  }

  return str;
}

/* Mathematical functions */
int abs(int j) { return (j < 0) ? -j : j; }

long labs(long j) { return (j < 0) ? -j : j; }

long long llabs(long long j) { return (j < 0) ? -j : j; }

div_t div(int numer, int denom) {
  div_t result;
  result.quot = numer / denom;
  result.rem = numer % denom;
  return result;
}

ldiv_t ldiv(long numer, long denom) {
  ldiv_t result;
  result.quot = numer / denom;
  result.rem = numer % denom;
  return result;
}

lldiv_t lldiv(long long numer, long long denom) {
  lldiv_t result;
  result.quot = numer / denom;
  result.rem = numer % denom;
  return result;
}

/* Pseudo-random number generation */
int rand(void) {
  rand_seed = rand_seed * 1103515245 + 12345;
  return (int)((rand_seed / 65536) % (RAND_MAX + 1));
}

void srand(unsigned int seed) { rand_seed = seed; }

/* Searching and sorting */
void *bsearch(const void *key, const void *base, size_t nmemb, size_t size,
              int (*compar)(const void *, const void *)) {
  const char *cbase = (const char *)base;
  size_t low = 0;
  size_t high = nmemb;

  while (low < high) {
    size_t mid = low + (high - low) / 2;
    const void *midp = cbase + mid * size;
    int cmp = compar(key, midp);

    if (cmp < 0) {
      high = mid;
    } else if (cmp > 0) {
      low = mid + 1;
    } else {
      return (void *)midp;
    }
  }

  return NULL;
}

/* Simple quicksort implementation */
static void qsort_swap(void *a, void *b, size_t size) {
  char *ca = (char *)a;
  char *cb = (char *)b;
  char temp;

  while (size--) {
    temp = *ca;
    *ca++ = *cb;
    *cb++ = temp;
  }
}

static void qsort_internal(void *base, size_t low, size_t high, size_t size,
                           int (*compar)(const void *, const void *)) {
  if (low < high) {
    char *cbase = (char *)base;
    size_t pivot = low;
    size_t i;

    for (i = low + 1; i <= high; i++) {
      if (compar(cbase + i * size, cbase + low * size) < 0) {
        pivot++;
        qsort_swap(cbase + i * size, cbase + pivot * size, size);
      }
    }

    qsort_swap(cbase + low * size, cbase + pivot * size, size);

    if (pivot > 0) {
      qsort_internal(base, low, pivot - 1, size, compar);
    }
    qsort_internal(base, pivot + 1, high, size, compar);
  }
}

void qsort(void *base, size_t nmemb, size_t size,
           int (*compar)(const void *, const void *)) {
  if (nmemb > 1) {
    qsort_internal(base, 0, nmemb - 1, size, compar);
  }
}

/* Memory management stubs (will be implemented later with syscalls) */
void *malloc(size_t size) {
  (void)size;
  return NULL; /* Not implemented yet */
}

void *calloc(size_t nmemb, size_t size) {
  (void)nmemb;
  (void)size;
  return NULL; /* Not implemented yet */
}

void *realloc(void *ptr, size_t size) {
  (void)ptr;
  (void)size;
  return NULL; /* Not implemented yet */
}

void free(void *ptr) {
  (void)ptr;
  /* Not implemented yet */
}

/* Process control stubs (will be implemented later with syscalls) */
void exit(int status) {
  (void)status;
  /* Not implemented yet - would call sys_exit */
  while (1)
    ; /* Infinite loop for now */
}

void abort(void) { exit(EXIT_FAILURE); }

int atexit(void (*function)(void)) {
  (void)function;
  return -1; /* Not implemented yet */
}

/* Environment stubs (will be implemented later) */
char *getenv(const char *name) {
  (void)name;
  return NULL; /* Not implemented yet */
}

int putenv(char *string) {
  (void)string;
  return -1; /* Not implemented yet */
}

int setenv(const char *name, const char *value, int overwrite) {
  (void)name;
  (void)value;
  (void)overwrite;
  return -1; /* Not implemented yet */
}

int unsetenv(const char *name) {
  (void)name;
  return -1; /* Not implemented yet */
}
