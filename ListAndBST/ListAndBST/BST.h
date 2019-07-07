#pragma once
struct Leaf {
	Leaf* left;
	Leaf* right;
	Leaf* root;
	int value;
};
class BST
{
public:
	void add(int);
	void delete_element();
	void preorder();
	void inorder();
	void postorder();
	void inorder_recursive();
	BST();
	~BST();
private:
	void add_helper(int, Leaf*&);
	Leaf* _root;
};


