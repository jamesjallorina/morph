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
    static_assert(!morph::is_lvalue_reference<foo>::value, "an lvalue reference");
    static_assert(morph::is_lvalue_reference<foo&>::value, "not an lvalue reference");
    static_assert(!morph::is_lvalue_reference<foo&&>::value, "an lvalue reference");
    static_assert(!morph::is_lvalue_reference<int>::value, "an lvalue reference");
    static_assert(morph::is_lvalue_reference<int&>::value, "not an lvalue reference");
    static_assert(!morph::is_lvalue_reference<int&&>::value, "an lvalue reference");
}