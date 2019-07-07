#pragma once
struct Node {
	Node* next;
	Node* previous;
	int value;
};
class List {

public:
	void insert_front(int);
	void insert_back(int);
	void delete_front();
	void delete_back();
	void delete_element(int);
	Node* search(int);
	int get_count();
	void print_list();
	void print_reverse();
	List();
	~List();
private:
	Node* _head;
	Node* _tail;
};