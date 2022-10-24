/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 21:02:50 by aaitoual          #+#    #+#             */
/*   Updated: 2022/10/24 15:45:21 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "containers.hpp"
# include <vector>

template <typename T>
struct my_alloc : public std::allocator<T> {
	static T*	allocate (size_t size) {
		std::cout << "calling allocate for :" << size << std::endl;
		return new T[size];
	}
	static void	deallocate(T *arr, size_t size) {
		std::cout << "calling deallocate for :" << size << std::endl;
		delete [] arr;
	}
};

int main() {
	{
		try {
			std::vector<int, my_alloc<int> > test2 (15, 5);
			std::vector<int, my_alloc<int> > test (10, 1);
			std::cout << std::distance(test2.begin(), test2.end()) << std::endl;
			// test.assign(test2.begin(), test2.begin());
			std::cout << test[0] << std::endl;
			std::cout << test.capacity() << std::endl;
			std::cout << test.size() << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		// std::cout << test.empty() << " " << test.size() << std::endl;
		// std::vector<int>::iterator end = --test.end();
		
		// std::cout << *end << " " << test[9] << std::endl;
		// for (int i = 0; i != 20; i++) std::cout << test[i];
		// std::cout << std::endl;
		// test.push_back(1);
		// for (int i = 0; i != 10; i++) {
		// 	test.push_back(i);
		// }
		// std::cout << (test.begin() == test.end()) << std::endl;
		// std::cout << (test.rbegin() == test.rend()) << std::endl;
		// test.begin() = --test.end();
		// std::cout << *test.rbegin() << std::endl;
		// std::cout << (test.begin() < test.end()) << std::endl;
		// std::vector<int>::iterator end = test.end();
		// std::cout << (begin != end) << std::endl;
		// std::cout << (begin++ != begin) << std::endl;
		// std::cout << *begin << std::endl;
		// std::cout << *++test.begin() << std::endl;
		// std::cout << test[0] << std::endl;
		// test.push_back(1);
		// const std::vector<int>::iterator it = test.begin();
		// std::cout << it
		// test[5] = 4;
		// std::cout << test[5] << std::endl;
	}
	puts("-------------------------------------");
	{
			std::vector<int, my_alloc<int> > test2 (15, 5);
			std::vector<int, my_alloc<int> > test (10, 1);
			std::cout << std::distance(test2.begin(), test2.end()) << std::endl;
			// test.assign(test2.begin(), test2.begin());
			std::cout << test[0] << std::endl;
			std::cout << test.capacity() << std::endl;
			std::cout << test.size() << std::endl;
		// try {
		// 	ft::vector<int> test(10, 5);
		// 	test.at(10);
		// }
		// catch (std::exception& e) {
		// 	std::cout << e.what() << std::endl;
		// }
		// std::cout << test.size() << " " << test.capacity() << std::endl;
		// test.resize(5);
		// std::cout << test.size() << " " << test.capacity() << std::endl;
		// std::cout << test[6] << std::endl;
		// ft::vector<int> test;
		// std::cout << test.max_size() << std::endl;
		// test.push_back(1);
		// for (int i = 0; i != 10; i++) {
		// 	test.push_back(i);
		// }
		// std::cout << (test.begin() == test.end()) << std::endl;
		// std::cout << (test.rbegin() == test.rend()) << std::endl;
		// std::cout << (test.begin() < test.end()) << std::endl;
		// std::cout << (begin < end) << std::endl;
		// std::cout << (begin++ != begin) << std::endl;
		// std::cout << (test.begin() < test.end()) << std::endl;
		// ft::vector<int> test(10, 5);
		// ft::vector<int> test2(test.begin(), test.end());
		// for (int i = 0; i != 10; i++) {
		// 	std::cout << test2[i] << std::endl;
		// }
		// ft::vector<int> test(10, 5);
		// test[5] = 4;
		// std::cout << test[5] << std::endl;
	}
	std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
	system("leaks containers");
	return 0;
}