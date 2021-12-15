#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <type_traits>
#include "../include/morph/morph.hpp"

TEST_CASE("test remove_cv", "[remove_cv]")
{
    STATIC_REQUIRE(std::is_same<morph::remove_cv<const int>::type, int>::value);
    STATIC_REQUIRE(std::is_same<morph::remove_cv<const volatile int>::type, int>::value);
    STATIC_REQUIRE(std::is_same<morph::remove_cv<int>::type, int>::value);
    STATIC_REQUIRE_FALSE(std::is_same<morph::remove_cv<const int>::type, const int>::value);
    STATIC_REQUIRE_FALSE(std::is_same<morph::remove_cv<const volatile int>::type, 
            const volatile int>::value);
}
