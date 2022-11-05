/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 02:30:10 by aaitoual          #+#    #+#             */
/*   Updated: 2022/11/03 19:27:29 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "iterator_traits.hpp"

namespace ft {
	template<typename S>
	class reverse_iterator : public std::iterator < std::random_access_iterator_tag,
													typename S::value_type,
													typename S::pointer,
													typename S::reference>{
		public :
			typedef typename ft::iterator_traits<S>::reference			reference;
			typedef	typename ft::iterator_traits<S>::value_type			value_type;
			typedef	typename ft::iterator_traits<S>::pointer			pointer;
			typedef	typename ft::iterator_traits<S>::difference_type	difference_type;
			typedef	typename ft::iterator_traits<S>::iterator_category	iterator_category;
		private :
			S	current;
		public :
			reverse_iterator () : current() {}
			explicit reverse_iterator (S it) : current (it) {}
			template <typename T>
			reverse_iterator (const reverse_iterator<T>& it) : current(it.base()) {};
			reference					operator * () const {S tmp = current; return *--tmp;}
			S*							operator -> () const {return &current;}
			reverse_iterator			operator ++ (int) {reverse_iterator	tmp(current);current--;return tmp;}
			reverse_iterator&			operator ++ () {current--;return *this;}
			reverse_iterator			operator -- (int) {reverse_iterator	tmp(current);current++;return tmp;}
			reverse_iterator&			operator -- () {current++;return *this;}
			reverse_iterator			operator + (int i) {return reverse_iterator (current - i);}
			reverse_iterator			operator - (int i) {return reverse_iterator (current + i);}
			reference					operator [] (int i) {return *(*this + i);}
			reverse_iterator&			operator -= (int i) {current += i; return *this;}
			reverse_iterator&			operator += (int i) {current -= i; return *this;}
			template <typename T>
			reverse_iterator&			operator = (reverse_iterator<T>& copy) {current = copy.current; return *this;};
			bool						operator != (reverse_iterator& iter) {return (this->current != iter.current) ?  1 : 0;}
			bool						operator == (reverse_iterator& iter) {return (this->current != iter) ?  0 : 1;}
			bool						operator < (reverse_iterator& iter) {return (this->current > iter.current) ?  1 : 0;}
			bool						operator <= (reverse_iterator& iter) {return (this->current >= iter.current) ?  1 : 0;}
			bool						operator > (reverse_iterator& iter) {return (this->current < iter.current) ?  1 : 0;}
			bool						operator >= (reverse_iterator& iter) {return (this->current <= iter.current) ?  1 : 0;}
			friend	bool				operator != (const reverse_iterator& that, const reverse_iterator& iter) {return (that.current != iter.current) ?  1 : 0;}
			friend	bool				operator == (const reverse_iterator& that, const reverse_iterator& iter) {return (that.current != iter) ?  0 : 1;}
			friend	bool				operator < (const reverse_iterator& that, const reverse_iterator& iter) {return (that.current > iter.current) ?  1 : 0;}
			friend	bool				operator <= (const reverse_iterator& that, const reverse_iterator& iter) {return (that.current >= iter.current) ?  1 : 0;}
			friend	bool				operator > (const reverse_iterator& that, const reverse_iterator& iter) {return (that.current < iter.current) ?  1 : 0;}
			friend	bool				operator >= (const reverse_iterator& that, const reverse_iterator& iter) {return (that.current <= iter.current) ?  1 : 0;}
			friend	reverse_iterator	operator - (int i, reverse_iterator it) {return reverse_iterator<S> (it.base() + i);}
			friend	reverse_iterator	operator + (int i, reverse_iterator it) {return reverse_iterator<S> (it.base() - i);}
			S							base() const {return current;}
	};
	template <class _Iter1, class _Iter2>
	typename reverse_iterator<_Iter1>::difference_type
	operator-(const reverse_iterator<_Iter1>& __x, const reverse_iterator<_Iter2>& __y)
	{
	    return __y.base() - __x.base();
	}
}