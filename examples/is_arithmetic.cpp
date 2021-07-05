// Copyright (c) 2021-present James Marjun Jallorina
// All Rights Reserved
//
// Distributed under the "MIT License". See the accompanying LICENSE.rst file.

#include <iostream>
#include "../include/morph/morph.hpp"

class foo {};

int main()
{
    static_assert(!morph::is_arithmetic<foo>::value, "an arithmetic type");
    static_assert(morph::is_arithmetic<bool>::value, "not an arithmetic type");
    static_assert(morph::is_arithmetic<int>::value, "not an arithmetic type");
    static_assert(morph::is_arithmetic<int const>::value, "not an arithmetic type");
    static_assert(!morph::is_arithmetic<int &>::value, "an arithmetic type");
    static_assert(!morph::is_arithmetic<int *>::value, "an arithmetic type");
    static_assert(morph::is_arithmetic<float>::value, "not an arithmetic type");
    static_assert(morph::is_arithmetic<float const>::value, "not an arithmetic type");
    static_assert(!morph::is_arithmetic<float &>::value, "an arithmetic type");
    static_assert(!morph::is_arithmetic<float *>::value, "an arithmetic type");
    static_assert(morph::is_arithmetic<char>::value, "not an arithmetic type");
    static_assert(morph::is_arithmetic<char const>::value, "not an arithmetic type");
    static_assert(!morph::is_arithmetic<char &>::value, "an arithmetic type");
    static_assert(!morph::is_arithmetic<char *>::value, "an arithmetic type");
}