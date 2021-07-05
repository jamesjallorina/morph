// Copyright (c) 2021-present James Marjun Jallorina
// All Rights Reserved
//
// Distributed under the "MIT License". See the accompanying LICENSE.rst file.

#include <iostream>
#include "../include/morph/morph.hpp"

class foo {};

int main() {
    
    std::cout << (morph::is_member_pointer<int(foo::*)>::value
                     ? "T is member pointer"
                     : "T is not a member pointer") << '\n';
    std::cout << (morph::is_member_pointer<int>::value
                     ? "T is member pointer"
                     : "T is not a member pointer") << '\n';
}