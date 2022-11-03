/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:55:51 by aaitoual          #+#    #+#             */
/*   Updated: 2022/11/03 06:04:11 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <cstring>
# include <string>
# include <algorithm>
# include <iostream>
# include <memory>
# include <limits>
# include <algorithm>
# include <stdexcept>
# include "exceptions/__exceptions.hpp"
# include "../implementations/enable_if.hpp"
# include "iterators/___vec_iterator.hpp"
# include "iterators/___vec_reverse_iterator.hpp"
# include "../../implementations/reverse_iterator.hpp"

void	_throw_my_exception(int index) {
	switch (index)
	{
	case 1 :
		throw __exceptions::vector_bad_allocation();
	case 2 :
		throw __exceptions::vector_bad_range();
	case 3 :
		throw std::out_of_range("vector");
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
	typedef std::allocator_traits<allocator_type>       __alloc_traits;
	// typedef	typename long int									difference_type;
	
//****************************************iterator*******************************************************************//
		public :
			typedef iterator_vec<T*>						iterator;
			typedef iterator_vec<const T*>					const_iterator;
			typedef ft::reverse_iterator<iterator>			reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
//****************************************private_attribute***************************************************************//
		private :
			T			*arr;
			alloc		alloc_obj;
			size_type	capacity__;
			size_type	size__;
//****************************************private_methods***************************************************************//
		private :
			size_type	max_size_() {
				return size_type(~0) / sizeof(T);
			}
			template <typename S>
			size_t	get_range(S first, S last) {
				size_t ret = 0;
				for (S iter = first; iter != last; iter++)
					ret++;
				return ret;
			}
			iterator	fill_the_new_array(T* arr_tmp, size_t *j, T val, T* __P)
			{
				iterator ret;
				for (size_t i = 0; arr_tmp + i != __P; i++) {
					alloc_obj.construct(arr + i, arr_tmp[i]);
					(*j)++;
				}
				ret = iterator (&arr[*j]);
				alloc_obj.construct(arr + (*j)++, val);;
				size__++;
				for (size_t i = (*j) - 1; i != capacity__; i++) alloc_obj.construct(arr + (*j)++, arr_tmp[i]);
				if (arr_tmp != NULL)
					alloc_obj.deallocate(arr_tmp, capacity__);
				return ret;
			}
			void	fill_the_new_array(T* arr_tmp, size_t *j, T val, T* __P, size_t n)
			{
				for (size_t i = 0; arr_tmp + i != __P; i++) {
					alloc_obj.construct(arr + i, arr_tmp[i]);
					(*j)++;
				}
				for (size_t i = 0; i != n; i++) {
					alloc_obj.construct(arr + (*j)++, val);
					size__++;
				}
				for (size_t i = (*j) - n; i != capacity__; i++) alloc_obj.construct(arr + (*j)++, arr_tmp[i]);;
				if (arr_tmp != NULL)
					alloc_obj.deallocate(arr_tmp, capacity__);
			}
			template <typename input_iter>
			void	fill_the_new_array(input_iter first, input_iter last, T* arr_tmp, size_t *j, T* __P, size_t n)
			{
				for (size_t i = 0; arr_tmp + i != __P; i++) {
					alloc_obj.construct(arr + i, arr_tmp[i]);;
					(*j)++;
				}
				for (input_iter iter = first; iter != last; iter++)
					alloc_obj.constract(arr + (*j)++, *iter);
				for (size_t i = (*j) - n; i != capacity__; i++) alloc_obj.constract(arr + (*j)++, arr_tmp[i]);;
				if (arr_tmp != NULL)
					alloc_obj.deallocate(arr_tmp, capacity__);
			}
			void	destroy_constructors(T*arr, size_t lenght) {
				for (size_t i = 0; i != lenght; i++) {
					alloc_obj.destroy(arr + i);
				}
			}
