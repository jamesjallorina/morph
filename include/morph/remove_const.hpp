#pragma once

namespace morph {

template <typename T>
struct remove_const { using type = T; };

template <typename T>
struct remove_const<const T> { using type = T; };

}	// namespace morph
