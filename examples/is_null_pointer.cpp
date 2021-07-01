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

    std::cout << "is_null_pointer<nullptr>: " << 
            morph::is_null_pointer<decltype(nullptr)>::value << std::endl;
    std::cout << "is_null_pointer<int *>: " << 
            morph::is_null_pointer<int *>::value << std::endl;
    std::cout << "is_null_pointer<float *>: " << 
            morph::is_null_pointer<float *>::value << std::endl;
    std::cout << "is_null_pointer<double *>: " << 
            morph::is_null_pointer<double *>::value << std::endl;
}