/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ___vec_reverse_iterator.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 21:02:30 by aaitoual          #+#    #+#             */
/*   Updated: 2022/11/03 05:24:44 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <iterator>
# include "../../implementations/iterator_traits.hpp"

template<typename S>
class reverse_iterator_vec{
	public :
		typedef typename ft::iterator_traits<S>::reference reference;
	private :
		S	current;
	public :
		reverse_iterator_vec () : current() {}
		explicit reverse_iterator_vec (S it) : current (it) {}
		template <typename T>
		reverse_iterator_vec (const reverse_iterator_vec<T>& it) : current(it.base()) {};
		reference	operator * () const {S tmp = current; return *--tmp;}
		S*								operator -> () const {return &current;}
		reverse_iterator_vec			operator ++ (int) {reverse_iterator_vec	tmp(current);current--;return tmp;}
		reverse_iterator_vec&			operator ++ () {current--;return *this;}
		reverse_iterator_vec			operator -- (int) {reverse_iterator_vec	tmp(current);current++;return tmp;}
		reverse_iterator_vec&			operator -- () {current++;return *this;}
		reverse_iterator_vec			operator + (int i) {return current - i;}
		reverse_iterator_vec			operator - (int i) {return current + i;}
		S&								operator [] (int i) {return reverse_iterator_vec(current - i);}
		reverse_iterator_vec&			operator -= (int i) {current += i; return *this;}
		reverse_iterator_vec&			operator += (int i) {current -= i; return *this;}
		template <typename T>
		reverse_iterator_vec&			operator = (reverse_iterator_vec<T>& copy) {current = copy.current; return *this;};
		bool							operator != (reverse_iterator_vec& iter) {return (this->current != iter.current) ?  1 : 0;}
		bool							operator == (reverse_iterator_vec& iter) {return (this->current != iter) ?  0 : 1;}
		bool							operator < (reverse_iterator_vec& iter) {return (this->current > iter.current) ?  1 : 0;}
		bool							operator <= (reverse_iterator_vec& iter) {return (this->current >= iter.current) ?  1 : 0;}
		bool							operator > (reverse_iterator_vec& iter) {return (this->current < iter.current) ?  1 : 0;}
		bool							operator >= (reverse_iterator_vec& iter) {return (this->current <= iter.current) ?  1 : 0;}
		friend	bool					operator != (const reverse_iterator_vec& that, const reverse_iterator_vec& iter) {return (that.current != iter.current) ?  1 : 0;}
		friend	bool					operator == (const reverse_iterator_vec& that, const reverse_iterator_vec& iter) {return (that.current != iter) ?  0 : 1;}
		friend	bool					operator < (const reverse_iterator_vec& that, const reverse_iterator_vec& iter) {return (that.current > iter.current) ?  1 : 0;}
		friend	bool					operator <= (const reverse_iterator_vec& that, const reverse_iterator_vec& iter) {return (that.current >= iter.current) ?  1 : 0;}
		friend	bool					operator > (const reverse_iterator_vec& that, const reverse_iterator_vec& iter) {return (that.current < iter.current) ?  1 : 0;}
		friend	bool					operator >= (const reverse_iterator_vec& that, const reverse_iterator_vec& iter) {return (that.current <= iter.current) ?  1 : 0;}
		friend	long					operator + (const reverse_iterator_vec &that, const reverse_iterator_vec& sec) {return that.current - sec.current;}
		friend	reverse_iterator_vec	operator - (int i, reverse_iterator_vec it) {return it + i;}
		friend	reverse_iterator_vec	operator + (int i, reverse_iterator_vec it) {return it - i;}
		friend	long					operator - (const reverse_iterator_vec &that, const reverse_iterator_vec& sec) {return that.current + sec.current;}
		S								base() const {return current;}
};