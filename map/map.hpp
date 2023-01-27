/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 08:05:53 by aaitoual          #+#    #+#             */
/*   Updated: 2023/01/11 05:40:20 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "RBT/red_black_three.hpp"
# include "iterators/__map_iterator.hpp"
# include "../implementations/reverse_iterator.hpp"

namespace ft {
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,T> > > class map {	
		public :
			typedef	typename std::pair<const Key, T>			value_type;
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
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef	ft::reverse_iterator<const_iterator>		const_reverse_iterator;
			typedef ft::iterator_traits<Key>					difference_type;
			typedef	size_t										size_type;

		////////////////////////////////////////////////
		////////////////////////////////////////////////
		////////////////////////////////////////////////
		private :
			size_type				__size;
			allocator_type			__alloc;
			key_compare				__comp;
			ft::RBT<value_type>		__tree;

		///////////////////////////////////////////////
		///////////////////////////////////////////////
		///////////////////////////////////////////////
		public :
			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {
				__size = 0;
				__alloc = alloc;
				__comp = comp;
				// std::pair <const int, std::string> tmp1 = std::make_pair(10, "test10");
				// std::pair <const int, std::string> tmp2= std::make_pair(11, "test11");
				// std::pair <const int, std::string> tmp3 = std::make_pair(12, "test12");
				// std::pair <const int, std::string> tmp4 = std::make_pair(13, "test13");
				// ft::NODE<value_type> node1(tmp1);
				// ft::NODE<value_type> node2(tmp2);
				// ft::NODE<value_type> node3(tmp3);
				// ft::NODE<value_type> node4(tmp4);
				// __tree.RBT_insert(&node1);
				// __tree.RBT_insert(&node2);
				// __tree.RBT_insert(&node3);
				// __tree.RBT_insert(&node4);
				// std::cout << "content : " << find_node(13).second << std::endl;
			}

			template <class Iter>
			map (Iter first, Iter last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type(), typename enable_if<!std::is_integral<Iter>::value>::type = NULL) {
				__size = 0;
				__alloc = alloc;
				__comp = comp;
				if (first > last) {
					//throw 
					std::cout << "throw \n";
					exit (0);
				}
				if (first == last) {
					return;
				}
				for (Iter it = first; it != last; it++)
					__tree.RBT_insert(*it);
			}
			////////////////////////////////////////////////
			////////////////////////////////////////////////
			////////////////////////////////////////////////
			mapped_type& operator[] (const key_type& k) {}
			///////////////////////////////////////////////
			///////////////////////////////////////////////
			///////////////////////////////////////////////
			ft::NODE<value_type>* find_node(const key_type& key) {
				ft::NODE<value_type>	*node = __tree.__root;

				while (node != __tree.__nullnode)
				{
					if (key == node->content.first)
						break ;
					if (__comp(key, node->content.first)) {
						if (node->left == __tree.__nullnode)
							break ;
						node = node->left;
					}
					else {
						if (node->right == __tree.__nullnode)
							break ;
						node = node->right;
					}
				}
				return node;
			}
			///////////////////////////////////////////////
			///////////////////////////////////////////////
			///////////////////////////////////////////////
			std::pair<iterator, bool> insert (const value_type& val) {
				ft::NODE<value_type>		*tmp = find_node(val.first);

				if (tmp != __tree.__nullnode && tmp->content.first == val.first) {
					// return std::pair<iterator, bool> (const iterator (val), false);
					return {iterator (val), false};
				}
				else {
					__tree.RBT_insert(val);
					__size++;
					tmp = find_node(val.first);
					// std::pair<iterator, bool> tmp2(iterator (tmp->content), true);
					// return tmp2;
					return {iterator (tmp->content), true};
				}
				// return ret;
			}
	};
}