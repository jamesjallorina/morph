#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../include/morph/morph.hpp"

class foo {};
 
enum bar {};
 
enum class ec : int {};


TEST_CASE("test is_enum", "[is_enum]")
{
    STATIC_REQUIRE_FALSE(morph::is_enum<foo>::value);
    STATIC_REQUIRE(morph::is_enum<bar>::value);
    STATIC_REQUIRE(morph::is_enum<ec>::value);
    STATIC_REQUIRE_FALSE(morph::is_enum<double>::value);
}