// Copyright (c) 2021-present James Marjun Jallorina
// All Rights Reserved
//
// Distributed under the "MIT License". See the accompanying LICENSE.rst file.

#include <iostream>
#include <type_traits>
#include "../include/morph/morph.hpp"

int main()
{
    std::cout << std::boolalpha;

    std::cout << "is_floating_point<float>: " << morph::is_floating_point<float>::value << std::endl;
    std::cout << "is_floating_point<double>: " << morph::is_floating_point<double>::value << std::endl;
    std::cout << "is_floating_point<long double>: " << morph::is_floating_point<long double>::value << std::endl;

    std::cout << "is_floating_point<long>: " << morph::is_floating_point<long>::value << std::endl;
}