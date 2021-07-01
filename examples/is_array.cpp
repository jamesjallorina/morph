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

    std::cout << "is_array<float>: " << morph::is_array<float[10]>::value << std::endl;
    std::cout << "is_array<double>: " << morph::is_array<double[20]>::value << std::endl;
    std::cout << "is_array<long double>: " << morph::is_array<long double[30]>::value << std::endl;

    std::cout << "is_array<long>: " << morph::is_array<long>::value << std::endl;
}