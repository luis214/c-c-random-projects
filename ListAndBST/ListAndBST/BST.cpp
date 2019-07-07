#include "BST.h"
#include <iostream>

BST::BST()
{
	_root = NULL;
}
void BST::add(int value) {
	if (_root == NULL)
	{
		_root = new Leaf();
		_root->value = value;
		_root->left = NULL;
		_root->right = NULL;
	}
	else
		add_helper(value, _root);
}
void BST::add_helper(int value, Leaf*& node) {
	if (node == NULL) {
		node = new Leaf();
		node->value = value;
		node->left = node->right = NULL;
	}
	else {
		if (value <= node->value) //Not sure where to place duplicate values 
			add_helper(value, node->left);
		else if (value > node->value)
			add_helper(value, node->right);
	}
}
//Used static for now
void BST::inorder_recursive() {
	//std::cout << _root->value << " " << _root->left << " " << _root->right << "\n";
	static Leaf* node = _root;
	if (node->left != NULL)
	{
		node = node->left;
		inorder_recursive();
	}
	std::cout << node->value << "\n";
	if (node->right != NULL)
	{
		node = node->right;
		inorder_recursive();
	}

}
/*
void BST::inorder() {
	if (_root == NULL)
		std::cout << "\n\nEmpty tree\n";
	else {
		Leaf* node = _root->left;
		while (node != _root)
		{
			while (node->left != NULL)
			{
				node = node->left;
			}
			std::cout << "\n" << node->value;
			node = node->root;
		}

	}
} */

BST::~BST()
{
}

