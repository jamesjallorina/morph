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
    static_assert(!morph::is_rvalue_reference<foo>::value, "an rvalue reference");
    static_assert(morph::is_rvalue_reference<foo&&>::value, "not an rvalue reference");
    static_assert(morph::is_rvalue_reference<int&&>::value, "not an rvalue reference");
    static_assert(!morph::is_rvalue_reference<int>::value, "an rvalue reference");
    static_assert(morph::is_rvalue_reference<double&&>::value, "not an rvalue reference");
    static_assert(morph::is_rvalue_reference<long&&>::value, "not an rvalue reference");
}