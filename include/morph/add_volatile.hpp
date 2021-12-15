#pragma once

namespace morph {

template <typename T>
struct add_volatile { using type = volatile T; };

template <typename T>
struct add_volatile<const T> { using type = const volatile T; };

template <typename T>
struct add_volatile<volatile T> { using type = volatile T; };

template <typename T>
struct add_volatile<const volatile T> { using type = const volatile T; };

}	// namespace morph
