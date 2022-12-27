#ifndef _LIBCLAYER_STDLIB_H
#define _LIBCLAYER_STDLIB_H 1

#ifdef __cplusplus
extern "C" {
#endif

#include <libclayer.h>
#include <stddef.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

int LIBCLAYER(atoi)(const char *str);

void LIBCLAYER(abort)() __attribute__((noreturn));
void LIBCLAYER(exit)(int status) __attribute__((noreturn));

void *LIBCLAYER(calloc)(size_t nmemb, size_t size);
void  LIBCLAYER(free)(void *ptr);
void *LIBCLAYER(malloc)(size_t size);
void *LIBCLAYER(realloc)(void *ptr, size_t size);

#ifdef __cplusplus
}
#endif

#endif
