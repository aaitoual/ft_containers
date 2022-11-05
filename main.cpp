/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 21:02:50 by aaitoual          #+#    #+#             */
/*   Updated: 2022/11/03 19:33:59 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "containers.hpp"
# include <vector>
# include "./implementations/reverse_iterator.hpp"
# include "map"


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

struct A { };
struct B { B(){} };
struct C { C(int){} };

void	test()
{
  {
    std::vector<int>::iterator a;
    a++;
    ++a;
    *a++;
  }
  {
    ft::vector<int>::iterator a;
    a++;
    ++a;
    *a++;
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