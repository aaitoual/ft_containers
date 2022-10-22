/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __exceptions.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 01:13:54 by aaitoual          #+#    #+#             */
/*   Updated: 2022/10/22 04:56:03 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <exception>

class __exceptions {
	public :
		class vector_bad_allocation : public std::exception {
			const char *what() const throw();
		};
		class vector_bad_range : public std::exception {
			const char *what() const throw();
		};
};