#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../include/morph/morph.hpp"

struct foo {};

class bar {};

enum class ec {};


TEST_CASE("test is_class", "[is_class]")
{
    STATIC_REQUIRE(morph::is_class<foo>::value);
    STATIC_REQUIRE(morph::is_class<bar>::value);
    STATIC_REQUIRE_FALSE(morph::is_class<ec>::value);
    STATIC_REQUIRE_FALSE(morph::is_class<long>::value);
}