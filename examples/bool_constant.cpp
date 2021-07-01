// Copyright (c) 2021-present James Marjun Jallorina
// All Rights Reserved
//
// Distributed under the "MIT License". See the accompanying LICENSE.rst file.

#include <iostream>
#include "../include/morph/morph.hpp"

int main()
{
    std::cout << "bool_constant<true>: " << morph::bool_constant<true>::value << std::endl;
    std::cout << "bool_constant<true>: " << morph::bool_constant<true>() << std::endl;
    std::cout << "bool_constant<false>: " << morph::bool_constant<false>::value << std::endl;
    std::cout << "bool_constant<false>: " << morph::bool_constant<false>() << std::endl;
}