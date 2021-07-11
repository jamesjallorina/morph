#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../include/morph/morph.hpp"

class foo {};

TEST_CASE("test is_array", "[is_array]")
{
    STATIC_REQUIRE(morph::is_array<float[10]>::value);
    STATIC_REQUIRE(morph::is_array<double[20]>::value);
    STATIC_REQUIRE(morph::is_array<long double[30]>::value);
    STATIC_REQUIRE_FALSE(morph::is_array<long>::value);
}