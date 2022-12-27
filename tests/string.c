#include <libclayer/string.h>

#include <assert.h>
#include <stddef.h>

#define COUNT 1024

static char aaa[COUNT], bbb[COUNT];

#define memcmp  LIBCLAYER(memcmp)
#define memcpy  LIBCLAYER(memcpy)
#define memmove LIBCLAYER(memmove)
#define memchr  LIBCLAYER(memchr)
#define memset  LIBCLAYER(memset)

void test_main()
{
    { // memcmp
        for (size_t i = 0; i < COUNT; ++i) aaa[i] = bbb[i] = i * i;
        assert(memcmp(aaa, bbb, COUNT) == 0);
        aaa[123] = 1;
        bbb[123] = 2;
        assert(memcmp(aaa, bbb, COUNT) == -1);
        aaa[123] = 2;
        bbb[123] = 1;
        assert(memcmp(aaa, bbb, COUNT) == 1);
    }

    { // memcpy
        for (size_t i = 0; i < COUNT; ++i) { aaa[i] = 0; bbb[i] = i * i; }
        assert(memcpy(aaa, bbb, COUNT) == aaa);
        for (size_t i = 0; i < COUNT; ++i) assert(aaa[i] == (char)(i * i));
    }

    { // memmove
        for (size_t i = 0; i < COUNT; ++i) { aaa[i] = 0; bbb[i] = i * i; }
        assert(memcpy(aaa, bbb, COUNT) == aaa);
        for (size_t i = 0; i < COUNT; ++i) assert(aaa[i] == (char)(i * i));
    }

    { // memchr
        for (size_t i = 0; i < COUNT; ++i) aaa[i] = 0;
        aaa[256] = 'a';
        assert(memchr(aaa, 'a', COUNT) == &aaa[256]);
    }

    { // memset
        memset(&aaa[0],         'a', COUNT / 2);
        memset(&aaa[COUNT / 2], 'b', COUNT / 2);
        for (size_t i = 0;         i < COUNT / 2; ++i) assert(aaa[i] == 'a');
        for (size_t i = COUNT / 2; i < COUNT;     ++i) assert(aaa[i] == 'b');
    }
}
