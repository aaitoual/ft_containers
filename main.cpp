/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 21:02:50 by aaitoual          #+#    #+#             */
/*   Updated: 2022/11/06 23:54:53 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "containers.hpp"
# include <vector>
# include "./implementations/reverse_iterator.hpp"
# include "map"


// #include <iostream>
// #include <iomanip>
// #include <type_traits>


void	test()
{
	{
		std::vector<int> TEST;
		std::pair <std::string,double> product1;                     // default constructor
		std::pair <std::string,double> product2 ("tomatoes",2.30);   // value init
		std::pair <std::string,double> product3 (product2);          // copy constructor
		
		product1 = std::make_pair(std::string("lightbulbs"),0.99);   // using make_pair (move)
		
		product2.first = "shoes";                  // the type of first is string
		product2.second = 39.90;                   // the type of second is double
		
		std::cout << "The price of " << product1.first << " is $" << product1.second << '\n';
		std::cout << "The price of " << product2.first << " is $" << product2.second << '\n';
		std::cout << "The price of " << product3.first << " is $" << product3.second << '\n';
	}
	puts ("\n***************************\n");
	{
		ft::pair <std::string,double> product1;                     // default constructor
		ft::pair <std::string,double> product2 ("tomatoes",2.30);   // value init
		ft::pair <std::string,double> product3 (product2);          // copy constructor
		
		product1 = ft::make_pair(std::string("lightbulbs"),0.99);   // using make_pair (move)
		
		product2.first = "shoes";                  // the type of first is string
		product2.second = 39.90;                   // the type of second is double
		
		std::cout << "The price of " << product1.first << " is $" << product1.second << '\n';
		std::cout << "The price of " << product2.first << " is $" << product2.second << '\n';
		std::cout << "The price of " << product3.first << " is $" << product3.second << '\n';
	}
}

int main() {
	// rev_it();
	// it();
	test();
	// test2();
	std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
	system("leaks containers");
	return 0;
}