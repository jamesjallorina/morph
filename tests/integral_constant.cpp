#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../include/morph/morph.hpp"

TEST_CASE("test bool_constant", "[bool_constant]")
{
    STATIC_REQUIRE(morph::integral_constant<int, 2>::value == 2);
    STATIC_REQUIRE(morph::integral_constant<int, 2>() == 2);
    STATIC_REQUIRE(morph::integral_constant<int, 4>::value == 4);
    STATIC_REQUIRE(morph::integral_constant<int, 4>() == 4);
}