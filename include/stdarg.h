/**
 * KoraLibC stdarg.h - Variable Arguments Implementation
 *
 * This header provides support for variadic functions (functions that can take 
 * a variable number of arguments). This is a freestanding implementation that
 * uses compiler builtins available in GCC and Clang.
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/**
 * va_list - Type to hold information about variable arguments
 * 
 * This type is used to declare a variable that will refer to each argument
 * in turn when processing a variable argument list.
 */
typedef __builtin_va_list va_list;

/**
 * va_start - Initialize a va_list for use
 * 
 * @param ap    The va_list to initialize
 * @param last  The last named parameter before the variable arguments
 * 
 * This macro initializes ap to point to the first variable argument.
 * The parameter 'last' should be the last named parameter of the function.
 */
#define va_start(ap, last) __builtin_va_start(ap, last)

/**
 * va_arg - Retrieve the next argument
 * 
 * @param ap    The va_list in use
 * @param type  The type of the argument to retrieve
 * @return      The next argument, cast to the specified type
 * 
 * This macro retrieves the next argument from the variable argument list
 * and advances the va_list to point to the following argument.
 */
#define va_arg(ap, type) __builtin_va_arg(ap, type)

/**
 * va_end - Clean up a va_list
 * 
 * @param ap The va_list to clean up
 * 
 * This macro performs any necessary cleanup for the va_list.
 * It should be called when finished processing variable arguments.
 */
#define va_end(ap) __builtin_va_end(ap)

/**
 * va_copy - Copy a va_list (C99)
 * 
 * @param dest The destination va_list
 * @param src  The source va_list to copy
 * 
 * This macro copies the state of src to dest, allowing independent
 * traversal of the same variable argument list.
 */
#define va_copy(dest, src) __builtin_va_copy(dest, src)

#ifdef __cplusplus
}
#endif 
