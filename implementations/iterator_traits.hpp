/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 21:30:18 by aaitoual          #+#    #+#             */
/*   Updated: 2022/11/03 05:09:10 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace  ft {
	template <typename _Iter>
	struct iterator_traits {
		typedef typename _Iter::difference_type   difference_type;
		typedef typename _Iter::value_type        value_type;
		typedef typename _Iter::pointer           pointer;
		typedef typename _Iter::reference         reference;
		typedef typename _Iter::iterator_category iterator_category;
	};
	
	template <typename T>
	struct iterator_traits <T*>{
		typedef long int				difference_type;
		typedef T						value_type;
		typedef T*						pointer;
		typedef T&						reference;
		typedef	std::random_access_iterator_tag iterator_category;
	};
	
	template <typename T>
	struct iterator_traits<const T*> {
		typedef long int						difference_type;
		typedef const T							value_type;
		typedef const T*						pointer;
		typedef const T&						reference;
		typedef	std::random_access_iterator_tag iterator_category;
	};
}
