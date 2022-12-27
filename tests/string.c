#include <libclayer/string.h>

#include <assert.h>
#include <stddef.h>

void test_main()
{
    {
        const size_t count = 1024;
        char aaa[count];
        char bbb[count];
        for (size_t i = 0; i < count; ++i) aaa[i] = bbb[i] = i*i;
        assert(LIBCLAYER(memcmp)(aaa, bbb, count) == 0);
        aaa[123] = 1;
        bbb[123] = 2;
        assert(LIBCLAYER(memcmp)(aaa, bbb, count) == -1);
        aaa[123] = 2;
        bbb[123] = 1;
        assert(LIBCLAYER(memcmp)(aaa, bbb, count) == 1);
    }
}
