/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 21:02:50 by aaitoual          #+#    #+#             */
/*   Updated: 2022/10/25 18:29:32 by aaitoual         ###   ########.fr       */
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

void	test() {
	try {
		// std::vector<int, my_alloc<int> > test2(10, 1);
		std::vector<int, my_alloc<int> > test;
		// test.reserve(10);
		// for (int i = 0; i != 10; i++) test.push_back(i);
		std::cout << "size : " << test.size() << " capacity : " << test.capacity() << std::endl;
		test.insert(test.end(), 23, 5);
		std::cout << "size : " << test.size() << " capacity : " << test.capacity() << std::endl;
		// std::cout << test[0] << std::endl;
		for (int i = 0; i != 12; i++) std::cout << test[i] << " ";
		std::cout << std::endl;
	}
	catch (std::exception &i) {
		std::cout << i.what() << std::endl;
	}
	puts ("-----------------------------------------------------------\n");
	try {
		// std::vector<int, my_alloc<int> > test2(10, 1);
		ft::vector<int, my_alloc<int> > test;
		// test.reserve(10);
		// for (int i = 0; i != 10; i++) test.push_back(i);
		std::cout << "size : " << test.size() << " capacity : " << test.capacity() << std::endl;
		test.insert(test.end(), 23, 5);
		std::cout << "size : " << test.size() << " capacity : " << test.capacity() << std::endl;
		// std::cout << test[0] << std::endl;
		for (int i = 0; i != 12; i++) std::cout << test[i] << " ";
		std::cout << std::endl;
	}
	catch (std::exception &i) {
		std::cout << i.what() << std::endl;
	}
	// try {
	// 	// std::vector<int, my_alloc<int> > test2(10, 1);
	// 	ft::vector<int, my_alloc<int> > test;
	// 	test.reserve(10);
	// 	for (int i = 0; i != 10; i++) test.push_back(i);
	// 	std::cout << "size : " << test.size() << " capacity : " << test.capacity() << std::endl;
	// 	test.insert(test.end(), 88);
	// 	std::cout << "size : " << test.size() << " capacity : " << test.capacity() << std::endl;
	// 	for (int i = 0; i != 12; i++) std::cout << test[i] << " ";
	// 	std::cout << std::endl;
	// }
	// catch (std::exception &i) {
	// 	std::cout << i.what() << std::endl;
	// }
	// {
	// 	ft::vector<int, my_alloc<int> > test(10, 5);
	// }
	// {
		
	// }
	// {
	// 	try {
	// 		ft::vector<int, my_alloc<int> > test (10, 1);
	// 		// std::cout << std::distance(test2.end(), test2.begin()) << std::endl;
	// 		test.assign(10, 5);
	// 		std::cout << test[0] << std::endl;
	// 		std::cout << test.capacity() << std::endl;
	// 		std::cout << test.size() << std::endl;
	// 	}
	// 	catch (std::exception &e) {
	// 		std::cout << e.what() << std::endl;
	// 	}
	// }
}

int main() {
	test();
	std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
	system("leaks containers");
	return 0;
}