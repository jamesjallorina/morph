#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../include/morph/morph.hpp"

class foo {};

TEST_CASE("test is_fundamental", "[is_fundamental]")
{
    STATIC_REQUIRE_FALSE(morph::is_fundamental<foo>::value);
    STATIC_REQUIRE(morph::is_fundamental<int>::value);
    STATIC_REQUIRE_FALSE(morph::is_fundamental<int &>::value);
    STATIC_REQUIRE_FALSE(morph::is_fundamental<int *>::value);
    STATIC_REQUIRE(morph::is_fundamental<float>::value);
    STATIC_REQUIRE_FALSE(morph::is_fundamental<float &>::value);
    STATIC_REQUIRE_FALSE(morph::is_fundamental<float *>::value);
}