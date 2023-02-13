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

#include "RBT/red_black_three.hpp"
#include "iterators/__map_iterator.hpp"
#include "../implementations/reverse_iterator.hpp"
#include "../implementations/enable_if.hpp"
#include "../implementations/is_integral.hpp"

# include "../implementations/iterator_traits.hpp"
# include "../implementations/lexicographical_compare.hpp"

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T> > >
	class map
	{
	private:
		// typedef _Rb_tree<key_type, value_type, _Select1st<value_type>, key_compare, _Pair_alloc_type> RBT_type;
		typedef ft::RBT<std::pair<const Key, T> > RBT_type;

	public:
		typedef typename std::pair<const Key, T> value_type;
		typedef T mapped_type;
		typedef Key key_type;
		typedef Compare key_compare;
		// typedef											value_compare;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef typename RBT_type::iterator iterator;
		typedef typename RBT_type::const_iterator const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef ft::iterator_traits<Key> difference_type;
		typedef size_t size_type;
		typedef std::allocator_traits<allocator_type>       __alloc_traits;

		////////////////////////////////////////////////
		////////////////////////////////////////////////
		////////////////////////////////////////////////
	private:
		size_type __size;
		allocator_type __alloc;
		key_compare __comp;
		RBT_type __tree;

		///////////////////////////////////////////////
		///////////////////////////////////////////////
		///////////////////////////////////////////////
				///////////////////////////////////////////////
		///////////////////////////////////////////////
		///////////////////////////////////////////////
	private :
		ft::NODE<value_type> *find_node(const key_type &key)
		{
			ft::NODE<value_type> *node = __tree.__root;

			while (node != __tree.__nullnode && !node->leaf)
			{
				if (key == node->content.first)
					break;
				if (__comp(key, node->content.first))
				{
					node = node->left;
				}
				else
				{
					node = node->right;
				}
			}
			return node;
		}
	public:
		explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
		{
			__size = 0;
			__alloc = alloc;
			__comp = comp;
		}

		template <class Iter>
		map(Iter first, Iter last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<Iter>::value>::type = NULL)
		{
			__size = 0;
			__alloc = alloc;
			__comp = comp;
			insert(first, last);
		}

		map (const map& x) {
			*this = x;
		}
		////////////////////////////////////////////////
		////////////////////////////////////////////////
		////////////////////////////////////////////////
		map&	operator = (const map& x) {
			__size = x.__size;
			__alloc = x.__alloc;
			__comp = x.__comp;
			size_t i = 0;
			for (iterator it(x.__tree.get_first()); i != x.__size; i++) {
				insert(*it);
				it++;
			}
			return *this;
		}

		mapped_type &operator[](const key_type &key) {
			ft::NODE<value_type> *tmp = find_node(key);
			
			if (tmp != __tree.__nullnode && tmp->content.first == key)
				return tmp->content.second;
			else {
				insert(value_type (key, mapped_type()));
				tmp = find_node(key);
			}
			return tmp->content.second;
		}
		///////////////////////////////////////////////
		///////////////////////////////////////////////
		///////////////////////////////////////////////
		std::pair<iterator, bool> insert(const value_type &val) {
			ft::NODE<value_type> *tmp = find_node(val.first);

			if (tmp != __tree.__nullnode && tmp->content.first == val.first)
			{
				// return std::pair<iterator, bool> (const iterator (val), false);
				return {iterator(tmp), false};
			}
			else
			{
				__tree.RBT_insert(val);
				__size++;
				tmp = find_node(val.first);
				return {iterator(tmp), true};
			}
		}

		// iterator insert (iterator position, const value_type& val) {
		// 	ft::NODE<value_type> *tmp = find_node(val.first);

		// 	// if (*position.)
		// }

		template <class IT>
  		void insert (IT first, IT last) {
			if (first > last) {
				std::cout << "EXCEPTION\n"; //return an exception;
				exit (0);
			}
			if (first == last)
				return ;
			for (IT it = first; it != last; it++)
				insert (*it);
		}
		//////////////////////////////////////////
		/////////////////////////////////////////
		//////////////////////////////////////////
		iterator	begin() {
			return iterator(__tree.get_first());
		}

		const_iterator	begin() const {
			return const_iterator(__tree.get_first());
		}

		iterator	end() {
			return iterator(__tree.get_last());
		}

		const_iterator	end() const {
			return const_iterator(__tree.get_last());
		}

		reverse_iterator	rbegin() {
			return reverse_iterator(__tree.get_last());
		}

		const_reverse_iterator	rbegin() const {
			return const_reverse_iterator(__tree.get_last());
		}

		reverse_iterator	rend() {
			return reverse_iterator(__tree.get_first());
		}

		const_reverse_iterator	rend() const {
			return const_reverse_iterator(__tree.get_first());
		}
		////////////////////////////////////////
		///////////////////////////////////////
		///////////////////////////////////////
		bool	empty() const {
			if (!__size)
				return true;
			return false;
		}
		size_type	size() const {
			return __size;
		}
		// size_type	max_size() const {
		// 	return (((unsigned long)std::numeric_limits<T>::max() < __alloc_traits::max_size(__alloc)) / sizeof(T) ? std::numeric_limits<typename alloc::difference_type>::max() : __alloc_traits::max_size(__alloc));
		// }
		/////////////////////////////////////
		/////////////////////////////////////
		/////////////////////////////////////
		void erase (iterator position) {
			__tree.RBT_delete(position.base());
		}
		size_type	erase (const key_type& k) {
			ft::NODE<value_type>	*tmp = find_node(k);

			if (tmp != __tree.__nullnode) {
				__tree.RBT_delete(tmp);
				return 1;
			}
			return 0;
		}
		void erase (iterator first, iterator last) {
			if (first > last) {
				std::cout << "EXCEPTION\n"; //return an exception;
				exit (0);
			}
			if (first == last)
				return ;
			for (iterator it = first; it != last; it++)
				erase(it);
		}
		//////////////////////////////////////////////////////
		///////////////////////////////////////////////////////////
		////////////////////////////////////////////////////
		iterator	find (const key_type& k){
			ft::NODE<value_type>	*tmp = find_node(k);
			if (!__size)
				tmp = __tree.__ROOT_P;
			else if (tmp == __tree.__nullnode)
				tmp = __tree.get_last()->parent;
			return iterator(tmp);
		}
		// const_iterator find (const key_type& k) const {
		// 	ft::NODE<value_type>	*tmp = find_node(k);
		// 	if (!__size)
		// 		tmp = __tree.__ROOT_P;
		// 	else if (tmp == __tree.__nullnode)
		// 		tmp = __tree.get_last()->parent;
		// 	return const_iterator(tmp);
		// }
	};
}