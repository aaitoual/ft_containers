/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 21:02:50 by aaitoual          #+#    #+#             */
/*   Updated: 2022/11/06 01:51:21 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "containers.hpp"
# include <vector>
# include "./implementations/reverse_iterator.hpp"
# include "map"


#include <iostream>
#include <iomanip>
#include <type_traits>

// void	test() {
// 	{
// 		ft::vector<int> test;
// 		test.reserve(2);
// 		// test[0] = 10;
// 		std::cout << *test.rbegin().base() << std::endl;
// 		test.push_back(10);
// 		test.push_back(10);
// 		std::cout << *test.rbegin().base() << std::endl;
// 	}
// 	char * r = (char *)malloc (100000);
// 	{
// 		std::vector<int> test;
// 		test.reserve(2);
// 		// test[0] = 10;
// 		std::cout << *test.rbegin().base() << std::endl;
// 		test.push_back(10);
// 		test.push_back(10);
// 		std::cout << *test.rbegin().base() << std::endl;
// 	}
// }

class A {};
 
enum E : int {};

template <class T>
T f(T i)
{
    static_assert(std::is_integral<T>::value, "Integral required.");
    return i;
}

template <class T>
T g(T i)
{
    static_assert(ft::is_integral<T>::value, "Integral required.");
    return i;
}

bool mycomp (char c1, char c2)
{ return std::tolower(c1)<std::tolower(c2); }

void	test()
{
	{
    	char foo[]="Apple";
  		char bar[]="apartment";
		
  		std::cout << std::boolalpha;
		
  		std::cout << "Comparing foo and bar lexicographically (foo<bar):\n";
		
  		std::cout << "Using default comparison (operator<): ";
  		std::cout << std::lexicographical_compare(foo,foo+5,bar,bar+9);
  		std::cout << '\n';
		
  		std::cout << "Using mycomp as comparison object: ";
  		std::cout << std::lexicographical_compare(foo,foo+5,bar,bar+9,mycomp);
  		std::cout << '\n';
	}
	puts ("\n***************************\n");
	{
    	char foo[]="Apple";
  		char bar[]="apartment";
		
  		std::cout << std::boolalpha;
		
  		std::cout << "Comparing foo and bar lexicographically (foo<bar):\n";
		
  		std::cout << "Using default comparison (operator<): ";
  		std::cout << std::lexicographical_compare(foo,foo+5,bar,bar+9);
  		std::cout << '\n';
		
  		std::cout << "Using mycomp as comparison object: ";
  		std::cout << std::lexicographical_compare(foo,foo+5,bar,bar+9,mycomp);
  		std::cout << '\n';
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