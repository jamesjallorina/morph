// Copyright (c) 2021-present James Marjun Jallorina
// All Rights Reserved
//
// Distributed under the "MIT License". See the accompanying LICENSE.rst file.

#include <iostream>
#include "../include/morph/morph.hpp"

int main()
{
    std::cout << "integral_constant<int, 2>::value: " 
                << morph::integral_constant<int, 2>::value << std::endl;
    std::cout << "integral_constant<int, 2>::value: " 
                << morph::integral_constant<int, 2>() << std::endl;
    std::cout << "integral_constant<int, 4>::value: " 
                << morph::integral_constant<int, 4>::value << std::endl;
    std::cout << "integral_constant<int, 4>::value: " 
                << morph::integral_constant<int, 4>() << std::endl;
}