/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ___vec_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 23:42:39 by aaitoual          #+#    #+#             */
/*   Updated: 2022/10/20 01:47:37 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <iterator>

template<typename T>
class ___vec_iterator : std::iterator <
                                        std::random_access_iterator_tag,
                                        T,
                                        const T*,
                                        T> {
};
