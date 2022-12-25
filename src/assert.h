#ifndef KERNAUX_INCLUDED_ASSERT
#define KERNAUX_INCLUDED_ASSERT

#define KERNAUX_PANIC(msg) ((void)0)
#define KERNAUX_ASSERT(cond) ((void)0)
#define KERNAUX_NOTNULL(cond) KERNAUX_ASSERT(cond)

#endif
