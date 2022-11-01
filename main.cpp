/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 21:02:50 by aaitoual          #+#    #+#             */
/*   Updated: 2022/11/01 05:14:35 by aaitoual         ###   ########.fr       */
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
			ft::vector<int>::iterator begin = --test.begin();
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


// int test2 ()
// {
// 	{
// 		std::vector<int> foo (3,100);   // three ints with a value of 100
// 		std::vector<int> bar (2,200);   // two ints with a value of 200
// 		if (foo==bar) std::cout << "foo and bar are equal\n";
// 		if (foo!=bar) std::cout << "foo and bar are not equal\n";
// 		if (foo< bar) std::cout << "foo is less than bar\n";
// 		if (foo> bar) std::cout << "foo is greater than bar\n";
// 		if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
// 		if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
// 	}
// 	{
// 		ft::vector<int> foo (3,100);   // three ints with a value of 100
// 		ft::vector<int> bar (2,200);   // two ints with a value of 200
// 		if (foo==bar) std::cout << "foo and bar are equal\n";
// 		if (foo!=bar) std::cout << "foo and bar are not equal\n";
// 		if (foo< bar) std::cout << "foo is less than bar\n";
// 		if (foo> bar) std::cout << "foo is greater than bar\n";
// 		if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
// 		if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
// 	}

//   return 0;
// }

void	rev_it() {
  std::vector<int> myvector;
  for (int i=0; i<10; i++) myvector.push_back(i);  // myvector: 0 1 2 3 4 5 6 7 8 9

  typedef std::vector<int>::iterator iter_type;

  std::reverse_iterator<iter_type> rev_iterator = myvector.rbegin();

  std::cout << "The fourth element from the end is: " << rev_iterator[3] << '\n';
}

void	it() {
	{
		std::vector<int> test;
		for (int i = 0; i != 10; i++) test.push_back(i);
		std::vector<int>::iterator it = test.begin();
		it += 5;
		std::cout << *++it << std::endl;
	}
	puts ("********************************");
	{
		ft::vector<int> test;
		for (int i = 0; i != 10; i++) test.push_back(i);
		ft::vector<int>::iterator it = test.begin();
		it += 5;
		std::cout << *++it << std::endl;
	}
}



int main() {
	rev_it();
	// it();
	// test();
	// test2();
	std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
	system("leaks containers");
	return 0;
}