//****************************************public_methods***************************************************************//
		public :
			vector (const allocator_type &tmp = alloc()) {																//default
				(void) tmp;
				arr = NULL; ///////////////////////////////////////////////////////////
				size__ = 0;
				capacity__ = 0;
			}
			explicit vector (size_type capacity_, const T& value = T(), const allocator_type& tmp = alloc()) {			//fill
				(void)tmp;
				if (capacity_ > max_size_())
					_throw_my_exception(1);
				if (capacity_) {
					arr = alloc_obj.allocate(capacity_);
					for (size_type i = 0; i != capacity_; i++) {
						alloc_obj.construct(arr + i, value);
					}
				}
				else
					alloc_obj.construct(arr);
				capacity__ = capacity_;
				size__ = capacity_;
			}
			template <class IT >
        	vector (IT first, IT last, const allocator_type& tmp = allocator_type(), typename ft::enable_if<!std::is_integral<IT>::value>::type = NULL) {									//range
				(void) tmp;
				alloc_obj.construct(arr);
				capacity__ = 0;
				size__ = 0;
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
				capacity__ = 0;
				*this = copy;
			}
			~vector () {
				if (capacity__)
					alloc_obj.deallocate(arr, capacity__);
			};
			iterator	begin() {
				return iterator (arr);
			}
			const_iterator	begin() const {
				return const_iterator (arr);
			}
			reverse_iterator	rbegin() {
				if (size__)
					return reverse_iterator (arr + size__ - 1);
				return reverse_iterator (NULL);
			}
			const_reverse_iterator	rbegin() const {
				if (size__)
					return const_reverse_iterator (arr + size__ - 1);
				return const_reverse_iterator (arr);
			}
			iterator	end() {
				return	iterator (arr + size__);
			}
			const_iterator	end() const {
				return const_iterator (arr + size__);
			}
			reverse_iterator	rend() {
				if (size__)
					return	reverse_iterator (arr - 1);
				return	reverse_iterator (NULL);
			}
			const_reverse_iterator	rend() const {
				if (size__)
					return	const_reverse_iterator (arr - 1);
				return	const_reverse_iterator (NULL);
			}
			void	push_back(const T& element) {
				if (size__ == capacity__ && capacity__) { // while pushing on an already full array
					T *arr_tmp = arr;
					arr = alloc_obj.allocate(capacity__ * 2);
					for (size_t i = 0; i != capacity__ *2; i++) {
						if (i == size__)
							alloc_obj.construct(arr + i, element);
						else if (i < capacity__)
							alloc_obj.construct(arr + i, arr_tmp[i]);
						else
							alloc_obj.construct(arr + i);
					}
					destroy_constructors(arr_tmp, capacity__);
					alloc_obj.deallocate(arr_tmp, capacity__);
					size__++;
					capacity__ *= 2;
				}
				else if (!capacity__) { // while pushing on a 0 capacity__ array
					arr = alloc_obj.allocate(1);
					capacity__ = 1;
					alloc_obj.construct(arr + size__++, element);
				}
				else
					alloc_obj.construct(arr + size__++, element);
			}
			size_type	max_size() const {
				return (((unsigned long)std::numeric_limits<T>::max() < __alloc_traits::max_size(alloc_obj)) / sizeof(T) ? std::numeric_limits<typename alloc::difference_type>::max() : __alloc_traits::max_size(alloc_obj));
			}
			size_type	size() const {
				return size__;
			}
			void resize (size_type n, T val = T()) {
				if (n > size__) {
					for (size_t i = size__; i != n; i++) push_back(val);
				}
				else if (n && n < size__) {
					for (size_t i = size__ - 1; i != n; i--) {
						alloc_obj.destroy(arr + i);
						size__--;
					}
				}
			}
			bool empty() const {
				return !size__;
			}
			size_type capacity() const {return capacity__;}
			void reserve (size_type n) {
				T* tmp_arr;
				if (!capacity__) {
					capacity__ = n;
					arr = alloc_obj.allocate(capacity__);
				}
				else if (n > capacity__) {
					tmp_arr = arr;
					arr = alloc_obj.allocate(n);
					for (size_t i = 0; i != size__; i++) alloc_obj.construct(arr + i, tmp_arr[i]);
					alloc_obj.deallocate(tmp_arr, capacity__);
					capacity__ = n;
				}
			}
			T& at (size_type index) {
				if (index >= size__)
					_throw_my_exception(3);
				return arr[index];
			}
			const T& at (size_type index) const {
				if (index >= size__)
					_throw_my_exception(3);
				return arr[index];
			}
			T& front() {
				return arr[0];
			}
			const T& front() const {
				return arr[0];
			}
			T& back() {
				if (size__)
					return arr[size__ - 1];
				return NULL;
			}
			const T& back() const {
				if (size__)
					return arr[size__ - 1];
				return NULL;
			}
			alloc get_allocator() const {
				return alloc_obj;
			}
			template <class IT>
  			void assign (IT first, IT last, typename ft::enable_if<!std::is_integral<IT>::value>::type = NULL) {
				if (first > last)
					_throw_my_exception(1); //******************************************************************
				size_type old_size = size__;
				size__ = 0;
				size_t dis = get_range (first, last);
				if (dis) {
					if (dis > capacity__ && capacity__)
					{
						destroy_constructors(arr, old_size);
						alloc_obj.deallocate(arr, capacity__);
						arr = alloc_obj.allocate(dis);
						capacity__ = dis;
					}
					else if (!capacity__)
					{
						arr = alloc_obj.allocate(dis);
						capacity__ = dis;
					}
					for (IT iter = first; iter != last; iter++) {
						alloc_obj.construct(arr + size__++, *iter);
					}
				}
			}
			void assign (size_type n, const T& val) {
				if (n > max_size_())
					_throw_my_exception(1); //*********************************************************************
				size_type old_size = size__;
				size__ = 0;
				if (n) {
					if (n > capacity__ && capacity__)
					{
						destroy_constructors(arr, old_size);
						alloc_obj.deallocate(arr, capacity__);
						arr = alloc_obj.allocate(n);
						capacity__ = n;
					}
					else if (!capacity__)
					{
						arr = alloc_obj.allocate(n);
						capacity__ = n;
					}
					for (size_t iter = 0; iter != n; iter++) {
						alloc_obj.construct(arr + size__++, val);
					}
				}
			}
			void	pop_back() {
				alloc_obj.destroy(arr + size__ - 1);
				size__--;
			}
			iterator insert (iterator position, const T& val) {
				size_t		j = 0;
				iterator	ret = position.base();
				T*			__P = begin().base() + (position.base() - begin().base());
				T*			arr_tmp = arr;
				if (size__ + 1 > capacity__ && capacity__) {
					arr = alloc_obj.allocate(capacity__ * 2);
					ret = fill_the_new_array(arr_tmp, arr, &j, val, __P);
					capacity__ *= 2;
				}
				else if (size__ + 1 > capacity__) {
					arr = alloc_obj.allocate(1);
					ret = fill_the_new_array(arr_tmp, &j, val, __P);
					capacity__ = 1;
				}
				else if (position.base() >= arr){
					size_t i = size__;
					for (i = capacity__ - 1; arr + i != position.base(); i--) {
						arr [i] = arr [i - 1];
					}
					alloc_obj.construct(arr + i, val);
					ret = iterator (&arr[i]);
					size__++;
				}
				return ret;
			}
			void insert (iterator position, size_type n, const T& val){
				size_t		j = 0;
				T*			__P = begin().base() + (position.base() - begin().base());
				T*			arr_tmp = arr;
				size_t		new_capacity = capacity__;
				if (size__ + n > capacity__ && capacity__) {
					if (size__ + n <= capacity__ * 2) {
						arr = alloc_obj.allocate(capacity__ * 2);
						new_capacity *= 2;
					}
					else {
						arr = alloc_obj.allocate(size__ + n);
						new_capacity *= size__ + n;
					}
					fill_the_new_array(arr_tmp, &j, val, __P, n);
					capacity__ = new_capacity;
				}
				else if (size__ + n > capacity__) {
					arr = alloc_obj.allocate(size__ + n);
					fill_the_new_array(arr_tmp, &j, val, __P, n);
					capacity__ = size__ + n;
				}
				else if (position.base() >= arr) {
					size_t i = size__;
					for (i = i; arr + i != __P; i--) {
						arr[i] = arr[i - n];
					}
					for (size_t u = 0; u != n; u++) {
						alloc_obj.construct(arr + i++, val);
						size__++;
					}
				}
			}
			template <class InputIterator>
    		void	insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!std::is_integral<InputIterator>::value>::type = NULL) {
				long 		dis = last - first;
				T*			__P = begin().base() + (position.base() - begin().base());
				size_t 		j = 0;
				size_t		new_capacity;
				T*			arr_tmp = arr;
				if (dis > 0) {
					size_t n = dis;
					if (size__ + n > capacity__ && capacity__) {
						if (size__ + n <= capacity__ * 2) {
							arr = alloc_obj.allocate(capacity__ * 2);
							new_capacity = capacity__ * 2;
						}
						else {
							arr = alloc_obj.allocate(size__ + n);
							new_capacity = size__ + n;
						}
						fill_the_new_array(first, last, arr_tmp, &j, __P, n);
						capacity__ = new_capacity;
					}
					else if (size__ + n > capacity__) {
						arr = alloc_obj.allocate(size__ + n);
						fill_the_new_array(first, last, arr_tmp, &j, __P, n);
						capacity__ = size__ + n;
					}
					else if (position.base() >= arr) {
						size_t i = size__;
						for (i = i; arr + i != __P; i--) arr[i] = arr[i - n];
						for (InputIterator iter = first; iter != last; iter++) {
							alloc_obj.construct(arr + i++, *iter);
							size__++;
						}
					}
				}
			}
			void swap (vector& x) {
				T*			arr_tmp = arr;
				size_type	capacity_tmp = capacity__;
				size_type	size_tmp = size__;
				alloc		alloc_obj_tmp = alloc_obj;
				
				arr = x.arr;
				capacity__ = x.capacity__;
				size__ = x.size__;
				alloc_obj = x.alloc_obj;
				x.arr = arr_tmp;
				x.capacity__ = capacity_tmp;
				x.size__ = size_tmp;
				x.alloc_obj = alloc_obj_tmp;
			}
			iterator	erase (iterator position) {
				T* __P = begin().base() + (position.base() - begin().base());
				size_t	index = 0;
				bool	after = 0;
				for (index = 0; arr + index < __P; index++) {}
				if (index + 1 <= size__) {
					alloc_obj.destroy(arr + index);
					while (index + 1 < size__) {
						arr[index] = arr[index + 1];
						index++;
					}
					size__--;
				}
				return iterator (__P);
			}
			iterator	erase (iterator first, iterator last) {
				T* 		__P = begin().base() + (first.base() - begin().base());
				size_t	dis = last - first;
				size_t	index = 0;
				bool	after = 0;
				for (index = 0; arr + index != first.base(); index++);
				for (index = index; arr + index != last; index++) {
					alloc_obj.destroy(arr + index);
					size__--;
				}
				for (index = index; index < capacity__; index++) {
					arr[index - dis] = arr[index];
				}
				return iterator (__P);
			}
			void	clear (void) {
				for (size_t i = 0; i != size__; i++)
					alloc_obj.destroy(arr + i);
				size__ = 0;
			}

