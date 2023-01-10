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
# include <map>
# include <vector>
#include <iostream>
#include <type_traits>

template <typename T>
void print_tree(ft::NODE<T> *root, ft::NODE<T> *NULL_NODE, int indent = 0) {
    if (root == NULL_NODE) {
        return;
    }
    print_tree(root->right, NULL_NODE, indent + 4);
    if (indent) {
        std::cout << std::setw(indent) << ' ';
    }
    if (root->right) std::cout << " /\n" << std::setw(indent) << ' ';
    std::cout << root->content << " (" << (root->color ? "red" : "black") << ")\n ";
    if (root->left) std::cout << std::setw(indent) << ' ' << " \\\n";
    print_tree(root->left, NULL_NODE, indent + 4);
}

void	test()
{
	{
		std::map<int, int> test;
	}
	// puts ("\n***************************\n");
	{
		ft::RDT<int> three;
		// ft::NODE<int> node1(8);
		// ft::NODE<int> node2(5);
		// ft::NODE<int> node3(15);
		// ft::NODE<int> node4(19);
		// ft::NODE<int> node5(9);
		// ft::NODE<int> node6(13);
		// ft::NODE<int> node7(23);
		// ft::NODE<int> node1(8);
		// ft::NODE<int> node2(18);
		// ft::NODE<int> node3(5);
		// ft::NODE<int> node4(15);
		// ft::NODE<int> node5(17);
		// ft::NODE<int> node6(25);
		// ft::NODE<int> node7(40);
		// ft::NODE<int> node8(80);
		ft::NODE<int> node1(12);
		ft::NODE<int> node2(8);
		ft::NODE<int> node3(15);
		ft::NODE<int> node4(1);
		ft::NODE<int> node5(9);
		ft::NODE<int> node6(13);
		ft::NODE<int> node7(23);
		ft::NODE<int> node8(10);
		three.RDT_insert(&node1);
		three.RDT_insert(&node2);
		three.RDT_insert(&node3);
		three.RDT_insert(&node4);
		three.RDT_insert(&node5);
		three.RDT_insert(&node6);
		three.RDT_insert(&node7);
		three.RDT_insert(&node8);
		// three.RDT_delete(&node6);
		// three.RDT_delete(&node2);
		// three.RDT_delete(&node7);
		three.RDT_delete(&node2);
		// std::cout << "root : " << three.__root->content << std::endl;
		std::cout << "*****************************************************************\n";
			// print_node(three.__root);
			// std::cout << "ROOT : " << three.__root->content << std::endl;
			// std::cout << "content : " << three.__root->left->content << std::endl;
			ft::print_tree(three.__root, three.__nullnode);
		// std::cout << three.__root->right->left->color << std::endl;
		std::cout << "*****************************************************************\n";
		// std::cout << three.__root->right->right->right->content << std::endl;
		// int tmp;
		// int i = 0;
		// ft::NODE<int> *node;
		// node = new ft::NODE<int>[100];
		// while (i != 100) {
		// 	std::cin >> tmp;
		// 	std::cout << std::endl;
		// 	node[i] = ft::NODE<int>(tmp);
		// 	three.RDT_insert(&node[i]);
		// 	std::cout << "*****************************************************************\n";
		// 	ft::print_node(three.__root);
		// 	std::cout << "*****************************************************************\n";
		// 	i++;
		// }
	}
}

int main() {
	test();
	std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
	// system("leaks containers");
	return 0;
}
