// Copyright (c) 2021-present James Marjun Jallorina
// All Rights Reserved
//
// Distributed under the "MIT License". See the accompanying LICENSE.rst file.

#include <iostream>
#include <type_traits>
#include "../include/morph/morph.hpp"

class foo {};

int main()
{
    static_assert(morph::is_pointer<int*>::value, "not a pointer type");
    static_assert(morph::is_pointer<double*>::value, "not a pointer type");
    static_assert(morph::is_pointer<long*>::value, "not a pointer type");
    static_assert(morph::is_pointer<foo*>::value, "not a pointer type");

    /// @brief uncomment this to check if not the same at compile time
    /// static_assert(morph::is_pointer<foo>::value, "not a pointer type");
}