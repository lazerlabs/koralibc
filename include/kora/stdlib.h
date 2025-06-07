#pragma once
#define _KORA_STDLIB_H_INCLUDED

#include <kora/sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Exit status constants */
#define EXIT_SUCCESS    0
#define EXIT_FAILURE    1

/* Maximum values */
#define RAND_MAX        32767

/* String conversion functions */
int atoi(const char *nptr);
long atol(const char *nptr);
long long atoll(const char *nptr);
double atof(const char *nptr);

long strtol(const char *nptr, char **endptr, int base);
unsigned long strtoul(const char *nptr, char **endptr, int base);
long long strtoll(const char *nptr, char **endptr, int base);
unsigned long long strtoull(const char *nptr, char **endptr, int base);
double strtod(const char *nptr, char **endptr);

/* Number to string conversion */
char *itoa(int value, char *str, int base);
char *ltoa(long value, char *str, int base);
char *lltoa(long long value, char *str, int base);
char *utoa(unsigned int value, char *str, int base);
char *ultoa(unsigned long value, char *str, int base);
char *ulltoa(unsigned long long value, char *str, int base);

/* Mathematical functions */
int abs(int j);
long labs(long j);
long long llabs(long long j);

typedef struct {
    int quot;
    int rem;
} div_t;

typedef struct {
    long quot;
    long rem;
} ldiv_t;

typedef struct {
    long long quot;
    long long rem;
} lldiv_t;

div_t div(int numer, int denom);
ldiv_t ldiv(long numer, long denom);
lldiv_t lldiv(long long numer, long long denom);

/* Pseudo-random number generation */
int rand(void);
void srand(unsigned int seed);

/* Searching and sorting */
void *bsearch(const void *key, const void *base, size_t nmemb, size_t size,
              int (*compar)(const void *, const void *));
void qsort(void *base, size_t nmemb, size_t size,
           int (*compar)(const void *, const void *));

/* Memory management (will be implemented later with syscalls) */
void *malloc(size_t size);
void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);
void free(void *ptr);

/* Process control (will be implemented later with syscalls) */
void exit(int status);
void abort(void);
int atexit(void (*function)(void));

/* Environment (will be implemented later) */
char *getenv(const char *name);
int putenv(char *string);
int setenv(const char *name, const char *value, int overwrite);
int unsetenv(const char *name);

#ifdef __cplusplus
}
#endif 
