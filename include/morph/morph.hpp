// Copyright (c) 2021-present James Marjun Jallorina
// All Rights Reserved
//
// Distributed under the "MIT License". See the accompanying LICENSE.rst file.

#ifndef MORPH_HPP
#define MORPH_HPP

#include <cstddef>

/// @brief The implementation is based from 
///        "en.cppreference.com/w/cpp/header/type_traits"
///        specification

#if __cplusplus > 201103L && __cplusplus < 201500L
#define MORPH_CXX14
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

using nullptr_t = decltype(nullptr);

/// @brief Const-volatility specifiers
template <typename T>
struct remove_cv { using type = T; };

template <typename T>
struct remove_cv<const T> { using type = T; };

template <typename T>
struct remove_cv<volatile T> { using type = T; };

template <typename T>
struct remove_cv<const volatile T> { using type = T; };

template <typename T>
struct remove_const { using type = T; };

template <typename T>
struct remove_const<const T> { using type = T; };

template <typename T>
struct remove_volatile { using type = T; };

template <typename T>
struct remove_volatile<volatile T> { using type = T; };

template <typename T>
struct add_cv { using type = const volatile T; };

template <typename T>
struct add_cv<const T> { using type = const volatile T; };

template <typename T>
struct add_cv<volatile T> { using type = const volatile T; };

template <typename T>
struct add_cv<const volatile T> { using type = const volatile T; };

template <typename T>
struct add_const { using type = const T; };

template <typename T>
struct add_const<const T> { using type = const T; };

template <typename T>
struct add_const<volatile T> { using type = const volatile T; };

template <typename T>
struct add_const<const volatile T> { using type = const volatile T; };

template <typename T>
struct add_volatile { using type = volatile T; };

template <typename T>
struct add_volatile<const T> { using type = const volatile T; };

template <typename T>
struct add_volatile<volatile T> { using type = volatile T; };

template <typename T>
struct add_volatile<const volatile T> { using type = const volatile T; };

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



namespace detail {

template <class T, class U>
struct is_same_base : false_type{};

template <class T>
struct is_same_base<T,T> : true_type{};

template <class T>
struct is_void_base : is_same_base<void, T> {};

template <class T>
struct is_null_pointer_base : is_same_base<nullptr_t, T> {};

template <class T>
struct is_integral_base : false_type {};

template <> struct is_integral_base<bool> : true_type {};
template <> struct is_integral_base<char> : true_type {};
template <> struct is_integral_base<unsigned char> : true_type {};
template <> struct is_integral_base<signed char> : true_type {};
template <> struct is_integral_base<wchar_t> : true_type {};
template <> struct is_integral_base<short> : true_type {};
template <> struct is_integral_base<unsigned short> : true_type {};
template <> struct is_integral_base<int> : true_type {};
template <> struct is_integral_base<unsigned int> : true_type {};
template <> struct is_integral_base<long> : true_type {};
template <> struct is_integral_base<unsigned long> : true_type {};
template <> struct is_integral_base<long long> : true_type {};
template <> struct is_integral_base<unsigned long long> : true_type {};

}   // namespace detail

template <class T>
struct is_integral : detail::is_integral_base<typename remove_cv<T>::type>{};

