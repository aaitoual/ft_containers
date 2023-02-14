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
		ft::RBT<char> three;
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
		// ft::NODE<int> node1(1);
		// ft::NODE<int> node2(2);
		// ft::NODE<int> node3(3);
		// ft::NODE<int> node4(4);
		// ft::NODE<int> node5(87);
		// ft::NODE<int> node6(7);
		// ft::NODE<int> node7(6);
		// ft::NODE<int> node8(20);
		ft::NODE<char> node1('q');
		ft::NODE<char> node2('w');
		ft::NODE<char> node3('e');
		ft::NODE<char> node4('r');
		ft::NODE<char> node5('t');
		ft::NODE<char> node6('y');
		ft::NODE<char> node7('u');
		ft::NODE<char> node8('i');
		ft::NODE<char> node9('o');
		ft::NODE<char> node10('p');
		ft::NODE<char> node11('a');
		ft::NODE<char> node12('s');
		ft::NODE<char> node13('d');
		ft::NODE<char> node14('f');
		ft::NODE<char> node15('g');
		three.RBT_insert('q');
		three.RBT_insert('w');
		three.RBT_insert('e');
		three.RBT_insert('r');
		three.RBT_insert('t');
		three.RBT_insert('y');
		three.RBT_insert('u');
		three.RBT_insert('i');
		three.RBT_insert('o');
		three.RBT_insert('p');
		three.RBT_insert('a');
		three.RBT_insert('s');
		three.RBT_insert('d');
		three.RBT_insert('f');
		three.RBT_insert('g');
		// three.RBT_insert(&node5);
		// three.RBT_insert(&node6);
		// three.RBT_insert(&node7);
		// three.RBT_insert(&node8);
		// three.RBT_delete(&node5);
		// three.RDT_delete(&node2);

		// three.RBT_delete(find_node(1, three));
		// three.RDT_delete(&node8);
		// three.RDT_delete(&node3);
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
	{
		ft::map<int, int> mymap;
		ft::map<int, int>::iterator it;
		ft::map<int, int>::iterator it2;

		mymap[5] = 50;
		mymap[3] = 50;
		mymap[7] = 50;
		mymap[1] = 50;
		mymap[4] = 50;
		mymap[6] = 50;
		mymap[9] = 50;
		mymap[8] = 50;
		mymap[11] = 50;
		mymap[2] = 50;
		mymap[0] = 50;
		mymap[10] = 50;
		mymap[12] = 50;

		it = mymap.begin();
		it2 = mymap.end();
		it2--;
        ft::NODE<std::pair<const int, int> > *tmp = it.base();
		// std::cout << tmp->content.first << std::endl;
		for (; it2 != mymap.begin(); it2--)
			std::cout << (*it2).first << " " << (*it2).second << " test " << std::endl;
		std::cout << (*it2).first << " " << (*it2).second << " test " << std::endl;
		std::cout << tmp->left->content.first << " " << tmp->left->content.second << std::endl;
		// it++;
		// it++;
		// it++;
		// it++;
		// it++;
		// it++;
		// it++;
		// it++;
		// it++;
		// it++;
		// it++;
		// it++;
		// it++;
		// it++;
		// it++;


		//   // print content:
		//   std::cout << "elements in mymap:" << '\n';
		//   std::cout << "a => " << mymap.find('a')->second << '\n';
		//   std::cout << "c => " << mymap.find('c')->second << '\n';
		//   std::cout << "d => " << mymap.find('d')->second << '\n';
		//   std::map<char,int> mymap;
		//   std::map<char,int>::iterator it;
		//   // insert some values:
		//   mymap['a']=10;
		//   mymap['b']=20;
		//   mymap['c']=30;
		//   mymap['d']=40;
		//   mymap['e']=50;
		//   mymap['f']=60;

		//   it=mymap.find('b');
		//   mymap.erase (it);                   // erasing by iterator

		//   mymap.erase ('c');                  // erasing by key

		//   it=mymap.find ('e');
		//   mymap.erase ( it, mymap.end() );    // erasing by range

		//   // show content:
		//   for (it=mymap.begin(); it!=mymap.end(); ++it)
		//     std::cout << it->first << " => " << it->second << '\n';
		// 	}
		// 	std::cout << ("**************************\n\n\n\n**************************") << std::endl;
		// 	{
		//   ft::map<char,int> mymap;
		//   ft::map<char,int>::iterator it;

		//   // insert some values:
		//   mymap['a']=10;
		//   mymap['b']=20;
		//   mymap['c']=30;
		//   mymap['d']=40;
		//   mymap['e']=50;
		//   mymap['f']=60;

		//   it=mymap.find('b');
		//   mymap.erase (it);                   // erasing by iterator

		//   mymap.erase ('c');                  // erasing by key

		//   it=mymap.find ('e');
		//   mymap.erase ( it, mymap.end() );    // erasing by range

		//   // show content:
		//   for (it=mymap.begin(); it!=mymap.end(); ++it)
		//     std::cout << it->first << " => " << it->second << '\n';
	}
}

int main()
{
	std::cout << ("-------------------------------------------------------") << std::endl;
	std::cout << ("-------------------------------------------------------") << std::endl;
	std::cout << ("-------------------------------------------------------") << std::endl;
	std::cout << ("-------------------------------------------------------") << std::endl;
	std::cout << ("-------------------------------------------------------") << std::endl;
	// test();
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
