#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../include/morph/morph.hpp"

class foo {};

TEST_CASE("test is_lvalue_reference", "[is_lvalue_reference]")
{
    STATIC_REQUIRE_FALSE(morph::is_lvalue_reference<foo>::value);
    STATIC_REQUIRE(morph::is_lvalue_reference<foo&>::value);
    STATIC_REQUIRE_FALSE(morph::is_lvalue_reference<foo&&>::value);
    STATIC_REQUIRE_FALSE(morph::is_lvalue_reference<int>::value);
    STATIC_REQUIRE(morph::is_lvalue_reference<int&>::value);
    STATIC_REQUIRE_FALSE(morph::is_lvalue_reference<int&&>::value);
}