namespace detail {

template <class T>
struct is_floating_point_base : false_type {};

template <> struct is_floating_point_base<float> : true_type {};
template <> struct is_floating_point_base<double> : true_type {};
template <> struct is_floating_point_base<long double> : true_type {};

template <class T>
struct is_array_base : false_type {};

template <class T, std::size_t N>
struct is_array_base<T[N]> : true_type {};

template <class T>
struct is_array_base<T[]> : true_type {};

#if defined(__has_feature) && defined(__clang__)

#define _LIBCPP_VISIBLE
struct two {char __lx[2];};

#if __has_feature(is_union) || (__GNUC__ > 4) || (__GNUC__ == 4 && __GNUC_MINOR__ >= 3)

template <class T> struct _LIBCPP_VISIBLE is_union_base : 
                                        integral_constant<bool, __is_union(T)> {};

#else

template <class T> struct __libcpp_union : false_type {};
template <class T> struct _LIBCPP_VISIBLE is_union_base
    : __libcpp_union<typename remove_cv<T>::type> {};
#endif

#if __has_feature(is_class) || (__GNUC__ > 4) || (__GNUC__ == 4 && __GNUC_MINOR__ >= 3)

template <class T> struct _LIBCPP_VISIBLE is_class_base : 
                                        integral_constant<bool, __is_class(T)> {};

#else

namespace is_class_imp {
template <class T> char test(int T::*);
template <class T> two test(...);
}   // namespace is_class_imp

template <class T> struct _LIBCPP_VISIBLE is_class_base : integral_constant<bool, 
                                        sizeof(is_class_imp::test<T>(0)) == 1 && 
                                        !is_union_base<T>::value> {};

#endif

#if __has_feature(is_enum) || (__GNUC__ > 4) || (__GNUC__ == 4 && __GNUC_MINOR__ >= 3)

template <class T> struct _LIBCPP_VISIBLE is_enum_base : 
                                        integral_constant<bool, __is_enum(T)> {};

#else

template <class T> struct _LIBCPP_VISIBLE is_enum_base : integral_constant<bool, 
                                    !is_void<T>::value &&
                                    !is_integral_base<T>::value &&
                                    !is_floating_point_base<T>::value   &&
                                    !is_array_base<T>::value &&
                                    !is_pointer_base<T>::value &&
                                    !is_reference_base<T>::value &&
                                    !is_member_pointer_base<T>::value &&
                                    !is_union_base<T>::value &&
                                    !is_class_base<T>::value &&
                                    !is_function_base<T>::value> {};

#endif

#endif

#if !defined(has_feature) && defined(__GNUC__)

/// @brief use compiler intrinsics for GNU C++ compiler
template<typename T>
struct is_enum_base : integral_constant<bool, __is_enum(T)>{};

template<typename T>
struct is_union_base : integral_constant<bool, __is_union(T)>{};

template<typename T>
struct is_class_base : integral_constant<bool, __is_class(T)>{};

#endif


template <class T>
struct is_function_base : false_type {};

/// @brief specialization for function for regular functions
template <class Ret, class ...Args>
struct is_function_base<Ret(Args...)> : true_type {};

/// @brief specialization for variadic functions such as std::printf
template <class Ret, class ...Args>
struct is_function_base<Ret(Args......)> : true_type {};

/// @brief specialization for function that have cv-qualifiers
template <class Ret, class ...Args>
struct is_function_base<Ret(Args...) const> : true_type {};

template <class Ret, class ...Args>
struct is_function_base<Ret(Args...) volatile> : true_type {};

template <class Ret, class ...Args>
struct is_function_base<Ret(Args...) const volatile> : true_type {};

template <class Ret, class ...Args>
struct is_function_base<Ret(Args......) const> : true_type {};

template <class Ret, class ...Args>
struct is_function_base<Ret(Args......) volatile> : true_type {};

template <class Ret, class ...Args>
struct is_function_base<Ret(Args......) const volatile> : true_type {};

/// @brief specialization for function that have ref-qualifiers
template <class Ret, class ...Args>
struct is_function_base<Ret(Args...) &> : true_type {};

template <class Ret, class ...Args>
struct is_function_base<Ret(Args...) const &> : true_type {};

template <class Ret, class ...Args>
struct is_function_base<Ret(Args...) volatile &> : true_type {};

template <class Ret, class ...Args>
struct is_function_base<Ret(Args...) const volatile &> : true_type {};

template <class Ret, class ...Args>
struct is_function_base<Ret(Args......) &> : true_type {};

template <class Ret, class ...Args>
struct is_function_base<Ret(Args......) const &> : true_type {};

template <class Ret, class ...Args>
struct is_function_base<Ret(Args......) volatile &> : true_type {};

template <class Ret, class ...Args>
struct is_function_base<Ret(Args......) const volatile &> : true_type {};

template <class Ret, class ...Args>
struct is_function_base<Ret(Args...) &&> : true_type {};

template <class Ret, class ...Args>
struct is_function_base<Ret(Args...) const &&> : true_type {};

template <class Ret, class ...Args>
struct is_function_base<Ret(Args...) volatile &&> : true_type {};

template <class Ret, class ...Args>
struct is_function_base<Ret(Args...) const volatile &&> : true_type {};

template <class Ret, class ...Args>
struct is_function_base<Ret(Args......) &&> : true_type {};

template <class Ret, class ...Args>
struct is_function_base<Ret(Args......) const &&> : true_type {};

template <class Ret, class ...Args>
struct is_function_base<Ret(Args......) volatile &&> : true_type {};

template <class Ret, class ...Args>
struct is_function_base<Ret(Args......) const volatile &&> : true_type {};

template <class T>
struct is_pointer_base : false_type {};

template <class T>
struct is_pointer_base<T*> : true_type {};

template <class T>
struct is_lvalue_reference_base : false_type {};

template <class T>
struct is_lvalue_reference_base<T&> : true_type {};

template <class T>
struct is_rvalue_reference_base : false_type {};

template <class T>
struct is_rvalue_reference_base<T&&> : true_type {};

template <class T>
struct is_member_function_pointer_base : false_type{};

template <class T, class U>
struct is_member_function_pointer_base<T U::*> : is_function_base<T> {};

template <class T>
struct is_member_pointer_base : false_type {};

template <class T, class U>
struct is_member_pointer_base<T U::*> : true_type {};

template <class T>
struct is_member_object_pointer_base : integral_constant<bool, 
                                                        is_member_pointer_base<T>::value && 
                                                        !is_member_function_pointer_base<T>::value> {};

template <class T>
struct is_arithmetic_base : integral_constant<bool, 
                                    is_integral<T>::value ||
                                    is_floating_point_base<T>::value>{};

template <class T>
struct is_fundamental_base : integral_constant<bool,
                                    is_arithmetic_base<T>::value ||
                                    is_void_base<T>::value ||
                                    is_null_pointer_base<T>::value>{};

template <class T>
struct is_scalar_base : integral_constant<bool,
                                is_arithmetic_base<T>::value ||
                                is_pointer_base<T>::value ||
                                is_member_pointer_base<T>::value ||
                                is_enum_base<T>::value ||
                                is_null_pointer_base<T>::value>{};

template <class T>
struct is_object_base : integral_constant<bool,
                                is_scalar_base<T>::value ||
                                is_array_base<T>::value ||
                                is_union_base<T>::value ||
                                is_class_base<T>::value> {};


template <class T>
struct is_reference_base : integral_constant<bool,
                                    is_lvalue_reference_base<T>::value ||
                                    is_rvalue_reference_base<T>::value> {};


template <class T>
struct is_compund_base : integral_constant<bool,
                                is_array_base<T>::value ||
                                is_function_base<T>::value ||
                                is_pointer_base<T>::value ||
                                is_member_pointer_base<T>::value ||
                                is_member_function_pointer_base<T>::value ||
                                is_reference_base<T>::value ||
                                is_class_base<T>::value ||
                                is_union_base<T>::value ||
                                is_enum_base<T>::value> {};

}   // namespace detail

