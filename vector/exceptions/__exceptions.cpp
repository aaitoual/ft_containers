/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __exceptions.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 01:21:07 by aaitoual          #+#    #+#             */
/*   Updated: 2022/10/22 04:56:34 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "__exceptions.hpp"

typedef __exceptions::vector_bad_allocation vector_exception;

const char* vector_exception::what() const throw() {
	return "vector";
}

const char* __exceptions::vector_bad_range::what() const throw() {
	return "vector";
}