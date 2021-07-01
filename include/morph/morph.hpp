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

/// @brief Alias template for const-volatility specifiers
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

/// @brief Primary type categories
template <class T, class U>
struct is_same : false_type{};

template <class T>
struct is_same<T,T> : true_type{};

template <class T>
struct is_void : is_same<void, typename remove_cv<T>::type> {};

template <class T>
struct is_null_pointer : is_same<nullptr_t, typename remove_cv<T>::type> {};

namespace detail {

template <class T>
struct is_integral_base : false_type {};

template <> struct is_integral_base<bool> : true_type {};
template <> struct is_integral_base<char> : true_type {};
template <> struct is_integral_base<short> : true_type {};
template <> struct is_integral_base<int> : true_type {};
template <> struct is_integral_base<long> : true_type {};
template <> struct is_integral_base<long long> : true_type {};

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

}   // namespace detail

template <class T>
struct is_floating_point : detail::is_floating_point_base<typename remove_cv<T>::type> {};

template <class T>
struct is_array : detail::is_array_base<typename remove_cv<T>::type> {};

template <class T>
struct is_function : detail::is_function_base<T> {};

template <class T>
struct is_pointer : detail::is_pointer_base<typename remove_cv<T>::type> {};

//template <class T>
//struct is_enum : false_type {};

// This seems difficult to implement
//template <class T>
//struct is_enum<enum> : true_type{};

//template <class T>
//struct is_union : false_type {};

// This seems difficult to implement
//template <class T>
//struct is_union<union> : true_type {};

// This seems difficult to implement
//template <class T>
//struct is_class : false_type {};

//template <class T>
//struct is_class<class> : true_type {};

template <class T>
struct is_lvalue_reference : detail::is_lvalue_reference_base<typename remove_cv<T>::type> {};

template <class T>
struct is_rvalue_reference : detail::is_rvalue_reference_base<typename remove_cv<T>::type> {};

template <class T>
struct is_member_function_pointer : detail::is_member_function_pointer_base<typename remove_cv<T>::type> {};

template <class T>
struct is_member_pointer : detail::is_member_pointer_base<typename remove_cv<T>::type> {};

template <class T>
struct is_member_object_pointer : detail::is_member_object_pointer_base<T> {};

}   // namespace morph

#endif   // MORPH_HPP