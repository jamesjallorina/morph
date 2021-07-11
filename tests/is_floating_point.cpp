#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../include/morph/morph.hpp"


TEST_CASE("test is_floating_point", "[is_floating_point]")
{
    STATIC_REQUIRE(morph::is_floating_point<float>::value);
    STATIC_REQUIRE(morph::is_floating_point<double>::value);
    STATIC_REQUIRE(morph::is_floating_point<long double>::value);
    STATIC_REQUIRE_FALSE(morph::is_floating_point<long>::value);
}