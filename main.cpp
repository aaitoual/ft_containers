/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 21:02:50 by aaitoual          #+#    #+#             */
/*   Updated: 2022/10/29 15:14:46 by aaitoual         ###   ########.fr       */
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
	// static T*	allocate (size_t size) {
	// 	std::cout << "calling allocate for :" << size << std::endl;
	// 	return new T[size];
	// }
	// static void	deallocate(T *arr, size_t size) {
	// 	std::cout << "calling deallocate for :" << size << std::endl;
	// 	delete [] arr;
	// }
};

void	test() {
	{
		std::vector<int> test;
		std::vector<int, my_alloc<int> > test2;
		for (int i = 0; i != 10; i++) test.push_back(20);
		for (int i = 0; i != 20; i++) test2.push_back(10);
		std::cout << "test size : " << test.size() << " test capacity : " << test.capacity() << std::endl;
		std::cout << "test2 size : " << test2.size() << " test2 capacity : " << test2.capacity() << std::endl;
		std::vector<int>::iterator test2_iterator = test2.begin();
		std::vector<int>::iterator test_iterator = test.begin();
		// test.swap(test2);
		for (int i = 0; i != 10; i++) std::cout << test2[i] << ", ";
		std::cout << std::endl;
		for (int i = 0; i != 10; i++) std::cout << test[i] << ", ";
		std::cout << std::endl;
		std::cout << "test size : " << test.size() << " test capacity : " << test.capacity() << std::endl;
		std::cout << "test2 size : " << test2.size() << " test2 capacity : " << test2.capacity() << std::endl;
		std::cout << "test begin : " << *test_iterator << std::endl;
		std::cout << "test2 begin : " << *test2_iterator << std::endl;
	}
	puts ("*-**************************************************************************");
	{
		ft::vector<int> test;
		ft::vector<int, my_alloc<int> > test2;
		for (int i = 0; i != 10; i++) test.push_back(20);
		for (int i = 0; i != 20; i++) test2.push_back(10);
		std::cout << "test size : " << test.size() << " test capacity : " << test.capacity() << std::endl;
		std::cout << "test2 size : " << test2.size() << " test2 capacity : " << test2.capacity() << std::endl;
		ft::vector<int>::iterator test2_iterator = test2.begin();
		ft::vector<int>::iterator test_iterator = test.begin();
		// test.swap(test2);
		for (int i = 0; i != 10; i++) std::cout << test2[i] << ", ";
		std::cout << std::endl;
		for (int i = 0; i != 10; i++) std::cout << test[i] << ", ";
		std::cout << std::endl;
		std::cout << "test size : " << test.size() << " test capacity : " << test.capacity() << std::endl;
		std::cout << "test2 size : " << test2.size() << " test2 capacity : " << test2.capacity() << std::endl;
		std::cout << "test begin : " << *test_iterator << std::endl;
		std::cout << "test2 begin : " << *test2_iterator << std::endl;
	}
}

int main() {
	test();
	std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
	system("leaks containers");
	return 0;
}