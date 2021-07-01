// Copyright (c) 2021-present James Marjun Jallorina
// All Rights Reserved
//
// Distributed under the "MIT License". See the accompanying LICENSE.rst file.

#include <iostream>
#include <type_traits>
#include "../include/morph/morph.hpp"

struct foo {
    void callback() { }
};

struct bar { };
 
int main()
{
    static_assert(morph::is_member_function_pointer<decltype(&foo::callback)>::value, 
                    "foo::callback is not a member function.");
    
    /// @brief uncomment this to check if not the same at compile time
    //static_assert(morph::is_member_function_pointer<decltype(&bar::callback)>::value, 
    //                "foo::callback is not a member function.");
}
