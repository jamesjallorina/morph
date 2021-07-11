#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../include/morph/morph.hpp"


struct foo {
    int fun() const&;
};
 
int bar();


TEST_CASE("test is_function", "[is_function]")
{
    STATIC_REQUIRE_FALSE(morph::is_function<foo>::value);
    STATIC_REQUIRE(morph::is_function<int(int)>::value);
    STATIC_REQUIRE(morph::is_function<decltype(bar)>::value);
    STATIC_REQUIRE_FALSE(morph::is_function<int>::value);
}