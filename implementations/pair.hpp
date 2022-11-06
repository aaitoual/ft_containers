/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 05:27:54 by aaitoual          #+#    #+#             */
/*   Updated: 2022/11/06 06:34:35 by aaitoual         ###   ########.fr       */
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
		pair();
		template<class U, class V> pair (const pair<U,V>& pr);
		pair (const first_type& a, const second_type& b);
	};
}