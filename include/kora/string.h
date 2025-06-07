#pragma once

#include <kora/sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

/* String length functions */
size_t strlen(const char *s);
size_t strnlen(const char *s, size_t maxlen);

/* String copying functions */
char *strcpy(char *dest, const char *src);
char *strncpy(char *dest, const char *src, size_t n);
char *strdup(const char *s);
char *strndup(const char *s, size_t n);

/* String concatenation functions */
char *strcat(char *dest, const char *src);
char *strncat(char *dest, const char *src, size_t n);

/* String comparison functions */
int strcmp(const char *s1, const char *s2);
int strncmp(const char *s1, const char *s2, size_t n);
int strcasecmp(const char *s1, const char *s2);
int strncasecmp(const char *s1, const char *s2, size_t n);

/* String searching functions */
char *strchr(const char *s, int c);
char *strrchr(const char *s, int c);
char *strstr(const char *haystack, const char *needle);
char *strcasestr(const char *haystack, const char *needle);
size_t strspn(const char *s, const char *accept);
size_t strcspn(const char *s, const char *reject);
char *strpbrk(const char *s, const char *accept);

/* String tokenization */
char *strtok(char *str, const char *delim);
char *strtok_r(char *str, const char *delim, char **saveptr);

/* String utility functions */
char *strerror(int errnum);

/* Memory manipulation functions */
void *memcpy(void *dest, const void *src, size_t n);
void *memmove(void *dest, const void *src, size_t n);
void *memset(void *s, int c, size_t n);
void *memchr(const void *s, int c, size_t n);
int memcmp(const void *s1, const void *s2, size_t n);

/* Memory allocation functions - declared in stdlib.h but needed for strdup */
#ifndef _KORA_STDLIB_H_INCLUDED
void *malloc(size_t size);
void free(void *ptr);
#endif

#ifdef __cplusplus
}
#endif 
