/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 05:27:54 by aaitoual          #+#    #+#             */
/*   Updated: 2022/11/06 23:53:21 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

namespace ft {
	template <class T1, class T2> struct pair {
		//member_types
		typedef T1 first_type;
		typedef T2 second_type;
		
		//member_variables
		T1 first;
		T2 second;
		
		//member_functions
		pair() : first(), second() {}
		template<class U, class V> pair (const pair<U,V>& pr) : first(pr.first), second(pr.second) {};
		pair (const first_type& a, const second_type& b) : first(a), second(b) {};

		//operators
		pair& operator=(pair const& __p) {first = __p.first;second = __p.second; return *this;}
	};
	
	//relational operators
	template <class _T1, class _T2> bool operator==(const pair<_T1,_T2>& __x, const pair<_T1,_T2>& __y) {
		return __x.first == __y.first && __x.second == __y.second;
	}
	
	template <class _T1, class _T2> bool operator!=(const pair<_T1,_T2>& __x, const pair<_T1,_T2>& __y) {
		return !(__x == __y);
	}
	
	template <class _T1, class _T2> bool operator< (const pair<_T1,_T2>& __x, const pair<_T1,_T2>& __y) {
		return __x.first < __y.first || (!(__y.first < __x.first) && __x.second < __y.second);
	}
	
	template <class _T1, class _T2> bool operator> (const pair<_T1,_T2>& __x, const pair<_T1,_T2>& __y) {
		return __y < __x;
	}
	
	template <class _T1, class _T2> bool operator>=(const pair<_T1,_T2>& __x, const pair<_T1,_T2>& __y) {
		return !(__x < __y);
	}
	
	template <class _T1, class _T2> bool operator<=(const pair<_T1,_T2>& __x, const pair<_T1,_T2>& __y) {
		return !(__y < __x);
	}
}
