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

#include "containers.hpp"
#include <map>
#include <vector>
// #include <iostream>
// #include <type_traits>


		ft::NODE<int> *find_node(const int &key, ft::RBT<int> &tree)
		{
			ft::NODE<int> *node = tree.__root;

			while (node != tree.__nullnode)
			{
				if (key == node->content)
					break;
				if (key < node->content)
				{
					node = node->left;
				}
				else
				{
					node = node->right;
				}
			}
			return node;
		}

void	test()
{
	{
		std::map<int, int> test;
	}
	// std::cout ("\n***************************\n");
	{
		ft::RBT<int> three;
		three.RBT_insert(1);
		three.RBT_insert(2);
		three.RBT_insert(3);

		three.RBT_delete(find_node(1, three));
		three.RBT_delete(find_node(2, three));
		three.RBT_delete(find_node(3, three));
		// std::cout << "root : " << three.__root->content << std::endl;
		std::cout << "*****************************************************************\n";
			// print_node(three.__root);
			std::cout << "ROOT : " << three.__root->content << std::endl;
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

void test2()
	{
  ft::map<char,int> mymap;
  char c;

  mymap ['a']=101;
  mymap ['c']=202;
  mymap ['f']=303;

  for (c='a'; c<'h'; c++)
  {
    std::cout << c;
    if (mymap.count(c)>0)
      std::cout << " is an element of mymap.\n";
    else 
      std::cout << " is not an element of mymap.\n";
	}
}

int main()
{
	std::cout << ("-------------------------------------------------------") << std::endl;
	std::cout << ("-------------------------------------------------------") << std::endl;
	std::cout << ("-------------------------------------------------------") << std::endl;
	std::cout << ("-------------------------------------------------------") << std::endl;
	std::cout << ("-------------------------------------------------------") << std::endl;
	test();
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
