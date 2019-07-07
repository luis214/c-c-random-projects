#include "List.h"
#include <iostream>

List::List() {
	_head = NULL;
	_tail = NULL;
}
void List::insert_front(int value) {
	Node* temp = new Node;
	if (_head == NULL) {
		temp->value = value;
		temp->next = NULL;
		temp->previous = NULL;
		_head = _tail = temp;
	}
	else {
		temp->value = value;
		temp->next = _head;
		temp->previous = NULL;
		_head->previous = temp;
		_head = temp;
	}
}
void List::insert_back(int value) {
	Node* temp = new Node;
	if (_head == NULL) {
		temp->value = value;
		temp->next = NULL;
		temp->previous = NULL;
		_tail = _head = temp;
	}
	else {
		temp->value = value;
		temp->next = NULL;
		temp->previous = _tail;
		_tail->next = temp;
		_tail = temp;
	}
}
void List::delete_front() {
	if (_head == NULL) {
		std::cout << "\nList is empty" << std::endl;
	}
	else if (_head == _tail)
	{
		delete _head;
		_head = _tail = NULL;
	}
	else {
		Node* temp = _head;
		_head = temp->next;
		delete temp;
		temp = NULL;
	}
}
void List::delete_back() {
	if (_tail == NULL) {
		std::cout << "\nList is empty" << std::endl;
	}
	else if (_tail == _head)
	{
		delete _tail;
		_head = _tail = NULL;
	}
	else {
		Node* temp = _tail;
		_tail = temp->previous;
		delete temp;
		temp = NULL;
	}
}
void List::delete_element(int value) {
	if (_head == NULL) {
		std::cout << "List is empty";
		return;
	}
	if (value == _head->value)
		delete_front();
	else if (value == _tail->value)
		delete_back();
	else {
		Node* temp = search(value);
		if (temp != NULL) {
			temp->previous->next = temp->next;
			temp->next->previous = temp->previous;
			delete temp;
		}
		else {
			std::cout << "Value does not exist";
		}
	}
}
Node* List::search(int value) {
	Node* temp = _head;
	Node* p = NULL;
	while (temp != NULL) {
		if (temp->value == value) {
			p = temp;
			break;
		}
		temp = temp->next;
	}
	return p;
}
int List::get_count() {
	Node* temp = _head;
	int count = 0;
	while (temp != NULL) {
		++count;
		temp = temp->next;
	}
	return count;
}
void List::print_list() {
	if (_head != NULL)
	{
		Node* temp = _head;
		while (temp != NULL) {
			std::cout << temp->value << "\n";
			temp = temp->next;
		}
	}
	else {
		std::cout << "\nList is empty\n";
	}

}
void List::print_reverse() {
	Node* temp = _tail;
	while (temp != NULL) {
		temp->value;
		temp = temp->previous;
	}
}
List::~List() {
	Node* temp = _head;
	while (temp != NULL) {
		Node* p = temp->next;
		delete temp;
		temp = p;
	}
}