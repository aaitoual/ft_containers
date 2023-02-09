/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 21:02:50 by aaitoual          #+#    #+#             */
/*   Updated: 2023/01/11 05:29:57 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "containers.hpp"
# include <map>
# include <vector>
// #include <iostream>
// #include <type_traits>

// void	test()
// {
// 	{
// 		std::map<int, int> test;
// 	}
// 	// std::cout ("\n***************************\n");
// 	{
// 		ft::RBT<int> three;
// 		// ft::NODE<int> node1(8);
// 		// ft::NODE<int> node2(5);
// 		// ft::NODE<int> node3(15);
// 		// ft::NODE<int> node4(19);
// 		// ft::NODE<int> node5(9);
// 		// ft::NODE<int> node6(13);
// 		// ft::NODE<int> node7(23);
// 		// ft::NODE<int> node1(8);
// 		// ft::NODE<int> node2(18);
// 		// ft::NODE<int> node3(5);
// 		// ft::NODE<int> node4(15);
// 		// ft::NODE<int> node5(17);
// 		// ft::NODE<int> node6(25);
// 		// ft::NODE<int> node7(40);
// 		// ft::NODE<int> node8(80);
// 		ft::NODE<int> node1(10);
// 		ft::NODE<int> node2(8);
// 		ft::NODE<int> node3(90);
// 		ft::NODE<int> node4(5);
// 		ft::NODE<int> node5(87);
// 		ft::NODE<int> node6(7);
// 		ft::NODE<int> node7(6);
// 		ft::NODE<int> node8(20);
// 		three.RBT_insert(&node1);
// 		three.RBT_insert(&node2);
// 		three.RBT_insert(&node3);
// 		three.RBT_insert(&node4);
// 		three.RBT_insert(&node5);
// 		three.RBT_insert(&node6);
// 		three.RBT_insert(&node7);
// 		three.RBT_insert(&node8);
// 		three.RBT_delete(&node5);
// 		// three.RDT_delete(&node2);
// 		three.RBT_delete(&node7);
// 		// three.RDT_delete(&node8);
// 		// three.RDT_delete(&node3);
// 		// std::cout << "root : " << three.__root->content << std::endl;
// 		std::cout << "*****************************************************************\n";
// 			// print_node(three.__root);
// 			std::cout << "ROOT : " << three.__root->content << std::endl;
// 			// std::cout << "content : " << three.__root->left->content << std::endl;
// 			ft::print_tree(three.__root, three.__nullnode);
// 		// std::cout << three.__root->right->left->color << std::endl;
// 		std::cout << "*****************************************************************\n";
// 		// std::cout << three.__root->right->right->right->content << std::endl;
// 		// int tmp;
// 		// int i = 0;
// 		// ft::NODE<int> *node;
// 		// node = new ft::NODE<int>[100];
// 		// while (i != 100) {
// 		// 	std::cin >> tmp;
// 		// 	std::cout << std::endl;
// 		// 	node[i] = ft::NODE<int>(tmp);
// 		// 	three.RDT_insert(&node[i]);
// 		// 	std::cout << "*****************************************************************\n";
// 		// 	ft::print_node(three.__root);
// 		// 	std::cout << "*****************************************************************\n";
// 		// 	i++;
// 		// }
// 	}
// }


void	test2() {
	{
  std::map<char,int> mymap;
  mymap['a']=101;
  mymap['b']=202;
  mymap['c']=302;

  std::cout << "mymap.size() is " << mymap.size() << '\n';
	}
	std::cout << ("**************************\n\n\n\n**************************") << std::endl;
	{
  ft::map<char,int> mymap;
  mymap['a']=101;
  mymap['b']=202;
  mymap['c']=302;

  std::cout << "mymap.size() is " << mymap.size() << '\n';
	}
}

int main() {
	std::cout << ("-------------------------------------------------------") << std::endl;
	std::cout << ("-------------------------------------------------------") << std::endl;
	std::cout << ("-------------------------------------------------------") << std::endl;
	std::cout << ("-------------------------------------------------------") << std::endl;
	std::cout << ("-------------------------------------------------------") << std::endl;
	test2();
	// std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
	// while (1);
	// system("leaks containers");
	std::cout << ("-------------------------------------------------------") << std::endl;
	std::cout << ("-------------------------------------------------------") << std::endl;
	std::cout << ("-------------------------------------------------------") << std::endl;
	std::cout << ("-------------------------------------------------------") << std::endl;
	std::cout << ("-------------------------------------------------------") << std::endl;
	return 0;
}
