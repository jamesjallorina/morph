#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../include/morph/morph.hpp"

TEST_CASE("test bool_constant", "[bool_constant]")
{
    STATIC_REQUIRE(morph::bool_constant<true>::value);
    STATIC_REQUIRE(morph::bool_constant<true>());
    STATIC_REQUIRE_FALSE(morph::bool_constant<false>::value);
    STATIC_REQUIRE_FALSE(morph::bool_constant<false>());
}