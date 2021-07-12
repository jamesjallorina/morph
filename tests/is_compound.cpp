#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../include/morph/morph.hpp"

class foo {};

struct bar {};

TEST_CASE("test is_compound", "[is_compound]")
{
    STATIC_REQUIRE(morph::is_compound<foo>::value);
    STATIC_REQUIRE(morph::is_compound<bar>::value);
    STATIC_REQUIRE_FALSE(morph::is_compound<int>::value);
    STATIC_REQUIRE_FALSE(morph::is_compound<float>::value);
    STATIC_REQUIRE_FALSE(morph::is_compound<double>::value);
    STATIC_REQUIRE_FALSE(morph::is_compound<long>::value);
}