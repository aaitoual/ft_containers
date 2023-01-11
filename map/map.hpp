/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 08:05:53 by aaitoual          #+#    #+#             */
/*   Updated: 2023/01/11 01:04:27 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "RBT/red_black_three.hpp"
# include "iterators/__map_iterator.hpp"
# include "../implementations/reverse_iterator.hpp"

namespace ft {
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key,T> > > class map {	
		public :
			typedef	pair<const Key, T>							value_type;
			typedef	T											mapped_type;
			typedef	Key											key_type;
			typedef	Compare										key_compare;
			// typedef											value_compare;
			typedef	Alloc										allocator_type;
			typedef	typename allocator_type::reference			reference;
			typedef	typename allocator_type::const_reference	const_reference;
			typedef	typename allocator_type::pointer			pointer;
			typedef	typename allocator_type::const_pointer		const_pointer;
			typedef	iterator_map<value_type>					iterator;
			typedef	iterator_map<const value_type>				const_iterator;
			typedef	ft::reverse_iterator<iterator>				reverse_iterator;
			typedef	ft::reverse_iterator<const_iterator>		const_reverse_iterator;
			typedef ft::iterator_traits<value_type>				difference_type;
			typedef	size_t										size_type;

		////////////////////////////////////////////////
		////////////////////////////////////////////////
		////////////////////////////////////////////////
		private :
			size_type		__size;
			allocator_type	__alloc;
			key_compare		__comp;
			ft::RBT			__tree;

		///////////////////////////////////////////////
		///////////////////////////////////////////////
		///////////////////////////////////////////////
		public :
			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {
				__size = 0;
				__alloc = alloc;
				__comp = comp;
			}
			////////////////////////////////////////////////
			////////////////////////////////////////////////
			////////////////////////////////////////////////
			mapped_type& operator[] (const key_type& k) {}
			///////////////////////////////////////////////
			///////////////////////////////////////////////
			///////////////////////////////////////////////
			value_type* 
	};
}