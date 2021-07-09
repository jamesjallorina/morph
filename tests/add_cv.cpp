#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <type_traits>
#include "../include/morph/morph.hpp"

TEST_CASE("test add_cv", "[add_cv]")
{
    STATIC_REQUIRE(std::is_same<morph::add_cv<int>::type,
                    const volatile int>::value);
    STATIC_REQUIRE(std::is_same<morph::add_cv<const int>::type, 
                    const volatile int>::value);
    STATIC_REQUIRE(std::is_same<morph::add_cv<volatile int>::type, 
                    const volatile int>::value);
    STATIC_REQUIRE(std::is_same<morph::add_cv<const volatile int>::type,
                    const volatile int>::value);
    STATIC_REQUIRE_FALSE(std::is_same<morph::add_cv<int>::type,
                    int>::value);
    STATIC_REQUIRE_FALSE(std::is_same<morph::add_cv<const int>::type, 
                    int>::value);
    STATIC_REQUIRE_FALSE(std::is_same<morph::add_cv<volatile int>::type, 
                    int>::value);
    STATIC_REQUIRE_FALSE(std::is_same<morph::add_cv<const volatile int>::type,
                    int>::value);
}