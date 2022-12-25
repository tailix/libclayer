#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <libclayer.h>

#include <stddef.h>

struct Libclayer libclayer = {
    .abort = NULL,
    .exit = NULL,

    .calloc = NULL,
    .free = NULL,
    .malloc = NULL,
    .realloc = NULL,
};
