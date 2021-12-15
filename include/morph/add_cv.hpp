#pragma once

namespace morph {
	
template <typename T>
struct add_cv { using type = const volatile T; };

template <typename T>
struct add_cv<const T> { using type = const volatile T; };

template <typename T>
struct add_cv<volatile T> { using type = const volatile T; };

template <typename T>
struct add_cv<const volatile T> { using type = const volatile T; };

}	// namespace morph
