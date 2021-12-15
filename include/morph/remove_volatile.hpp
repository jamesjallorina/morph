#pragma once

namespace morph {
	
template <typename T>
struct remove_volatile { using type = T; };

template <typename T>
struct remove_volatile<volatile T> { using type = T; };

}	// namespace morph
