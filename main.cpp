/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 21:02:50 by aaitoual          #+#    #+#             */
/*   Updated: 2022/10/25 11:31:49 by aaitoual         ###   ########.fr       */
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
			std::vector<int, my_alloc<int> > test (20, 1);
			// std::cout << std::distance(test2.end(), test2.begin()) << std::endl;
			test.assign(50, 5);
			std::cout << test[0] << std::endl;
			std::cout << test[10] << std::endl;
			std::cout << test.capacity() << std::endl;
			std::cout << test.size() << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	puts ("-----------------------------------------------------------\n");
	{
		try {
			ft::vector<int, my_alloc<int> > test (20, 1);
			// std::cout << std::distance(test2.end(), test2.begin()) << std::endl;
			test.assign(50, 5);
			std::cout << test[0] << std::endl;
			std::cout << test[10] << std::endl;
			std::cout << test.capacity() << std::endl;
			std::cout << test.size() << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
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
	std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
	system("leaks containers");
	return 0;
}