/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:55:51 by aaitoual          #+#    #+#             */
/*   Updated: 2022/10/22 06:24:29 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <cstring>
# include <string>
# include <algorithm>
# include <iostream>
# include <memory>
# include "exceptions/__exceptions.hpp"

void	_throw_my_exception(int index) {
	switch (index)
	{
	case 1 :
		throw __exceptions::vector_bad_allocation();
	case 2 :
		throw __exceptions::vector_bad_range();
	default:
		break;
	}
}

namespace ft
{
	template <typename T, typename alloc = std::allocator<T> >
	class   vector {
		
	public:
    typedef alloc		                            	allocator_type;
	typedef	typename allocator_type::reference			reference;
	typedef	typename allocator_type::const_reference	const_reference;
	typedef	typename allocator_type::pointer			pointer;
	typedef	typename allocator_type::const_pointer		const_pointer;
	typedef typename alloc::size_type					size_type;
	
//****************************************iterator*******************************************************************//
		class iterator : public std::iterator < std::random_access_iterator_tag, T, const T*, T> {
			private :
				T*	current;
			public :
				iterator () {current = NULL;}
				iterator (T * it) {current = it;}
				T&	operator * () {return *current;}
				iterator	operator ++ (int) {iterator	tmp(current);current++;return tmp;}
				iterator&	operator ++ () {current++;return current;}
				iterator	operator -- (int) {iterator	tmp(current);current--;return tmp;}
				iterator&	operator -- () {current--;return current;}
				iterator&	operator = (iterator copy) {current = copy.current; return *this;};
				bool		operator != (iterator& iter) {return (*current != *iter) ?  1 : 0;}
				bool		operator == (iterator& iter) {return (*current != *iter) ?  0 : 1;}
				bool		operator > (iterator& iter) {return (*current > *iter) ?  0 : 1;}
				bool		operator >= (iterator& iter) {return (*current >= *iter) ?  0 : 1;}
				bool		operator < (iterator& iter) {return (*current < *iter) ?  0 : 1;}
				bool		operator <= (iterator& iter) {return (*current <= *iter) ?  0 : 1;}
		};
//****************************************private_attribute***************************************************************//
		private :
			T			*arr;
			alloc		alloc_obj;
			size_type	capacity;
			size_type	size;
//****************************************private_methods***************************************************************//
		private :
			size_type	max_size() {
				return size_type(~0) / sizeof(T);
			}
//****************************************public_methods***************************************************************//
		public :
			vector (const allocator_type &tmp = alloc()) {																//default
				(void) tmp;
				arr = NULL;
				size = 0;
				capacity = 0;
			}
			explicit vector (size_type capacity_, const T &value = T(), const allocator_type& tmp = alloc()) {			//fill
				(void)tmp;
				if (capacity_ > max_size())
					_throw_my_exception(1);
				if (capacity_) {
					arr = alloc_obj.allocate(capacity_);
					for (size_type i = 0; i != capacity_; i++) {
						arr[i] = value;
					}
				}
				else
					arr = NULL;
				capacity = capacity_;
				size = capacity_;
			}
			template <typename IT>
        	vector (IT first, IT last, const allocator_type& tmp = allocator_type()) {									//range
				(void) tmp;
				arr = NULL;
				if (first > last)
					_throw_my_exception(2);
				if (first == last)
					return ;
				for (IT iter = first; iter != last; iter++) {
					push_back(*iter);
					first++;
				}	
			}
			vector (const vector& copy) {																				//copy
				capacity = 0;
				*this = copy;
			}
			~vector () {
				alloc_obj.deallocate(arr, capacity);
			};
			iterator	begin() {
				return iterator (arr);
			}
			iterator	end() {
				return	iterator (arr + size);
			}
			void	push_back(T element) {
				if (size == capacity && capacity) { // while pushing on an already full array
					T *arr_tmp;
					arr_tmp = alloc_obj.allocate(capacity * 2);
					std::copy(arr, arr + capacity, arr_tmp);
					alloc_obj.deallocate(arr, capacity);
					arr = arr_tmp;
					capacity *= 2;
				}
				else if (!capacity) { // while pushing on a 0 capacity array
					arr = alloc_obj.allocate(1);
					capacity = 1;
				}
				arr[size++] = element;
			}
//****************************************public_operator***************************************************************//
		public :
			int&	operator [] (int index) {
				return arr[index];
			}
			vector& operator = (const vector& copy) {
				if (copy.capacity && !capacity)
					arr = alloc_obj.allocate(capacity.capacity);
				else if (copy.capacity && capacity) {
					alloc_obj.deallocate(arr, capacity);
					arr = alloc_obj.allocate(copy.capacity);
				}
				else if (!copy.capacity) {
					if (capacity)
						alloc_obj.deallocate(arr, capacity);
					arr = NULL;
				}
				capacity = copy.capacity;
				size = copy.size;
			}
			
	};
}