#ifndef _LIBCLAYER_H
#define _LIBCLAYER_H 1

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

#ifndef LIBCLAYER_PREFIX
#define LIBCLAYER(name) name
#else
#define LIBCLAYER(name) LIBCLAYER2(LIBCLAYER_PREFIX, name)
#define LIBCLAYER2(prefix, name) LIBCLAYER3(prefix, name)
#define LIBCLAYER3(prefix, name) prefix ## name
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
