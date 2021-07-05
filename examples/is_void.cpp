// Copyright (c) 2021-present James Marjun Jallorina
// All Rights Reserved
//
// Distributed under the "MIT License". See the accompanying LICENSE.rst file.

#include <iostream>
#include "../include/morph/morph.hpp"

int main()
{
    std::cout << std::boolalpha;

    std::cout << "is_void<void>: " << morph::is_void<void>::value << std::endl;
    std::cout << "is_void<const void>: " << morph::is_void<const void>::value <<std::endl;
    std::cout << "is_void<const volatile void>: " << morph::is_void<const volatile void>::value << std::endl;
    std::cout << "is_void<int>: " << morph::is_void<int>::value << std::endl;
    std::cout << "is_void<float>: " << morph::is_void<float>::value << std::endl;
    std::cout << "is_void<double>: " << morph::is_void<double>::value << std::endl;
}