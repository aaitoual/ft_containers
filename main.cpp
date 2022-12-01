/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 21:02:50 by aaitoual          #+#    #+#             */
/*   Updated: 2022/12/01 22:38:15 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "containers.hpp"
# include "map"
// # include <vector>
// # include "./implementations/reverse_iterator.hpp"

// #include <iostream>
// #include <iomanip>
// #include <type_traits>

template <typename T>
void	print_node(ft::NODE<T> *node)
{
	if (node->left)
		print_node(node->left);
	std::cout << node->content << "   " << node->color << std::endl;
	if (node->right)
		print_node(node->right);
}

void	test()
{
	{
		std::map<int, int> test;
	}
	puts ("\n***************************\n");
	{
		ft::RDT<int> three;
		// ft::NODE<int> node1(8);
		// ft::NODE<int> node2(5);
		// ft::NODE<int> node3(15);
		// ft::NODE<int> node4(19);
		// ft::NODE<int> node5(9);
		// ft::NODE<int> node6(13);
		// ft::NODE<int> node7(23);
		ft::NODE<int> node1(8);
		ft::NODE<int> node2(18);
		ft::NODE<int> node3(5);
		ft::NODE<int> node4(15);
		ft::NODE<int> node5(17);
		ft::NODE<int> node6(25);
		ft::NODE<int> node7(40);
		ft::NODE<int> node8(80);
		// ft::NODE<int> node7(40);
		// three.RDT_insert(&node1);
		// three.RDT_insert(&node2);
		// three.RDT_insert(&node3);
		// three.RDT_insert(&node4);
		// three.RDT_insert(&node5);
		// three.RDT_insert(&node6);
		// three.RDT_insert(&node7);
		// three.RDT_insert(&node8);
		// std::cout << "root : " << three.__root->content << std::endl;
		// std::cout << three.__root->right->left->content << std::endl;
		// print_node(three.__root);
		int tmp;
		int i = 0;
		ft::NODE<int> *node;
		node = new ft::NODE<int>[100];
		while (i != 1000) {
			std::cin >> tmp;
			std::cout << std::endl;
			node[i] = ft::NODE<int>(tmp);
			three.RDT_insert(&node[i]);
			std::cout << "*****************************************************************\n";
			print_node(three.__root);
			std::cout << "*****************************************************************\n";
			i++;
		}
	}
}

int main() {
	test();
	std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
	system("leaks containers");
	return 0;
}