// Copyright (c) 2021-present James Marjun Jallorina
// All Rights Reserved
//
// Distributed under the "MIT License". See the accompanying LICENSE.rst file.

#include <iostream>
#include "../include/morph/morph.hpp"

struct foo {};

class bar {};

enum class ec {};

int main()
{
    static_assert(morph::is_class<foo>::value, "not a class type");
    static_assert(morph::is_class<bar>::value, "not a class type");
    static_assert(!morph::is_class<ec>::value, "a class type");
    static_assert(!morph::is_class<long>::value, "a class type");
}