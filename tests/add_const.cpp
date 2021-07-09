#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <type_traits>
#include "../include/morph/morph.hpp"

TEST_CASE("test add_const", "[add_const]")
{
    STATIC_REQUIRE(std::is_same<morph::add_const<int>::type, 
                    const int>::value);
    STATIC_REQUIRE(std::is_same<morph::add_const<const int>::type, 
                    const int>::value);
    STATIC_REQUIRE(std::is_same<morph::add_const<volatile int>::type, 
                    const volatile int>::value);
    STATIC_REQUIRE(std::is_same<morph::add_const<const volatile int>::type,
                    const volatile  int>::value);
    STATIC_REQUIRE_FALSE(std::is_same<morph::add_const<int>::type, 
                    int>::value);
    STATIC_REQUIRE_FALSE(std::is_same<morph::add_const<const int>::type, 
                    int>::value);
    STATIC_REQUIRE_FALSE(std::is_same<morph::add_const<volatile int>::type, 
                    int>::value);
    STATIC_REQUIRE_FALSE(std::is_same<morph::add_const<const volatile int>::type,
                    int>::value);
}