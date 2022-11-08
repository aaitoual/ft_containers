/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_three.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:00:52 by aaitoual          #+#    #+#             */
/*   Updated: 2022/11/08 13:22:07 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft {
	template<typename T> class NODE {
		public :
			NODE	*parent;
			NODE	*right;
			NODE	*left;
			T		content;
			bool	color;
			NODE (T content_) : parent(NULL), right(NULL), left(NULL), color(1), content(content_) {}
			// NODE	operator = (const NODE& copy) {
			// 	color = copy.color;
			// 	content = copy.content;
			// 	left
			// }
	};

	template<typename T>
	int	which_node(NODE<T> *node) {
		if (node->parent->right == node)
			return 1;	
		else if (node->parent->left == node)
			return 2;	
		return 0;
	}
	
	template<typename T>
	void	rotate(NODE<T> *first, NODE<T> *second, int case__, NODE<T> *__root) {
		NODE<T> *tmp;
		if (case__ == 1) {
			if (which_node(second) == 1) {
				first->right = second->left;
				second->left = first;
				first->right = NULL;
				if (first == __root)
					second = __root;
			}
			else if (which_node(second) == 2) {
				first->left = second->right;
				second->right = first;
				first->left = NULL;
				if (first == __root)
					second = __root;
			}
		}
		if (case__ == 2) {
			if (which_node(second) == 1) {
				tmp = second->left;
				second->left = first;
				first->right = tmp;
				first->color = 0;
				second->color = 1;
				if (first == __root)
					second = __root;
			}
			else if (which_node(second) == 2) {
				tmp = second->right;
				second->right = first;
				first->left = tmp;
				first->color = 0;
				second->color = 1;
				if (first == __root)
					second = __root;
			}
		}
	}
	
	template<typename T>
	void		color_cases(NODE<T> *node, NODE<T> *__root) {
		NODE<T>	*grand_parent;
		if (node->parent && node->parent->parent) {
			grand_parent = node->parent->parent;
			if (grand_parent->right == node->parent) {
				if (grand_parent->left->color == 1 ) {
					grand_parent->left->color = 0;
					grand_parent->color = 1;
					grand_parent->right->color = 0;
				}
				else if (grand_parent->left->color == 0 && node == node->parent->right) {
					rotate(node->parent, node, 2, __root);
				}
				else if (grand_parent->left->color == 0 && node == node->parent->left) {
					rotate(node->parent, node, 1, __root);
				}
			}
			else if (grand_parent->left == node->parent) {
				if (grand_parent->right->color == 1) {
					grand_parent->right->color = 0;
					grand_parent->color = 1;
					grand_parent->left->color = 0;
				}
				else if (grand_parent->right->color == 0 && node == node->parent->right) {
					rotate(node, node->parent, 1, __root);
				}
				else if (grand_parent->right->color == 0 && node == node->parent->left) {
					rotate(node->parent, node, 2, __root);
				}
			}
		}
	}
	template<typename T> class RDT {
		public :
			NODE<T>	*__root;
			NODE<T>	*__nullnode;
			RDT (void) : __root(NULL), __nullnode(NULL) {}
			void	RDT_insert(NODE<T> *new_node) {
				NODE<T> *x = __root;
				NODE<T> *y;
				y = x;
				while (x != __nullnode) {
					y = x;
					if (new_node->content < x->content)
						x = x->left;
					else
						x = x->right;
				}
				if (y == __nullnode)
				{
					__root = new_node;
					new_node->color = 0;
				}
				else {
					if (new_node->content < y->content) {
						new_node->parent = y;
						y->left = new_node;
					}
					else {
						new_node->parent = y;
						y->right = new_node;
					}
				}
				if (new_node->parent && new_node->parent->parent) {
					color_cases(new_node, __root);
				}
				// std::cout << __root->content << std::endl;
				__root->color = 0;
			}
	};
}