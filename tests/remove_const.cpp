#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <type_traits>
#include "../include/morph/morph.hpp"

TEST_CASE("test remove_const", "[remove_const]")
{
    STATIC_REQUIRE(std::is_same<morph::remove_const<const int>::type, int>::value);
    STATIC_REQUIRE(std::is_same<morph::remove_const<const volatile int>::type, volatile int>::value);
    STATIC_REQUIRE(std::is_same<morph::remove_const<int>::type, int>::value);
    STATIC_REQUIRE_FALSE(std::is_same<morph::remove_const<const int>::type, const int>::value);
    STATIC_REQUIRE_FALSE(std::is_same<morph::remove_const<const volatile int>::type, 
            const volatile int>::value);
}