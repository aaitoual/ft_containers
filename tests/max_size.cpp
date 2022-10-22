/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_size.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 00:41:26 by aaitoual          #+#    #+#             */
/*   Updated: 2022/10/19 00:59:57 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <vector>
# include <string>
# include <iostream>
# include <exception>

void    test (unsigned int in) {    
	std::cout << "in : " << in << ", ~in : " << ~in << std::endl;
}

int main () {
	unsigned int in;

	in = 0;
	// std::cout << "in : " << in << ", ~in : " << ~in << std::endl;
	test (4294967294);
}