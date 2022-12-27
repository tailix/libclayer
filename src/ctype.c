#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <libclayer/ctype.h>

int LIBCLAYER(isdigit)(const int c)
{
    return (unsigned)c - '0' < 10;
}

int LIBCLAYER(islower)(const int c)
{
    return (unsigned)c - 'a' < 26;
}

int LIBCLAYER(isspace)(const int c)
{
    return c == ' ' || (unsigned)c - '\t' < 5;
}

int LIBCLAYER(isupper)(const int c)
{
    return (unsigned)c - 'A' < 26;
}

int LIBCLAYER(tolower)(const int c)
{
    return LIBCLAYER(isupper)(c) ? (c + ('a' - 'A')) : c;
}

int LIBCLAYER(toupper)(const int c)
{
    return LIBCLAYER(islower)(c) ? (c - ('a' - 'A')) : c;
}
