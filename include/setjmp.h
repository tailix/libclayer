#ifdef LIBCLAYER_NOPREFIX
#include <libclayer/setjmp.h>
#else
#define LIBCLAYER_NOPREFIX
#include <libclayer/setjmp.h>
#undef LIBCLAYER_NOPREFIX
#endif
