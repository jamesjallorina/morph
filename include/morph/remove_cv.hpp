#pragma once

namespace morph {

/// @brief Const-volatility specifiers
template <typename T>
struct remove_cv { using type = T; };

template <typename T>
struct remove_cv<const T> { using type = T; };

template <typename T>
struct remove_cv<volatile T> { using type = T; };

template <typename T>
struct remove_cv<const volatile T> { using type = T; };

}   // namespace morph
