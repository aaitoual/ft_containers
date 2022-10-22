/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 21:02:50 by aaitoual          #+#    #+#             */
/*   Updated: 2022/10/22 06:23:35 by aaitoual         ###   ########.fr       */
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
			std::vector<int, my_alloc<int> > const test;
			std::vector<int, my_alloc<int> > ori(test);
			// for (int i = 0; i != 10; i++) {
			// 	ori.push_back (55);
			// }
			// std::vector<int>::iterator end = ori.end();
			// std::vector<int>::iterator beg = ori.begin();
			// std::cout << *beg++ << std::endl;
			// std::cout << *end << std::endl;
			// std::vector<int> new_vec(ori.end(), ori.begin());
			// for (int i = 0; i != 10; i++) {
			// 	std::cout << new_vec[i] << std::endl;
			// }
			// std::cout << new_vec.capacity() << std::endl;
			// puts ("done");
			// std::cout << *beg << std::endl;
			// std::cout << new_vec.size() << std::endl;
			// std::cout << "**************** " << new_vec[0] << std::endl;
		}
		catch (std::exception &e) {
			std::cout << "*******************************************\n" << e.what() << std::endl;
		}
	}
	// std::cout << "\n------------------------------------------------------------------\n";
	// {
	// 	try {
	// 		ft::vector<int> ori;
	// 		for (int i = 0; i != 10; i++) {
	// 			ori.push_back(55);
	// 		}
	// 		ft::vector<int>::iterator beg = ori.begin();
	// 		ft::vector<int>::iterator end = ori.end();
	// 		std::cout << *beg << std::endl;
	// 		std::cout << *end << std::endl;
	// 		ft::vector<int> new_vec (ori.end(), ori.begin());
	// 		// for (int i = 0; i != 10; i++) {
	// 		// 	std::cout << new_vec[i] << std::endl;
	// 		// }
	// 		std::cout << "**************** " << new_vec[0] << std::endl;
	// 	}
	// 	catch (std::exception &e) {
	// 		std::cout << "*******************************************\n" << e.what() << std::endl;
	// 	}
	// }
	std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
	system("leaks containers");
	return 0;
}