/// @brief Primary type categories
template <class T, class U>
struct is_same : detail::is_same_base<T, U>{};

template <class T>
struct is_void : detail::is_void_base<typename remove_cv<T>::type>{};

template <class T>
struct is_null_pointer : detail::is_null_pointer_base<typename remove_cv<T>::type> {};

template <class T>
struct is_floating_point : detail::is_floating_point_base<typename remove_cv<T>::type> {};

template <class T>
struct is_array : detail::is_array_base<typename remove_cv<T>::type> {};

template<typename T>
struct is_enum : detail::is_enum_base<T>{};

template<typename T>
struct is_union : detail::is_union_base<T>{};

template<typename T>
struct is_class : detail::is_class_base<T>{};

template <class T>
struct is_function : detail::is_function_base<T> {};

template <class T>
struct is_pointer : detail::is_pointer_base<typename remove_cv<T>::type> {};

template <class T>
struct is_lvalue_reference : detail::is_lvalue_reference_base<typename remove_cv<T>::type> {};

template <class T>
struct is_rvalue_reference : detail::is_rvalue_reference_base<typename remove_cv<T>::type> {};

template <class T>
struct is_member_function_pointer : detail::is_member_function_pointer_base<typename remove_cv<T>::type> {};

template <class T>
struct is_member_object_pointer : detail::is_member_object_pointer_base<T> {};

template <class T>
struct is_fundamental : detail::is_fundamental_base<typename remove_cv<T>::type>{};

