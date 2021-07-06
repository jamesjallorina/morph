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
    static_assert(morph::is_object<foo>::value, "not an object type");
    static_assert(morph::is_object<bar>::value, "not an object type");
    static_assert(!morph::is_object<foo&>::value, "an object type");
    static_assert(!morph::is_object<bar&>::value, "an object type");
    static_assert(!morph::is_object<foo&&>::value, "an object type");
    static_assert(!morph::is_object<bar&&>::value, "an object type");
}