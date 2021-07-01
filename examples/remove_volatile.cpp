// Copyright (c) 2021-present James Marjun Jallorina
// All Rights Reserved
//
// Distributed under the "MIT License". See the accompanying LICENSE.rst file.

#include <iostream>
#include <type_traits>
#include "../include/morph/morph.hpp"

int main()
{
    static_assert(std::is_same<morph::remove_volatile<volatile int>::type, int>::value, "not the same");
    static_assert(std::is_same<morph::remove_volatile<int>::type, int>::value, "not the same");

    /// @brief uncomment this to check if not the same at compile time
    //static_assert(std::is_same<morph::remove_volatile<double>::type, int>::value, "not the same");
}