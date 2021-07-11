#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../include/morph/morph.hpp"

TEST_CASE("test is_integral", "[is_integral]")
{
    STATIC_REQUIRE(morph::is_integral<bool>::value);
    STATIC_REQUIRE(morph::is_integral<char>::value);
    STATIC_REQUIRE(morph::is_integral<short>::value);
    STATIC_REQUIRE(morph::is_integral<int>::value);
    STATIC_REQUIRE(morph::is_integral<long>::value);
    STATIC_REQUIRE(morph::is_integral<long long>::value);
    STATIC_REQUIRE_FALSE(morph::is_integral<long *>::value);
}