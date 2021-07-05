// Copyright (c) 2021-present James Marjun Jallorina
// All Rights Reserved
//
// Distributed under the "MIT License". See the accompanying LICENSE.rst file.

#include <iostream>
#include "../include/morph/morph.hpp"

class foo {};

int main()
{
    static_assert(!morph::is_fundamental<foo>::value, "a fundamental type");
    static_assert(morph::is_fundamental<int>::value, "not a fundamental type");
    static_assert(!morph::is_fundamental<int &>::value, "a fundamental type");
    static_assert(!morph::is_fundamental<int *>::value, "a fundamental type");
    static_assert(morph::is_fundamental<float>::value, "not a fundamental type");
    static_assert(!morph::is_fundamental<float &>::value, "a fundamental type");
    static_assert(!morph::is_fundamental<float *>::value, "a fundamental type");
}