// Copyright (c) 2021-present James Marjun Jallorina
// All Rights Reserved
//
// Distributed under the "MIT License". See the accompanying LICENSE.rst file.

#include <iostream>
#include <type_traits>
#include "../include/morph/morph.hpp"

/// @brief from cppreference example
struct A {
    int fun() const&;
};
 
template<typename>
struct PM_traits {};
 
template<class T, class U>
struct PM_traits<U T::*> {
    using member_type = U;
};
 
int f();
 
int main() 
{
    std::cout << std::boolalpha;

    std::cout << morph::is_function<A>::value << '\n';
    std::cout << morph::is_function<int(int)>::value << '\n';
    std::cout << morph::is_function<decltype(f)>::value << '\n';
    std::cout << morph::is_function<int>::value << '\n';
 
    using T = PM_traits<decltype(&A::fun)>::member_type; // T is int() const&
    std::cout << morph::is_function<T>::value << '\n';
}