#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <libclayer/string.h>

#include <stddef.h>

int LIBCLAYER(memcmp)(const void *s1, const void *s2, size_t n)
{
    for (const unsigned char *p1 = s1, *p2 = s2; n--; ++p1, ++p2) {
        if (*p1 != *p2) return *p1 - *p2;
    }
    return 0;
}

void *LIBCLAYER(memcpy)(void *dest, const void *src, size_t n)
{
    char *dest_cell = dest;
    char *src_cell = (char*)src;
    while (n--) *dest_cell++ = *src_cell++;
    return dest;
}

void *LIBCLAYER(memmove)(void *dest, const void *src, size_t n)
{
    char *dest_cell = dest;
    char *src_cell = (char*)src;
    if (dest_cell <= src_cell) {
        while (n--) *dest_cell++ = *src_cell++;
    } else {
        dest_cell += n;
        src_cell += n;
        while (n--) *--dest_cell = *--src_cell;
    }
    return dest;
}

void *LIBCLAYER(memchr)(const void *s, int c, size_t n)
{
    for (const unsigned char *p = s; n--; ++p) {
        if ((unsigned char)c == *p) return (void*)p;
    }
    return NULL;
}

void *LIBCLAYER(memset)(void *s, int c, size_t n)
{
    char *ss = s;
    while (n--) *ss++ = c;
    return s;
}

char *LIBCLAYER(strcat)(char *dest, const char *src)
{
    char *const dest_start = dest;
    while (*dest) ++dest;
    while ((*dest++ = *src++));
    return dest_start;
}

char *LIBCLAYER(strchr)(const char *s, int c)
{
    for (; *s != (char)c; ++s) if (*s == '\0') return NULL;
    return (char*)s;
}

int LIBCLAYER(strcmp)(const char *s1, const char *s2)
{
    for (;;) {
        const char c1 = *s1++;
        const char c2 = *s2++;
        if (c1 != c2) return c1 < c2 ? -1 : 1;
        if (!c1) return 0;
    }
}

char *LIBCLAYER(strcpy)(char *dest, const char *src)
{
    char *tmp = dest;
    while ((*dest++ = *src++) != '\0');
    return tmp;
}

size_t LIBCLAYER(strlen)(const char *s)
{
    const char *ss = s;
    while (*ss != '\0') ++ss;
    return ss - s;
}

char *LIBCLAYER(strncat)(char *dest, const char *src, size_t n)
{
    char *const dest_start = dest;
    if (n) {
        while (*dest) ++dest;
        while ((*dest++ = *src++)) {
            if (--n == 0) {
                *dest = '\0';
                break;
            }
        }
    }
    return dest_start;
}

int LIBCLAYER(strncmp)(const char *s1, const char *s2, size_t n)
{
    while (n--) {
        const char c1 = *s1++;
        const char c2 = *s2++;
        if (c1 != c2) return c1 < c2 ? -1 : 1;
        if (!c1) return 0;
    }
    return 0;
}

char *LIBCLAYER(strncpy)(char *dest, const char *src, size_t n)
{
    char *tmp = dest;
    while (n-- && (*dest++ = *src++) != '\0');
    return tmp;
}

size_t LIBCLAYER(strnlen)(const char *s, size_t maxlen)
{
    const char *ss = s;
    while (*ss != '\0' && maxlen--) ++ss;
    return ss - s;
}

char *LIBCLAYER(strstr)(const char *haystack, const char *needle)
{
    const size_t needle_slen = LIBCLAYER(strlen)(needle);
    if (!needle_slen) return (char*)haystack;

    size_t haystack_slen = LIBCLAYER(strlen)(haystack);
    while (haystack_slen >= needle_slen) {
        --haystack_slen;
        if (!LIBCLAYER(memcmp)(haystack, needle, needle_slen)) {
            return (char*)haystack;
        }
        ++haystack;
    }

    return NULL;
}
