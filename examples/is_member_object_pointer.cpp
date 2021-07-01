// Copyright (c) 2021-present James Marjun Jallorina
// All Rights Reserved
//
// Distributed under the "MIT License". See the accompanying LICENSE.rst file.

#include <iostream>
#include <type_traits>
#include "../include/morph/morph.hpp"


#include <iostream>
#include <type_traits>
 
class foo {};

int main() {
    
    std::cout << (morph::is_member_object_pointer<int(foo::*)>::value
                     ? "T is member object pointer"
                     : "T is not a member object pointer") << '\n';
    std::cout << (morph::is_member_object_pointer<int(foo::*)()>::value
                     ? "T is member object pointer"
                     : "T is not a member object pointer") << '\n';
}