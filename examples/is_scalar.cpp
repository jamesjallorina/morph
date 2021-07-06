// Copyright (c) 2021-present James Marjun Jallorina
// All Rights Reserved
//
// Distributed under the "MIT License". See the accompanying LICENSE.rst file.

#include <iostream>
#include "../include/morph/morph.hpp"

class foo {};

int main()
{
    static_assert(morph::is_scalar<int>::value, "not a scalar type");
    static_assert(!morph::is_scalar<foo>::value, "a scalar type");
}