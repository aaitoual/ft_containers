/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_three.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 22:21:42 by aaitoual          #+#    #+#             */
/*   Updated: 2023/01/11 01:00:58 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <memory>

template<typename S>
class iterator_map;

namespace ft {
	template<typename T>
	class NODE {
		private :
			std::allocator<NODE>	alloc;
		public :
			NODE	*parent;
			NODE	*right;
			NODE	*left;
			NODE	*null_node;
			T		content;
			bool	leaf;
			bool	color; //0 black, 1 red
			NODE (T content_) : parent(NULL), right(NULL), left(NULL), color(1), content(content_), null_node(NULL), leaf(0) {}
			NODE (void) : parent(NULL), right(NULL), left(NULL), color(0), content(T()), null_node(NULL), leaf(0) {}
			T		operator *() {return content;}
			// NODE (NODE<T> & copy) : parent(NULL), right(NULL), left(NULL), color(1), content(T()) {}
			void	operator = (const NODE& copy){
				color = copy.color;
				content = copy.content;
				right = copy->right;
				left = copy->left;
				parent = copy->parent;
				null_node = NULL;
				leaf = copy.leaf;
			}
			NODE *get_next() {
				NODE	*tmp;
				NODE	*ret;
				if (right != NULL && !right->leaf) {
					tmp = right;
					ret = right;
					while (tmp != NULL && !tmp->leaf) {
						ret = tmp;
						tmp = tmp->left;
					}
					return ret;
				}
				else if (parent != NULL && parent->left == this) {
					return parent;
				}
				else if (parent != NULL && parent->right == this) {
					if (parent->parent != NULL && parent->parent->left == parent)
						return parent->parent;
					else if (!leaf)
						return right;
				}
				if (leaf)
					return parent;
				return this;
			}
			NODE *get_prev() {
				NODE	*tmp;
				NODE	*ret;
				if (left != NULL) {
					tmp = left;
					ret = left;
					while (tmp != NULL && !tmp->leaf) {
						ret = tmp;
						tmp = tmp->right;
					}
					return ret;
				}
				else if (parent != NULL && parent->right == this) {
					return parent;
				}
				else if (parent != NULL && parent->left == this) {
					if (parent->parent != NULL && parent->parent->right == parent)
						return parent->parent;
					// else {
					// 	if (__leaf_l == NULL) {
					// 		__leaf_l = alloc.allocate(1);
					// 		alloc.construct(__leaf_l, T());
					// 		__leaf_l->parent = this;
					// 		__leaf_l->color = 0;
					// 	}
					// 	return __leaf_l;
					// }
				}
				// else if (parent != NULL && this == parent->__leaf_r)
				// 	return parent;
				return this;
			}
	};
	template <typename T>
	void print_tree(ft::NODE<T> *root, ft::NODE<T> *NULL_NODE, int indent = 0);
	template <typename T>
	void	print_node(ft::NODE<T> *node) {
		if (node->left && !node->leaf->leaf)
			print_node(node->left);
		std::cout << node->content << "   " << node->color << std::endl;
		if (node->right && !node->right->leaf)
			print_node(node->right);
	}
	/////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////
	template<typename T, typename Alloc = std::allocator<NODE<T> > > class RBT {
	public :
		typedef	iterator_map<T>						iterator;
		typedef	iterator_map<const T>				const_iterator;
		NODE<T>	*__root;
		NODE<T>	*__nullnode;
		NODE<T>	*__ROOT_P;
		Alloc	__alloc_obj;

		RBT (void) : __root(NULL), __nullnode(NULL) {__ROOT_P = __alloc_obj.allocate(1); __alloc_obj.construct(__ROOT_P, T());}
		NODE<T>	*get_first() {
			NODE<T>	*ret = __root;
			NODE<T>	*tmp = __root;

			while (tmp != __nullnode && !tmp->leaf) {
				ret = tmp;
				tmp = tmp->left;
			}
			return ret;
		}
		NODE<T> *get_last() {
			NODE<T>	*ret = __root;
			NODE<T>	*tmp = __root;

			while (tmp != __nullnode) {
				ret = tmp;
				tmp = tmp->right;
			}
			return ret;
		}
		void	RBT_insert(T new_content) {
			NODE<T> *x = __root;
			NODE<T> *y = __root;
			NODE<T>	*new_node = __alloc_obj.allocate(1);
			__alloc_obj.construct(new_node, new_content);

			while (x != __nullnode && !x->leaf) {
				y = x;
				if (new_node->content < x->content)
					x = x->left;
				else
					x = x->right;
			}
			if (y == __nullnode)
			{
				__root = new_node;
				__ROOT_P->right = new_node;
				new_node->color = 0;
				new_node->right = __alloc_obj.allocate(1);
				new_node->left = __alloc_obj.allocate(1);
				__alloc_obj.construct(new_node->right, T());
				__alloc_obj.construct(new_node->left, T());
				new_node->right->leaf = 1;
				new_node->left->leaf = 1;
				new_node->right->color = 0;
				new_node->left->color = 0;
				new_node->right->parent = new_node;
				new_node->left->parent = new_node;
			}
			else {
				new_node->parent = y;
				new_node->right = __nullnode;
				new_node->left = __nullnode;
				if (new_node->content < y->content) {
					new_node->left = y->left;
					new_node->right = __alloc_obj.allocate(1);
					__alloc_obj.construct(new_node->right, T());
					new_node->right->leaf = 1;
					new_node->right->color = 0;
					y->left = new_node;
					new_node->right->parent = new_node;
					new_node->left->parent = new_node;
				}
				else {
					new_node->right = y->right;
					new_node->left = __alloc_obj.allocate(1);
					__alloc_obj.construct(new_node->left, T());
					new_node->left->leaf = 1;
					new_node->left->color = 0;
					y->right = new_node;
					new_node->right->parent = new_node;
					new_node->left->parent = new_node;
				}
				fix_the_three(new_node);
			}
			__root->color = 0;
		}
		void	RDT_insert(NODE<T> *new_node, NODE<T> *pos) {
			NODE<T> *x = pos;
			NODE<T> *y = pos;
			while (x != __nullnode) {
				y = x;
				if (which_node(x) == 1 && new_node->content < x->parent->content)
					x = x->parent;
				else if (which_node(x) == 2 && new_node->content >= x->parent->content)
					x = x->parent;
				else
					break;
			}
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
				__ROOT_P->right = new_node;
				new_node->color = 0;
				new_node->right = __alloc_obj.allocate(1);
				new_node->left = __alloc_obj.allocate(1);
				__alloc_obj.construct(new_node->right, T());
				__alloc_obj.construct(new_node->left, T());
				new_node->right->leaf = 1;
				new_node->left->leaf = 1;
				new_node->right->color = 0;
				new_node->left->color = 0;
				new_node->right->parent = new_node;
				new_node->left->parent = new_node;
			}
			else {
				new_node->parent = y;
				new_node->right = __nullnode;
				new_node->left = __nullnode;
				if (new_node->content < y->content) {
					new_node->left = y->left;
					new_node->right = __alloc_obj.allocate(1);
					__alloc_obj.construct(new_node->right, T());
					new_node->right->leaf = 1;
					new_node->right->color = 0;
					y->left = new_node;
					new_node->right->parent = new_node;
					new_node->left->parent = new_node;
				}
				else {
					new_node->right = y->right;
					new_node->left = __alloc_obj.allocate(1);
					__alloc_obj.construct(new_node->left, T());
					new_node->left->leaf = 1;
					new_node->left->color = 0;
					y->right = new_node;
					new_node->right->parent = new_node;
					new_node->left->parent = new_node;
				}
				fix_the_three(new_node);
			}
			__root->color = 0;
		}
		void	transplant(NODE<T> *parent, NODE<T> *child) {
			if (parent->parent == __nullnode) {
				__root = child;
				__ROOT_P->right = child;
			}
			else if (which_node(parent) == 2)
				parent->parent->left = child;
			else
				parent->parent->right = child;
			if (child != __nullnode)
				child->parent = parent->parent;
		}

		NODE<T>	*get_sub_child_min(int case_, NODE<T> *node) {
			NODE<T>	*child;
			NODE<T>	*ret;
			if (case_ == 1) {
				child = node->right;
				ret = node->right;
				while (child != __nullnode && !child->leaf) {
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
			// std::cout << "test : " << node->parent->parent->left->content << std::endl;
			while (node != __root && (node == __nullnode || !node->color)) {
				if (which_node(node) == 2) {
					
					sibling = node->parent->right;
					if (sibling != __nullnode && sibling->color) {
						sibling->color = 0;
						node->parent->color = 1;
						left_rotation(node->parent);
						sibling = node->parent->right;
					}
					// if ((sibling == __nullnode || !sibling->color) && (sibling->right == __nullnode || !sibling->right->color) && (sibling->left == __nullnode || !sibling->left->color)) {
					if (sibling == __nullnode || (sibling->left == __nullnode || !sibling->left->color) && (sibling->right == __nullnode || !sibling->right->color)) {
						if (sibling != __nullnode)
							sibling->color = 1;
						node = node->parent;
					}
					else {
						// if (sibling != __nullnode && !sibling->color && (sibling->right == __nullnode || !sibling->right->color) && (sibling->left != __nullnode && sibling->left->color)) {
						if (sibling != __nullnode && (sibling->right == __nullnode || !sibling->right->color)) {
							if (sibling->left != __nullnode)
								sibling->left->color = 0;
							sibling->color = 1;
							right_rotation(sibling);
							sibling = node->parent->right;
						}
						// if (sibling != __nullnode && !sibling->color && sibling->right != __nullnode && sibling->right->color) {
						if (1) {
							if (sibling != __nullnode)
								sibling->color = node->parent->color;
							node->parent->color = 0;
							if (sibling != __nullnode && sibling->right != __nullnode)
								sibling->right->color = 0;
							left_rotation(node->parent);
							node = __root;
						}
					}
				}
				//////////////////////////////////////////////////////////////
				else if (1) {
					sibling = node->parent->left;
					if (sibling != __nullnode && sibling->color) {
						sibling->color = 0;
						node->parent->color = 1;
						right_rotation(node->parent);
						sibling = node->parent->left;
					}
					// if ((sibling == __nullnode || !sibling->color) && (sibling->right == __nullnode || !sibling->right->color) && (sibling->left == __nullnode || !sibling->left->color)) {
					if (sibling == __nullnode || (sibling->right == __nullnode || !sibling->right->color) && (sibling->left == __nullnode || !sibling->left->color)) {
						if (sibling != __nullnode)
							sibling->color = 1;
						node = node->parent;
					}
					else {
						// if (sibling != __nullnode && !sibling->color && (sibling->right == __nullnode || !sibling->right->color) && (sibling->left != __nullnode && sibling->left->color)) {
						if (sibling != __nullnode && (sibling->left == __nullnode || !sibling->left->color)) {
							if (sibling->right != __nullnode)
								sibling->right->color = 0;
							sibling->color = 1;
							left_rotation(sibling);
							sibling = node->parent->left;
						}
						// if (sibling != __nullnode && !sibling->color && sibling->right != __nullnode && sibling->right->color) {
						if (1) {
							if (sibling != __nullnode)
								sibling->color = node->parent->color;
							node->parent->color = 0;
							if (sibling != __nullnode && sibling->left != __nullnode)
								sibling->left->color = 0;
							right_rotation(node->parent);
							node = __root;
						}
					}
				}
				// else if (which_leaf(node) == 2) {
				// 	sibling = node->parent->right;
				// 	if (sibling != __nullnode && sibling->color) {
				// 		sibling->color = 0;
				// 		node->parent->color = 1;
				// 		left_rotation(node->parent);
				// 		// if (node->parent->left != __nullnode)
				// 			// node = node->parent->left;
				// 		sibling = node->parent->right;
				// 	}
				// 	// if ((sibling == __nullnode || !sibling->color) && (sibling->right == __nullnode || !sibling->right->color) && (sibling->left == __nullnode || !sibling->left->color)) {
				// 	if ((sibling->left == __nullnode && !sibling->left->color) && (sibling->right == __nullnode || !sibling->right->color)) {
				// 		sibling->color = 1;
				// 		node = node->parent;
				// 	}
				// 	else {
				// 		// if (sibling != __nullnode && !sibling->color && (sibling->right == __nullnode || !sibling->right->color) && (sibling->left != __nullnode && sibling->left->color)) {
				// 		if ((sibling->right == __nullnode || !sibling->right->color)) {
				// 			if (sibling->left != __nullnode)
				// 				sibling->left->color = 0;
				// 			sibling->color = 1;
				// 			right_rotation(sibling);
				// 			sibling = node->parent->right;
				// 		}
				// 		// if (sibling != __nullnode && !sibling->color && sibling->right != __nullnode && sibling->right->color) {
				// 		if (1) {
				// 			sibling->color = node->parent->color;
				// 			node->parent->color = 0;
				// 			if (sibling->right != __nullnode)
				// 				sibling->right->color = 0;
				// 			left_rotation(node->parent);
				// 			node = __root;
				// 		}
				// 	}
				// }
				// else if (which_leaf(node) == 1) {
				// 	sibling = node->parent->left;
				// 	if (sibling != __nullnode && sibling->color) {
				// 		sibling->color = 0;
				// 		node->parent->color = 1;
				// 		right_rotation(node->parent);
				// 		sibling = node->parent->left;
				// 	}
				// 	// if ((sibling == __nullnode || !sibling->color) && (sibling->right == __nullnode || !sibling->right->color) && (sibling->left == __nullnode || !sibling->left->color)) {
				// 	if (sibling == __nullnode || (sibling->right == __nullnode || !sibling->right->color) && (sibling->left == __nullnode || !sibling->left->color)) {
				// 		if (sibling != __nullnode)
				// 			sibling->color = 1;
				// 		node = node->parent;
				// 	}
				// 	else {
				// 		// if (sibling != __nullnode && !sibling->color && (sibling->right == __nullnode || !sibling->right->color) && (sibling->left != __nullnode && sibling->left->color)) {
				// 		if (sibling != __nullnode && (sibling->left == __nullnode || !sibling->left->color)) {
				// 			sibling->right->color = 0;
				// 			sibling->color = 1;
				// 			left_rotation(sibling);
				// 			sibling = node->parent->left;
				// 		}
				// 		// if (sibling != __nullnode && !sibling->color && sibling->right != __nullnode && sibling->right->color) {
				// 		if (1) {
				// 			if (sibling != __nullnode)
				// 				sibling->color = node->parent->color;
				// 			node->parent->color = 0;
				// 			if (sibling != __nullnode && sibling->left != __nullnode)
				// 				sibling->left->color = 0;
				// 			right_rotation(node->parent);
				// 			node = __root;
				// 		}
				// 	}
				// }
			}
			if (node != __nullnode)
				node->color = 0; 
		}
		void	__delete(NODE<T> *node) {
			bool	ori_color;
			NODE<T>	*tmp_node;
			NODE<T>	*tmp_node2;

			ori_color = node->color;
			if (node->left == __nullnode || node->left->leaf) {
				tmp_node = node->right;
				// if (tmp_node == __nullnode) {
				// 	if (node->__leaf_r == NULL) {
				// 		node->__leaf_r = __alloc_obj.allocate(1);
				// 		__alloc_obj.construct(node->__leaf_r, T());
				// 		node->__leaf_r->parent = node;
				// 		node->__leaf_r->color = 0;
				// 	}
				// 	tmp_node = node->__leaf_r;
				// 	transplant(node, node->__leaf_r);
				// }
				// else
					transplant(node, node->right);
			}
			else if (node->right == __nullnode || node->left->leaf) {
				tmp_node = node->left;
				// if (tmp_node == __nullnode) {
				// 	if (node->__leaf_l == NULL) {
				// 		node->__leaf_l = __alloc_obj.allocate(1);
				// 		__alloc_obj.construct(node->__leaf_l, T());
				// 		node->__leaf_l->parent = node;
				// 		node->__leaf_l->color = 0;
				// 	}
				// 	tmp_node = node->__leaf_l;
				// 	transplant(node, node->__leaf_l);
				// }
				transplant(node, node->left);
			}
			else {
				tmp_node2 = get_sub_child_min(1, node);
 				ori_color = tmp_node2->color;
				tmp_node = tmp_node2->right;
				if (tmp_node2->parent == node) {
					// if (tmp_node != __nullnode)
						tmp_node->parent = tmp_node2;
				}
				else {
					transplant(tmp_node2, tmp_node2->right);
					tmp_node2->right = node->right;
					tmp_node2->right->parent = tmp_node2;
				}
				transplant(node, tmp_node2);
				tmp_node2->left = node->left;
				if (tmp_node2->left != __nullnode)
					tmp_node2->left->parent = tmp_node2;
				tmp_node2->color = node->color;
			}
			if (!ori_color)
				___delete_fix(tmp_node);
		}

		void	RBT_delete(NODE<T> *delete_node) {
			__delete(delete_node);
		}
		void	right_rotation(NODE<T> *node) {
			NODE<T> *new_parent = node->left;

			if (new_parent == __nullnode) {
				if (node->parent != __nullnode) {
					if (which_node(node) == 1)
						node->parent->right = new_parent;
					else if (which_node(node) == 2)
						node->parent->left = new_parent;
				}
				else
					__root = new_parent;
				return ;
			}
			node->left = new_parent->right;
			if (new_parent->right != __nullnode)
				new_parent->right->parent = node;
			new_parent->parent = node->parent;
			if (node->parent == __nullnode)
				__root = new_parent;
			else if (node->parent->right == node)
				node->parent->right = new_parent;
			else
				node->parent->left = new_parent;
			new_parent->right = node;
			node->parent = new_parent;
		}
		void	left_rotation(NODE<T> *node) {
			NODE<T> *new_parent = node->right;

			if (new_parent == __nullnode) {
				if (node->parent != __nullnode) {
					if (which_node(node) == 1)
						node->parent->left = new_parent;
					else if (which_node(node) == 2)
						node->parent->right = new_parent;
				}
				else
					__root = new_parent;
				return ;
			}
			node->right = new_parent->left;
			if (new_parent->left != __nullnode)
				new_parent->left->parent = node;
			new_parent->parent = node->parent;
			if (node->parent == __nullnode)
				__root = new_parent;
			else if (node->parent->left == node)
				node->parent->left = new_parent;
			else
				node->parent->right = new_parent;
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
				else if (which_node(parent) == 1) {
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
	template<typename T>
	int	which_node(NODE<T> *node) {
		if (node == NULL)
			return 0;
		if (node->parent->right == node)
			return 1;	
		else if (node->parent->left == node)
			return 2;	
		return 0;
	}
	template<typename T>
	int	which_leaf(NODE<T> *node) {
		if (node == NULL)
			return 0;
		if (node->parent->__leaf_r == node)
			return 1;	
		else if (node->parent->__leaf_l == node)
			return 2;	
		return 0;
	}
	template <typename T>
	void print_tree(ft::NODE<T> *root, ft::NODE<T> *NULL_NODE, int indent) {
    	if (root == NULL_NODE || root->leaf) {
    	    return;
    	}
    	print_tree(root->right, NULL_NODE, indent + 4);
    	if (indent) {
    	    std::cout << std::setw(indent) << ' ';
    	}
    	if (root->right && !root->right->leaf) std::cout << " /\n" << std::setw(indent) << ' ';
    	std::cout << root->content << " (" << (root->color ? "red" : "black") << ")\n ";
    	if (root->left && !root->left->leaf) std::cout << std::setw(indent) << ' ' << " \\\n";
    	print_tree(root->left, NULL_NODE, indent + 4);
	}
}