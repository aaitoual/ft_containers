/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ___vec_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 23:42:39 by aaitoual          #+#    #+#             */
/*   Updated: 2022/10/31 23:41:11 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <iterator>

template<typename S>
class iterator_vec : public std::iterator < std::random_access_iterator_tag, S, const S*, S>{
	private :
		S*	current;
	public :
		S*	base() const {return current;};
		iterator_vec () {current = NULL;}
		iterator_vec (S * it) {current = it;}
		S&	operator * () const {return *current;}
		iterator_vec			operator ++ (int) {iterator_vec	tmp(current);current++;return tmp;}
		iterator_vec&			operator ++ () {current++;return *this;}
		iterator_vec			operator -- (int) {iterator_vec	tmp(current);current--;return tmp;}
		iterator_vec&			operator -- () {current--;return *this;}
		// iterator_vec&			operator = (const iterator_vec& copy) {current = copy.current; return *this;}
		iterator_vec&			operator = (const iterator_vec& copy) {current = copy.current; return *this;}
		bool				operator != (iterator_vec& iter) {return (this->current != iter.current) ?  1 : 0;}
		bool				operator == (iterator_vec& iter) {return (this->current != iter) ?  0 : 1;}
		bool				operator > (iterator_vec& iter) {return (this->current > iter.current) ?  1 : 0;}
		bool				operator >= (iterator_vec& iter) {return (this->current >= iter.current) ?  1 : 0;}
		bool				operator < (iterator_vec& iter) {return (this->current < iter.current) ?  1 : 0;}
		bool				operator <= (iterator_vec& iter) {return (this->current <= iter.current) ?  1 : 0;}
		friend bool			operator != (const iterator_vec& that, const iterator_vec& iter) {return (that.current != iter.current) ?  1 : 0;}
		friend bool			operator == (const iterator_vec& that, const iterator_vec& iter) {return (that.current != iter) ?  0 : 1;}
		friend bool			operator > (const iterator_vec& that, const iterator_vec& iter) {return (that.current > iter.current) ?  1 : 0;}
		friend bool			operator >= (const iterator_vec& that, const iterator_vec& iter) {return (that.current >= iter.current) ?  1 : 0;}
		friend bool			operator < (const iterator_vec& that, const iterator_vec& iter) {return (that.current < iter.current) ?  1 : 0;}
		friend bool			operator <= (const iterator_vec& that, const iterator_vec& iter) {return (that.current <= iter.current) ?  1 : 0;}
		friend long			operator - (const iterator_vec &that, const iterator_vec& sec) {return that.current - sec.current;}
};
