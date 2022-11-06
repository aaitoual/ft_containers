/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pair.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 23:49:28 by aaitoual          #+#    #+#             */
/*   Updated: 2022/11/06 23:52:09 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include "pair.hpp"

namespace ft {
    template <class T1, class T2>  ft::pair<T1, T2> make_pair (T1 x, T2 y) {
        return ft::make_pair<T1, T2>(x, y);
    }
}