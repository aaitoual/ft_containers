/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_three.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 22:21:42 by aaitoual          #+#    #+#             */
/*   Updated: 2022/12/02 00:13:08 by aaitoual         ###   ########.fr       */
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
			bool	color; //0 black, 1 red
			NODE (T content_) : parent(NULL), right(NULL), left(NULL), color(1), content(content_) {}
			NODE (void) : parent(NULL), right(NULL), left(NULL), color(0), content(T()) {}
			// NODE (NODE<T> & copy) : parent(NULL), right(NULL), left(NULL), color(1), content(T()) {}
			// void	operator = (const NODE& copy) {
			// 	color = copy.color;
			// 	content = copy.content;
			// 	right = copy->right;
			// 	left = copy->left;
			// 	parent = copy->parent;
			// }
	};
	/////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////
	template<typename T> class RDT {
	public :
		NODE<T>	*__root;
		NODE<T>	*__nullnode;
		NODE<T>	*leaf;
		RDT (void) : __root(NULL), __nullnode(NULL), leaf(new NODE<T>()) {}
		void	RDT_insert(NODE<T> *new_node) {
			NODE<T> *x = __root;
			NODE<T> *y = __root;
			while (x != leaf) {
				y = x;
				if (new_node->content < x->content)
					x = x->left;
				else
					x = x->right;
			}
			if (y == leaf)
			{
				__root = new_node;
				new_node->color = 0;
				new_node->right = leaf;
				new_node->left = leaf;
			}
			else {
				new_node->parent = y;
					new_node->right = leaf;
					new_node->left = leaf;
				if (new_node->content < y->content)
					y->left = new_node;
				else
					y->right = new_node;
				fix_the_three(new_node);
			}
			__root->color = 0;
		}
		void	right_rotation(NODE<T> *node) {
			NODE<T> *new_parent = node->left;
			NODE<T> *tmp_parent = node->parent;		
			node->left = new_parent->right;
			new_parent->right = node;
			if (tmp_parent != __nullnode) {
				if (tmp_parent->right == node)
					tmp_parent->right = new_parent;
				else
					tmp_parent->left = new_parent;
			}
		}
		void	left_rotation(NODE<T> *node) {
			NODE<T> *new_parent = node->right;
			NODE<T> *tmp_parent = node->parent;

			node->right = new_parent->left;
			new_parent->left = node;
			if (tmp_parent != __nullnode) {
				if (tmp_parent->right == node)
					tmp_parent->right = new_parent;
				else
					tmp_parent->left = new_parent;
			}
		}
		void	fix_the_three(NODE<T> *node) {
			NODE<T> *parent = __nullnode;
			NODE<T>	*G_parent = __nullnode;
			NODE<T>	*tmp = node;
			
			parent = node->parent;
			if (parent != __root)
				G_parent = parent->parent;
			while (node != __root && parent->color == 1) { //if the parent is red and the node isn't root yet
				parent = node->parent;
				if (parent != __root)
					G_parent = parent->parent;
				if (which_node(parent) == 2) { // if the parent is the left of the G_parent
					if (G_parent != __nullnode && G_parent->right->color == 1) { //if the uncle is red
						G_parent->color = 1;
						parent->color = 0;
						G_parent->right->color = 0;
					}
					else if (G_parent != __nullnode && which_node(node) == 1) {
						right_rotation(G_parent);
						node->color = 0;
						G_parent->color = 1;
					}
					else if (G_parent != __nullnode && which_node(node) == 2) {
						left_rotation(parent);
						right_rotation(G_parent);
						node->color = 0;
						G_parent->color = 1;
					}
				}
				if (which_node(parent) == 1) {
					if (G_parent != __nullnode && G_parent->left->color== 1) {
						G_parent->color = 1;
						parent->color = 0;
						G_parent->left->color = 0;
					}
					else if (G_parent != __nullnode && which_node(node) == 1) {
						left_rotation(parent);
						right_rotation(G_parent);
						node->color = 0;
						G_parent->color = 1; 
					}
					else if (G_parent != __nullnode && which_node(node) == 2) {
						right_rotation(G_parent);
						node->color = 0;
						G_parent->color = 1; 
					}
				}
				if (G_parent != __nullnode)
					node = G_parent;
				else
					node = parent;
			}
			node = tmp;
		}
	};
	/////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////
	template<typename T>
	int	which_node(NODE<T> *node) {
		if (node->parent->right == node)
			return 1;	
		else if (node->parent->left == node)
			return 2;	
		return 0;
	}
}