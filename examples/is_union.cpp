// Copyright (c) 2021-present James Marjun Jallorina
// All Rights Reserved
//
// Distributed under the "MIT License". See the accompanying LICENSE.rst file.

#include <iostream>
#include "../include/morph/morph.hpp"

struct foo {};
 
typedef union {
    int a;
    float b;
} bar;
 
struct wrap {
    bar b;
};

int main()
{
    static_assert(!morph::is_union<foo>::value, "a union type");
    static_assert(morph::is_union<bar>::value, "not a union type");
    static_assert(!morph::is_union<wrap>::value, "a union type");
    static_assert(!morph::is_union<double>::value, "a union type");
}