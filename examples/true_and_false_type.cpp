// Copyright (c) 2021-present James Marjun Jallorina
// All Rights Reserved
//
// Distributed under the "MIT License". See the accompanying LICENSE.rst file.

#include <iostream>
#include "../include/morph/morph.hpp"

int main()
{
    std::cout << "true_type: " << morph::true_type::value << std::endl;
    std::cout << "true_type: " << morph::true_type() << std::endl;
    std::cout << "false_type: " << morph::false_type::value << std::endl;
    std::cout << "false_type: " << morph::false_type() << std::endl;
}