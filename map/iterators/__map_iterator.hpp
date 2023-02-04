/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __map_iterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 23:06:18 by aaitoual          #+#    #+#             */
/*   Updated: 2023/01/10 23:12:59 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <iterator>
# include "../../implementations/iterator_traits.hpp"
# include "../RBT/red_black_three.hpp"

template<typename S>
class iterator_map : public std::iterator <std::random_access_iterator_tag, S, const S, S>{
	public :
		typedef S& 			reference;
		typedef long int	difference_type;
		typedef	S*			pointer;
	private :
		ft::NODE<S>	*current;
		ft::NODE<S>	*ref_ret;
	public :
		ft::NODE<S>*	base() const {return current;}
		iterator_map () : current(), ref_ret() {}
		iterator_map (ft::NODE<S>* it) : current(it), ref_ret() {}
		template <typename T>
		iterator_map (iterator_map<T>& it) : current(it.base()), ref_ret() {};
		S&				operator * () const {return (current != NULL) ? current->content : ref_ret->content;}
		// std::pair<i				operator * () const {return std::pair<int, std::string> (1, "test");}
		S*						operator -> () const {S& tmp = current->content; return &tmp;}
		iterator_map			operator ++ (int) {
			iterator_map	tmp(current);
			if (current != NULL)
				current = current->get_next();
			else
				current = current + 1;
			return tmp;
		}
		iterator_map&			operator ++ () {
			if (current != NULL)
				current = current->get_next();
			else
				current = current + 1;
			return *this;
		}
		iterator_map			operator -- (int) {
			iterator_map	tmp(current);
			if (current != NULL)
				current = current->get_prev();
			else
				current = current - 1;
			return tmp;}
		iterator_map&			operator -- () {
			current = current->get_prev();
			return *this;
		}
		// template <typename T>
		iterator_map&			operator = (const iterator_map<S>& copy) {current = copy.base(); return *this;}
		bool					operator != (iterator_map& iter) {return (this->current != iter.current) ?  1 : 0;}
		// bool					operator == (iterator_map& iter) {return (this->current != iter.current) ?  0 : 1;}
		
		friend	bool			operator != (const iterator_map& that, const iterator_map& iter) {return (that.base() != iter.base()) ?  1 : 0;}
		// friend	bool			operator == (const iterator_map& that, const iterator_map& iter) {return (that.base() != iter) ?  0 : 1;}
};