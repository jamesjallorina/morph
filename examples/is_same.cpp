// Copyright (c) 2021-present James Marjun Jallorina
// All Rights Reserved
//
// Distributed under the "MIT License". See the accompanying LICENSE.rst file.

#include <iostream>
#include "../include/morph/morph.hpp"

int main()
{
    std::cout << "is_same<void, void>: " << morph::is_same<void, void>::value << std::endl;
    std::cout << "is_same<void, void>: " << morph::is_same<void, void>() << std::endl;
    std::cout << "is_same<void, double>: " << morph::is_same<void, double>::value << std::endl;
    std::cout << "is_same<void, double>: " << morph::is_same<void, double>() << std::endl;
}