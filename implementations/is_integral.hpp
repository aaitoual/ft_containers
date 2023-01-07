/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 20:02:03 by aaitoual          #+#    #+#             */
/*   Updated: 2022/11/06 00:20:43 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

namespace ft
{
	template <typename T, T __V>
	struct const_value
	{
		static const T value = __V;
		typedef T      value_type;
	};
	#define true_const const_value<bool, true>
	#define false_const const_value<bool, false>
	template <typename T> struct is_integral_utils : public false_const {};
	template <> struct is_integral_utils<bool> : public true_const {};
	template <> struct is_integral_utils<char> : public true_const {};
	template <> struct is_integral_utils<signed char> : public true_const {}; // check signed char | answer (signed char can hold 8 bits and the first bite will be for the signe so it will stor from -128 to 127 but the char and the unsigned char will store from 0 to 255)
	template <> struct is_integral_utils<unsigned char> : public true_const {};
	template <> struct is_integral_utils<wchar_t> : public true_const {}; // check wchar_t | answer (wchar_t hold 16 bite "sometimes 32" and it can stor wide character, like unicodes)
	template <> struct is_integral_utils<char16_t> : public true_const {};  // check char16_t
	template <> struct is_integral_utils<char32_t> : public true_const {}; // check char16_t
	template <> struct is_integral_utils<short> : public true_const {};
	template <> struct is_integral_utils<unsigned short> : public true_const {};
	template <> struct is_integral_utils<int> : public true_const {};
	template <> struct is_integral_utils<unsigned int> : public true_const {};
	template <> struct is_integral_utils<long> : public true_const {};
	template <> struct is_integral_utils<unsigned long> : public true_const {};
	template <> struct is_integral_utils<long long> : public true_const {};
	template <> struct is_integral_utils<unsigned long long> : public true_const {};
	template <> struct is_integral_utils<__int128_t> : public true_const {}; // check __int128_t
	template <> struct is_integral_utils<__uint128_t> : public true_const {}; // check __uint128_t
	template <typename T>
	struct	is_integral : public is_integral_utils<typename std::remove_cv<T>::type> {}; ////////////check std::remove_cv<T>
}