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

# include <iterator>
# include "../../implementations/iterator_traits.hpp"

template<typename S>
class iterator_map : public std::iterator <std::random_access_iterator_tag, S, const S, S>{
	public :
		typedef S& 			reference;
		typedef long int	difference_type;
	private :
		S	current;
	public :
		S	base() const {return current;}
		iterator_map () : current() {}
		iterator_map (S it) : current(it) {}
		template <typename T>
		iterator_map (const iterator_map<T>& it) : current(it.base()) {};
		reference				operator * () const {return *current;}
		S						operator -> () const {return current;}
		iterator_map			operator ++ (int) {iterator_map	tmp(current);current++;return tmp;}
		iterator_map&			operator ++ () {current++;return *this;}
		iterator_map			operator -- (int) {iterator_map	tmp(current);current--;return tmp;}
		iterator_map&			operator -- () {current--;return *this;}
		template <typename T>
		iterator_map&			operator = (const iterator_map<T>& copy) {current = copy.base(); return *this;}
		bool					operator != (iterator_map& iter) {return (this->current != iter.current) ?  1 : 0;}
		bool					operator == (iterator_map& iter) {return (this->current != iter.current) ?  0 : 1;}
		
		friend	bool			operator != (const iterator_map& that, const iterator_map& iter) {return (that.base() != iter.base()) ?  1 : 0;}
		friend	bool			operator == (const iterator_map& that, const iterator_map& iter) {return (that.base() != iter) ?  0 : 1;}
};