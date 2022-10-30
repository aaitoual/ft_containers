/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 21:02:50 by aaitoual          #+#    #+#             */
/*   Updated: 2022/10/31 00:11:57 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "containers.hpp"
# include <vector>

template <typename T>
struct my_alloc : public std::allocator<T> {
	// void	construct (T* ptr, const T& val) {
	// 	std::cout << "construct called\n";
	// 	std::cout << val << std::endl;
	// }
	// void	construct (const my_alloc &alloc, T* ptrr) {
	// 	std::cout << "construct called\n";
	// 	// std::cout << val << std::endl;
	// }
	// void	destroy (T* ptr) {
	// 	std::cout << "destroy called\n";
	// }
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
	{
		try {
			std::vector<int, my_alloc<int> > test;
	
			test.reserve(10);
			std::cout << &test[0] << std::endl;
			for (int i = 0; i != 10; i++) test.push_back(i);
			std::vector<int, my_alloc<int> >::iterator begin = --test.begin();
			std::cout << *test.erase(test.begin(), --test.end()) << std::endl;
			for (size_t i = 0; i != test.size(); i++) std::cout << test[i] << " ,";
			std::cout << std::endl;
			std::cout << &test[0] << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	puts ("*-**************************************************************************");
	{
		try {
			ft::vector<int, my_alloc<int> > test;
	
			test.reserve(10);
			std::cout << &test[0] << std::endl;
			for (int i = 0; i != 10; i++) test.push_back(i);
			ft::vector<int, my_alloc<int> >::iterator begin = --test.begin();
			std::cout << *test.erase(test.begin(), --test.end()) << std::endl;
			for (size_t i = 0; i != test.size(); i++) std::cout << test[i] << " ,";
			std::cout << std::endl;
			std::cout << &test[0] << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
}

int main() {
	test();
	std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
	system("leaks containers");
	return 0;
}