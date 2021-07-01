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

    std::cout << "is_integral<bool>: " << morph::is_integral<bool>::value << std::endl;
    std::cout << "is_integral<char>: " << morph::is_integral<char>::value << std::endl;
    std::cout << "is_integral<short>: " << morph::is_integral<short>::value << std::endl;
    std::cout << "is_integral<int>: " << morph::is_integral<int>::value << std::endl;
    std::cout << "is_integral<long>: " << morph::is_integral<long>::value << std::endl;
    std::cout << "is_integral<long long>: " << morph::is_integral<long long>::value << std::endl;

    std::cout << "is_integral<long *>: " << morph::is_integral<long *>::value << std::endl;
}