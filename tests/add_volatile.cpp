#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <type_traits>
#include "../include/morph/morph.hpp"

TEST_CASE("test add_volatile", "[add_volatile]")
{
    STATIC_REQUIRE(std::is_same<morph::add_volatile<int>::type,
                    volatile int>::value);
    STATIC_REQUIRE(std::is_same<morph::add_volatile<const int>::type, 
                    const volatile int>::value);
    STATIC_REQUIRE(std::is_same<morph::add_volatile<volatile int>::type, 
                    volatile int>::value);
    STATIC_REQUIRE(std::is_same<morph::add_volatile<const volatile int>::type,
                    const volatile int>::value);
    STATIC_REQUIRE_FALSE(std::is_same<morph::add_volatile<int>::type,
                    int>::value);
    STATIC_REQUIRE_FALSE(std::is_same<morph::add_volatile<const int>::type, 
                    int>::value);
    STATIC_REQUIRE_FALSE(std::is_same<morph::add_volatile<volatile int>::type, 
                    int>::value);
    STATIC_REQUIRE_FALSE(std::is_same<morph::add_volatile<const volatile int>::type,
                    int>::value);
}