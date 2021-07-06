// Copyright (c) 2021-present James Marjun Jallorina
// All Rights Reserved
//
// Distributed under the "MIT License". See the accompanying LICENSE.rst file.

#include <iostream>
#include "../include/morph/morph.hpp"

class foo {};

struct bar {};

int main()
{
    static_assert(morph::is_compound<foo>::value, "not a compound type");
    static_assert(morph::is_compound<bar>::value, "not a compound type");
    static_assert(!morph::is_compound<int>::value, "a compound type");
    static_assert(!morph::is_compound<float>::value, "a compound type");
    static_assert(!morph::is_compound<double>::value, "a compound type");
    static_assert(!morph::is_compound<long>::value, "a compound type");
}