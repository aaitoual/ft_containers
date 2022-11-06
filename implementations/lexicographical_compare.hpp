/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 00:49:53 by aaitoual          #+#    #+#             */
/*   Updated: 2022/11/06 04:46:49 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft {
	template <class iter1, class iter2, class Compare>
	bool lexicographical_compare (iter1 __first1, iter1 __last1, iter2 __first2, iter2 __last2, Compare comp) {
		for (; __first2 != __last2; ++__first1, ++__first2)
   		{
		if (__first1 == __last1 || comp(*__first1, *__first2))
			return true;
		if (comp(*__first2, *__first1))
			return false;
		}
		return false;
	}
	template <class iter1, class iter2>
 	bool lexicographical_compare (iter1 __first1, iter1 __last1, iter2 __first2, iter2 __last2) {
		for (; __first2 != __last2; ++__first1, ++__first2)
   		{
		if (__first1 == __last1 || *__first2 < *__first1)
			return true;
		if (*__first2 < *__first1)
			return false;
		}
		return false;
	}
}
