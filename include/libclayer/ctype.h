#ifndef _LIBCLAYER_CTYPE_H
#define _LIBCLAYER_CTYPE_H 1

#ifdef __cplusplus
extern "C" {
#endif

#include <libclayer.h>

int LIBCLAYER(isdigit)(int c);
int LIBCLAYER(islower)(int c);
int LIBCLAYER(isspace)(int c);
int LIBCLAYER(isupper)(int c);

int LIBCLAYER(tolower)(int c);
int LIBCLAYER(toupper)(int c);

#ifdef __cplusplus
}
#endif

#endif