//****************************************public_operator***************************************************************//
		public :
			T&	operator [] (size_t index) {
				return arr[index];
			}
			const T& operator[] (size_type index) const {
				return arr[index];
			}
			vector& operator = (const vector& copy) {
				if (copy.capacity__ && !capacity__)
					arr = alloc_obj.allocate(copy.capacity__);
				else if (copy.capacity__ && capacity__) {
					alloc_obj.deallocate(arr, capacity__);
					arr = alloc_obj.allocate(copy.capacity__);
				}
				else if (!copy.capacity__) {
					if (capacity__)
						alloc_obj.deallocate(arr, capacity__);
					arr = NULL;
				}
				capacity__ = copy.capacity__;
				size__ = copy.size__;
				return *this;
			}
	};
}

template <typename R, typename alloc>
bool	operator== (const ft::vector<R, alloc>& lhs, const ft::vector<R,alloc>& rhs) {
	if (lhs.size() == rhs.size())
		return std::equal(lhs.begin(), lhs.end(), rhs.begin());
	return false;
}

template <typename R, typename alloc>
bool	operator!= (const ft::vector<R, alloc>& lhs, const ft::vector<R,alloc>& rhs) {return !(lhs == rhs);}

template <typename R, typename alloc>
bool	operator< (const ft::vector<R, alloc>& lhs, const ft::vector<R,alloc>& rhs) {
	return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <typename R, typename alloc>
bool	operator> (const ft::vector<R, alloc>& lhs, const ft::vector<R,alloc>& rhs) {
	return (rhs < lhs);
}

template <typename R, typename alloc>
bool	operator<= (const ft::vector<R, alloc>& lhs, const ft::vector<R,alloc>& rhs) {
	return !(rhs < lhs);
}

template <typename R, typename alloc>
bool	operator>= (const ft::vector<R, alloc>& lhs, const ft::vector<R,alloc>& rhs) {
	return !(lhs < rhs);
}