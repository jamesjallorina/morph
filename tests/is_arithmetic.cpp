#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../include/morph/morph.hpp"

class foo {};

TEST_CASE("test is_arithmetic", "[is_arithmetic]")
{
    STATIC_REQUIRE_FALSE(morph::is_arithmetic<foo>::value);
    STATIC_REQUIRE(morph::is_arithmetic<bool>::value);
    STATIC_REQUIRE(morph::is_arithmetic<int>::value);
    STATIC_REQUIRE(morph::is_arithmetic<int const>::value);
    STATIC_REQUIRE_FALSE(morph::is_arithmetic<int &>::value);
    STATIC_REQUIRE_FALSE(morph::is_arithmetic<int *>::value);
    STATIC_REQUIRE(morph::is_arithmetic<float>::value);
    STATIC_REQUIRE(morph::is_arithmetic<float const>::value);
    STATIC_REQUIRE_FALSE(morph::is_arithmetic<float &>::value);
    STATIC_REQUIRE_FALSE(morph::is_arithmetic<float *>::value);
    STATIC_REQUIRE(morph::is_arithmetic<char>::value);
    STATIC_REQUIRE(morph::is_arithmetic<char const>::value);
    STATIC_REQUIRE_FALSE(morph::is_arithmetic<char &>::value);
    STATIC_REQUIRE_FALSE(morph::is_arithmetic<char *>::value);
}