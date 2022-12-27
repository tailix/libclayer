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

#define strcat  LIBCLAYER(strcat)
#define strchr  LIBCLAYER(strchr)
#define strcmp  LIBCLAYER(strcmp)
#define strcpy  LIBCLAYER(strcpy)
#define strlen  LIBCLAYER(strlen)

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

    { // strcat
        aaa[0] = 'f'; aaa[1] = 'o'; aaa[2] = 'o'; aaa[3] = '\0';
        strcat(aaa, "bar");
        for (const char *e = "foobar", *g = aaa; *e; ++e, ++g) assert(*g == *e);
        assert(aaa[6] == '\0');
    }

    { // strchr
        const char *const s = "foobar";
        assert(strchr(s, 'f') == &s[0]);
        assert(strchr(s, 'b') == &s[3]);
        assert(strchr(s, 'r') == &s[5]);
        assert(strchr(s, 'x') == NULL);
        assert(strchr(s, 'F') == NULL);
    }

    { // strcmp
        assert(strcmp("", "") == 0);
        assert(strcmp("", "a") == -1);
        assert(strcmp("a", "") == 1);
        assert(strcmp("a", "a") == 0);
        assert(strcmp("a", "aa") == -1);
        assert(strcmp("aa", "a") == 1);
        assert(strcmp("aa", "ab") == -1);
        assert(strcmp("ab", "aa") == 1);
        assert(strcmp("aa", "aa") == 0);
    }

    { // strcpy
        assert(strcpy(aaa, "foobar") == aaa);
        for (const char *e = "foobar", *g = aaa; *e; ++e, ++g) assert(*g == *e);
        assert(aaa[6] == '\0');
    }

    { // strlen
        assert(strlen("") == 0);
        assert(strlen("a") == 1);
        assert(strlen("aa") == 2);
        assert(strlen("aaaaaaaaaa") == 10);
    }
}
