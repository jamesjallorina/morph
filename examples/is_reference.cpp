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
    static_assert(morph::is_reference<foo&>::value, "not a reference type");
    static_assert(morph::is_reference<foo&&>::value, "not a reference type");
    static_assert(morph::is_reference<bar&>::value, "not a reference type");
    static_assert(morph::is_reference<bar&&>::value, "not a reference type");
    static_assert(!morph::is_reference<foo>::value, "a reference type");
    static_assert(!morph::is_reference<bar>::value, "a reference type");
}