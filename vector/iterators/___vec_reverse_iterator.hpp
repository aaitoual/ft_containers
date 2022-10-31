/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ___vec_reverse_iterator.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 21:02:30 by aaitoual          #+#    #+#             */
/*   Updated: 2022/10/31 23:41:25 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <iterator>

template<typename S>
class reverse_iterator_vec : public std::iterator < std::random_access_iterator_tag, S, const S*, S>{
	private :
		S*	current;
	public :
		reverse_iterator_vec () {current = NULL;}
		reverse_iterator_vec (S * it) {current = it;}
		S&	operator * () const {return *current;}
		reverse_iterator_vec			operator ++ (int) {reverse_iterator_vec	tmp(current);current--;return tmp;}
		reverse_iterator_vec&			operator ++ () {current--;return *this;}
		reverse_iterator_vec			operator -- (int) {reverse_iterator_vec	tmp(current);current++;return tmp;}
		reverse_iterator_vec&			operator -- () {current++;return *this;}
		reverse_iterator_vec&			operator = (reverse_iterator_vec copy) {current = copy.current; return *this;};
		bool				operator != (reverse_iterator_vec& iter) {return (this->current != iter.current) ?  1 : 0;}
		bool				operator == (reverse_iterator_vec& iter) {return (this->current != iter) ?  0 : 1;}
		bool				operator < (reverse_iterator_vec& iter) {return (this->current > iter.current) ?  1 : 0;}
		bool				operator <= (reverse_iterator_vec& iter) {return (this->current >= iter.current) ?  1 : 0;}
		bool				operator > (reverse_iterator_vec& iter) {return (this->current < iter.current) ?  1 : 0;}
		bool				operator >= (reverse_iterator_vec& iter) {return (this->current <= iter.current) ?  1 : 0;}
		friend bool			operator != (const reverse_iterator_vec& that, const reverse_iterator_vec& iter) {return (that.current != iter.current) ?  1 : 0;}
		friend bool			operator == (const reverse_iterator_vec& that, const reverse_iterator_vec& iter) {return (that.current != iter) ?  0 : 1;}
		friend bool			operator < (const reverse_iterator_vec& that, const reverse_iterator_vec& iter) {return (that.current > iter.current) ?  1 : 0;}
		friend bool			operator <= (const reverse_iterator_vec& that, const reverse_iterator_vec& iter) {return (that.current >= iter.current) ?  1 : 0;}
		friend bool			operator > (const reverse_iterator_vec& that, const reverse_iterator_vec& iter) {return (that.current < iter.current) ?  1 : 0;}
		friend bool			operator >= (const reverse_iterator_vec& that, const reverse_iterator_vec& iter) {return (that.current <= iter.current) ?  1 : 0;}
};