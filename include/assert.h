/**
 * KoraLibC assert.h - Assertion Macro Implementation
 *
 * This header provides the assert macro for debugging. In a freestanding
 * environment, we provide our own implementation without depending on
 * the host system's abort() function.
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/**
 * __kora_assert_fail - Internal assertion failure handler
 * 
 * This function is called when an assertion fails. In a full OS environment,
 * this would typically call abort() or similar. For KoraOS, we provide a
 * minimal implementation that can be customized by the kernel.
 */
void __kora_assert_fail(const char *assertion, const char *file, 
                        unsigned int line, const char *function);

/**
 * NDEBUG handling - When NDEBUG is defined, assertions are disabled
 */
#ifdef NDEBUG

#define assert(expr) ((void)0)

#else /* NDEBUG not defined - assertions enabled */

/**
 * assert - Assert that an expression is true
 * 
 * @param expr Expression to test
 * 
 * If expr evaluates to false (0), the assertion fails and __kora_assert_fail
 * is called with diagnostic information. If expr is true (non-zero), nothing happens.
 * 
 * Note: The expression is evaluated only when NDEBUG is not defined.
 */
#define assert(expr) \
    ((expr) ? (void)0 : __kora_assert_fail(#expr, __FILE__, __LINE__, __func__))

#endif /* NDEBUG */

/**
 * static_assert - Compile-time assertion (C11/C23)
 * 
 * This provides static_assert functionality for compile-time checks.
 * Available in C11 and later standards.
 */
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
/* C11 and later have built-in static_assert */
#define static_assert _Static_assert
#elif defined(__cplusplus) && __cplusplus >= 201103L
/* C++11 and later have built-in static_assert */
/* Already available, no need to define */
#else
/* Pre-C11: Provide a basic implementation */
#define static_assert(expr, msg) \
    typedef char static_assert_##__LINE__[(expr) ? 1 : -1]
#endif

#ifdef __cplusplus
}
#endif 
