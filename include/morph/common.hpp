#pragma once

#include <cstddef>

#if __cplusplus > 201103L && __cplusplus < 201500L
#define MORPH_CXX14
#endif

#if __cplusplus > 201103L
#define MORPH_HAS_VARIABLE_TEMPLATES
#endif

#if __cplusplus > 201402L
#define MORPH_CXX17
#endif

/// @brief Only C++17 supports inline variable
#if defined(MORPH_CXX17)
#define MORPH_INLINE_VARIABLE inline
#else
#define MORPH_INLINE_VARIABLE
#endif

#define MORPH_BOOL bool
#define MORPH_INLINE inline
#define MORPH_CONSTEXPR constexpr
#define MORPH_INLINE_CONSTEXPR_BOOL_VARIABLE MORPH_INLINE_VARIABLE MORPH_CONSTEXPR MORPH_BOOL


namespace morph {

/// @brief Helper Classes
template < class T, T v>
struct integral_constant
{
    using value_type  = T;
    using type = integral_constant;
    static constexpr T value = v;

    /// @brief Conversion function based from value_type = T
    constexpr operator value_type() const noexcept { return value; }
    constexpr value_type operator()() const noexcept { return value; }
};

template <bool B>
using bool_constant = integral_constant<bool, B>;

using true_type = integral_constant<bool, true>;
using false_type = integral_constant<bool, false>;

}   // namespace morph
