#ifndef _STRING_H
#define _STRING_H 1

#ifdef __cplusplus
extern "C" {
#endif

#include <libclayer.h>
#include <stddef.h>

// mem*
int    LIBCLAYER(memcmp)(const void *s1, const void *s2, size_t n);
void  *LIBCLAYER(memcpy)(void *dest, const void *src, size_t n);
void  *LIBCLAYER(memmove)(void *dest, const void *src, size_t n);
void  *LIBCLAYER(memchr)(const void *s, int c, size_t n);
void  *LIBCLAYER(memset)(void *s, int c, size_t n);

// str*
char  *LIBCLAYER(strcat)(char *dest, const char *src);
char  *LIBCLAYER(strchr)(const char *s, int c);
int    LIBCLAYER(strcmp)(const char *s1, const char *s2);
char  *LIBCLAYER(strcpy)(char *dest, const char *src);
size_t LIBCLAYER(strlen)(const char *s);

// strn*
char  *LIBCLAYER(strncat)(char *dest, const char *src, size_t n);
int    LIBCLAYER(strncmp)(const char *s1, const char *s2, size_t n);
char  *LIBCLAYER(strncpy)(char *dest, const char *src, size_t n);
size_t LIBCLAYER(strnlen)(const char *s, size_t maxlen);

// str*
char  *LIBCLAYER(strstr)(const char *haystack, const char *needle);

#ifdef __cplusplus
}
#endif

#endif
