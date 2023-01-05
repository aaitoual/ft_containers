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
	template <typename T>
	void	print_node(ft::NODE<T> *node)
	{
		if (node->left)
			print_node(node->left);
		std::cout << node->content << "   " << node->color << std::endl;
		if (node->right)
			print_node(node->right);
	}
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
				new_node->right = __nullnode;
				new_node->left = __nullnode;
			}
			else {
				new_node->parent = y;
				new_node->right = __nullnode;
				new_node->left = __nullnode;
				if (new_node->content < y->content)
					y->left = new_node;
				else
					y->right = new_node;
				fix_the_three(new_node);
			}
			__root->color = 0;
		}

		void	transplant(NODE<T> *parent, NODE<T> *child) {
			if (parent->parent == __nullnode)
				__root = child;
			else if (which_node(parent) == 2)
				parent->parent->left = child;
			else
				parent->parent->right = child;
			child->parent = parent->parent;
		}

		NODE<T>	*get_sub_child_min(int case_, NODE<T> *node) {
			NODE<T>	*child;
			NODE<T>	*ret;
			if (case_ == 1) {
				child = node->right;
				ret = node->right;
				while (child != __nullnode) {
					ret = child;
					child = child->left;
				}
			}
			return ret;
		}

		NODE<T>	*get_sibling(NODE<T> *node) {
			if (node == __nullnode)
				return __nullnode;
			if (node->parent == __nullnode)
				return __nullnode;
			if (which_node(node) == 1)
				return node->parent->left;
			if (which_node(node) == 2)
				return node->parent->right;
			return __nullnode;
		}

		void	___delete_fix(NODE<T> *node) {
			NODE<T> *sibling;

			while (node != __root && node != __nullnode && !node->color) {
				sibling = get_sibling(node);
				if (sibling != __nullnode && sibling->color) {
					sibling->color = 0;
					node->parent->color = 1;
					left_rotation(node->parent);
					sibling = get_sibling(node); //check;
				}
				if ((sibling == __nullnode || !sibling->color) && (sibling->right == __nullnode || !sibling->right->color) && (sibling->left == __nullnode || !sibling->left->color)) {
					sibling->color = 1;
					node = node->parent;
				}
				if (sibling != __nullnode && !sibling->color && (sibling->right == __nullnode || !sibling->right->color) && (sibling->left != __nullnode && sibling->left->color)) {
					sibling->color = 1;
					right_rotation(sibling);
					sibling = get_sibling(node);
				}
				if (sibling != __nullnode && !sibling->color && (sibling->right != __nullnode && sibling->right->color)) {
					sibling->color = node->parent->color;
					node->parent->color = 0;
					if (sibling->right != __nullnode)
						sibling->right->color = 0;
					left_rotation(node->parent);
					node = __root;
				}
			}
			if (node != __nullnode)
				node->color = 0; 
		}

		void	__delete(NODE<T> *node) {
			bool	ori_color;
			NODE<T>	*tmp_node;
			NODE<T>	*tmp_node2;

			ori_color = node->color;
			if (node->left == __nullnode) {
				tmp_node = node->right;
				transplant(node, tmp_node);
				if (!ori_color)
					___delete_fix(tmp_node);
			}
			else if (node->right == __nullnode) {
				tmp_node = node->left;
				transplant(node, tmp_node);
				if (!ori_color)
					___delete_fix(tmp_node);
			}
			else {
				tmp_node = get_sub_child_min(1, node);
				tmp_node2 = tmp_node->right;
				transplant(tmp_node, tmp_node2);
				tmp_node->right = tmp_node2->parent;
				tmp_node2->parent = tmp_node;
				transplant(node, tmp_node);
				node->left->parent = tmp_node;
				tmp_node->left = node->left;
				tmp_node->parent = node->parent;
				if (!ori_color)
					___delete_fix(tmp_node2);
			}

		}

		void	RDT_delete(NODE<T> *delete_node) {
			__delete(delete_node);
		}
		void	right_rotation(NODE<T> *node) {
			NODE<T> *new_parent = node->left;

			node->left = new_parent->right;
			if (new_parent->right != __nullnode)
				new_parent->right->parent = node;
			new_parent->parent = node->parent;
			if (new_parent->parent == __nullnode)
				__root = new_parent;
			else if (new_parent->parent->right == node)
				new_parent->parent->right = new_parent;
			else
				new_parent->parent->left = new_parent;
			new_parent->right = node;
			node->parent = new_parent;
		}
		void	left_rotation(NODE<T> *node) {
			NODE<T> *new_parent = node->right;

			node->right = new_parent->left;
			if (new_parent->left != __nullnode)
				new_parent->left->parent = node;
			new_parent->parent = node->parent;
			if (new_parent->parent == __nullnode)
				__root = new_parent;
			else if (new_parent->parent->left == node)
				new_parent->parent->left = new_parent;
			else
				new_parent->parent->right = new_parent;
			new_parent->left = node;
			node->parent = new_parent;
		}
		void	fix_the_three(NODE<T> *node) {
			NODE<T> *parent = __nullnode;
			NODE<T>	*G_parent = __nullnode;
			NODE<T>	*tmp = node;
			
			parent = node->parent;
			if (parent != __root)
				G_parent = parent->parent;
			else
				return ;
			while (node != __root && node != __nullnode && parent != __nullnode && parent->color == 1) { //if the parent is red and the node isn't root yet
				if (which_node(parent) == 2) { // if the parent is the left of the G_parent
					if (G_parent != __nullnode && G_parent->right != __nullnode && G_parent->right->color == 1) { //if the uncle is red
						G_parent->color = 1;
						parent->color = 0;
						G_parent->right->color = 0;
					}
					else if (G_parent != __nullnode && which_node(node) == 1 && (G_parent->right == __nullnode || G_parent->right->color == 0)) {
						left_rotation(parent);
						right_rotation(G_parent);
						node->color = 0;
						G_parent->color = 1;
					}
					else if (G_parent != __nullnode && which_node(node) == 2 && (G_parent->right == __nullnode || G_parent->right->color == 0)) {
						right_rotation(G_parent);
						parent->color = 0;
						G_parent->color = 1;
					}
				}
				if (which_node(parent) == 1) {
					if (G_parent != __nullnode && G_parent->left != __nullnode && G_parent->left->color == 1) {
						G_parent->color = 1;
						parent->color = 0;
						G_parent->left->color = 0;
						node = G_parent;
					}
					else if (G_parent != __nullnode && which_node(node) == 2 && (G_parent->left == __nullnode || G_parent->left->color == 0)) {
						right_rotation(parent);
						left_rotation(G_parent);
						node->color = 0;
						G_parent->color = 1; 
					}
					else if (G_parent != __nullnode && which_node(node) == 1 && (G_parent->left == __nullnode || G_parent->left->color == 0)) {
						left_rotation(G_parent);
						parent->color = 0;
						G_parent->color = 1; 
					}
				}
				node = G_parent;
				parent = node->parent;
				if (parent != __nullnode && parent != __root)
					G_parent = parent->parent;
				else
					break ;
			}
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