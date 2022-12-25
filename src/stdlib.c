#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <libclayer.h>

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void LIBCLAYER(exit)(const int status)
{
    // Custom implementation
    libclayer.exit(status);
}

void LIBCLAYER(abort)()
{
    // Custom implementation
    if (libclayer.abort) libclayer.abort();

    // Default implementation
    LIBCLAYER(exit)(EXIT_FAILURE);
}

void *LIBCLAYER(calloc)(const size_t nmemb, const size_t size)
{
    // Custom implementation
    if (libclayer.calloc) return libclayer.calloc(nmemb, size);

    // Default implementation
    const size_t total_size = nmemb * size;
    if (!total_size) return NULL;
    if (total_size / nmemb != size) return NULL;
    void *const ptr = LIBCLAYER(malloc)(total_size);
    if (ptr) LIBCLAYER(memset)(ptr, 0, total_size);
    return ptr;
}

void LIBCLAYER(free)(void *const ptr)
{
    // Custom implementation
    libclayer.free(ptr);
}

void *LIBCLAYER(malloc)(const size_t size)
{
    // Custom implementation
    return libclayer.malloc(size);
}

void *LIBCLAYER(realloc)(void *const ptr, const size_t size)
{
    // Custom implementation
    return libclayer.realloc(ptr, size);
}

int LIBCLAYER(atoi)(const char *str)
{
    while (LIBCLAYER(isspace)(*str)) ++str;
    bool is_negative = false;
    switch (*str) {
    case '-': is_negative = true; // fall through
    case '+': ++str;
    }
    int result = 0;
    while (LIBCLAYER(isdigit)(*str)) result = 10 * result - (*str++ - '0');
    return is_negative ? result : -result;
}