template <class T>
struct is_arithmetic : detail::is_arithmetic_base<typename remove_cv<T>::type>{};

template <class T>
struct is_scalar : detail::is_scalar_base<typename remove_cv<T>::type>{};

template <class T>
struct is_object : detail::is_object_base<typename remove_cv<T>::type>{};

template <class T>
struct is_compound : detail::is_compund_base<typename remove_cv<T>::type>{};

template <class T>
struct is_reference : detail::is_reference_base<typename remove_cv<T>::type>{};

template <class T>
struct is_member_pointer : detail::is_member_pointer_base<typename remove_cv<T>::type> {};

/// @brief C++14-style aliases for brevity
template <typename T>
using remove_cv_t = typename remove_cv<T>::type;

template <typename T>
using remove_const_t = typename remove_const<T>::type;

template <typename T>
using remove_volatile_t = typename remove_volatile<T>::type;

template <typename T>
using add_cv_t = typename add_cv<T>::type;

template <typename T>
using add_const_t = typename add_const<T>::type;

template <typename T>
using add_volatile_t = typename add_volatile<T>::type;

#if defined(MORPH_CXX14) && defined(MORPH_HAS_VARIABLE_TEMPLATES)

template <class T>
MORPH_INLINE_CONSTEXPR_BOOL_VARIABLE is_void_v = is_void<T>::value;

template <class T>
MORPH_INLINE_CONSTEXPR_BOOL_VARIABLE is_null_pointer_v = is_null_pointer<T>::value;

template <class T>
MORPH_INLINE_CONSTEXPR_BOOL_VARIABLE is_integral_v = is_integral<T>::value;

template <class T>
MORPH_INLINE_CONSTEXPR_BOOL_VARIABLE is_floating_point_v = is_floating_point<T>::value;

template <class T>
MORPH_INLINE_CONSTEXPR_BOOL_VARIABLE is_array_v = is_array<T>::value;

template <class T>
MORPH_INLINE_CONSTEXPR_BOOL_VARIABLE is_enum_v = is_enum<T>::value;

template <class T>
MORPH_INLINE_CONSTEXPR_BOOL_VARIABLE is_union_v = is_union<T>::value;

template <class T>
MORPH_INLINE_CONSTEXPR_BOOL_VARIABLE is_class_v = is_class<T>::value;

template <class T>
MORPH_INLINE_CONSTEXPR_BOOL_VARIABLE is_function_v = is_function<T>::value;

template <class T>
MORPH_INLINE_CONSTEXPR_BOOL_VARIABLE is_lvalue_reference_v = is_lvalue_reference<T>::value;

template <class T>
MORPH_INLINE_CONSTEXPR_BOOL_VARIABLE is_rvalue_reference_v = is_rvalue_reference<T>::value;

template <class T>
MORPH_INLINE_CONSTEXPR_BOOL_VARIABLE is_member_object_pointer_v = is_member_object_pointer<T>::value;

template <class T>
MORPH_INLINE_CONSTEXPR_BOOL_VARIABLE is_member_function_pointer_v = is_member_function_pointer<T>::value;

template <class T>
MORPH_INLINE_CONSTEXPR_BOOL_VARIABLE is_fundamental_v = is_fundamental<T>::value;

template <class T>
MORPH_INLINE_CONSTEXPR_BOOL_VARIABLE is_arithmetic_v = is_arithmetic<T>::value;

template <class T>
MORPH_INLINE_CONSTEXPR_BOOL_VARIABLE is_scalar_v = is_scalar<T>::value;

template <class T>
MORPH_INLINE_CONSTEXPR_BOOL_VARIABLE is_object_v = is_object<T>::value;

template <class T>
MORPH_INLINE_CONSTEXPR_BOOL_VARIABLE is_compound_v = is_compound<T>::value;

template <class T>
MORPH_INLINE_CONSTEXPR_BOOL_VARIABLE is_reference_v = is_reference<T>::value;

template <class T>
MORPH_INLINE_CONSTEXPR_BOOL_VARIABLE is_member_pointer_v = is_member_pointer<T>::value;


#endif // MORPH_HAS_VARIABLE_TEMPLATES

}   // namespace morph

#endif   // MORPH_HPP