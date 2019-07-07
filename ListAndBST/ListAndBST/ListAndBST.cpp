#include "List.h"
#include "BST.h"
#include <iostream>

using namespace std;

int main() {

	int yn = 1;
	int select;
	while (yn != 0) {
		cout << "Select data structure: \n\n\t1. Doubly Linked List \n\t2. BST\n\tSelect: ";
		cin >> select;

		if (select == 1) {

			//Create and populate Link List
			List* list = new List();
			for (int i = 0; i < 25; ++i)
				list->insert_front(rand());
			//Test area.
			//Type the operation(s) you want to perform on the list, i.e. list->print_reverse();


		}
		else {
			//Create and populate BST
			BST* bst = new BST();
			
				bst->add(5);
				bst->add(7);
				bst->add(3);
			//Test area.
			bst->inorder_recursive();
		}

		cout << "\n\nPress 0 to exit.. ";
		cin >> yn;
	}



	return 0;
}