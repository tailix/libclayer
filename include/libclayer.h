#ifndef _LIBCLAYER_H
#define _LIBCLAYER_H 1

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

#ifdef LIBCLAYER_NOPREFIX
#define LIBCLAYER(name) name
#else
#define LIBCLAYER(name) libclayer_ ## name
#endif

struct Libclayer {
    __attribute__((noreturn)) void (*abort)();
    __attribute__((noreturn)) void (*exit)(int status);

    void *(*calloc)(size_t nmemb, size_t size);
    void  (*free)(void *ptr);
    void *(*malloc)(size_t size);
    void *(*realloc)(void *ptr, size_t size);
};

extern struct Libclayer libclayer;

#ifdef __cplusplus
}
#endif

#endif
