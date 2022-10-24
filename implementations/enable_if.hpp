/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 07:13:23 by aaitoual          #+#    #+#             */
/*   Updated: 2022/10/24 07:43:11 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft {
	template <bool valu, typename T = void>
	struct enable_if
	{
		typedef T type;
	};
	
	template <typename T>
	struct enable_if <false, T>
	{
	};
}
