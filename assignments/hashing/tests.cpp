#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../../commons/doctest.h"

#include "Dictionary.h"

TEST_CASE("valid size")
{
   CHECK_NOTHROW(new Dictionary(1));
   CHECK_THROWS(new Dictionary(0), INVALID_SIZE);
}

TEST_CASE("hash")
{
   Dictionary *d = new Dictionary(3);
   CHECK(d->hash("hash") == ('h' + 'a' + 's' + 'h') % 3);
   CHECK(d->hash("") == 0);
}