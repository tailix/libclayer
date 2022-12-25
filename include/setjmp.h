#ifndef _SETJMP_H
#define _SETJMP_H 1

#ifdef __cplusplus
extern "C" {
#endif

#include <libclayer.h>

// TODO: define in architecture-specific header
typedef unsigned long __jmp_buf[sizeof(long) == 8 ? 8 : 6];

typedef struct __jmp_buf_tag {
    __jmp_buf __jb;
    unsigned long __fl;
    unsigned long __ss[128 / sizeof(long)];
} jmp_buf[1];

int  LIBCLAYER(setjmp)(jmp_buf env) __attribute__((returns_twice));
void LIBCLAYER(longjmp)(jmp_buf env, int val) __attribute__((noreturn));

#ifdef __cplusplus
}
#endif

#endif
