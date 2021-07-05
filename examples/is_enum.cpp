// Copyright (c) 2021-present James Marjun Jallorina
// All Rights Reserved
//
// Distributed under the "MIT License". See the accompanying LICENSE.rst file.

#include <iostream>
#include "../include/morph/morph.hpp"

class foo {};
 
enum bar {};
 
enum class ec : int {};

int main()
{
    static_assert(!morph::is_enum<foo>::value, "an enum type");
    static_assert(morph::is_enum<bar>::value, "not an enum type");
    static_assert(morph::is_enum<ec>::value, "not an enum type");
    static_assert(!morph::is_enum<double>::value, "an enum type");
}