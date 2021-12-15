#pragma once

namespace morph {
	
template <typename T>
struct add_const { using type = const T; };

template <typename T>
struct add_const<const T> { using type = const T; };

template <typename T>
struct add_const<volatile T> { using type = const volatile T; };

template <typename T>
struct add_const<const volatile T> { using type = const volatile T; };

}	// namespace morph
