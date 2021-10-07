//============================================================================
// Name        : cpp_task_9.cpp
// Author      : John Doe
// Version     :
// Copyright   : Your copyright notice
//============================================================================
#include <iostream>
#include "treelib.h"

int main() {
	treelib::AVLNode *root = NULL;
	char number;
	do {
		std::cout << "\n1. Constructor" << std::endl;
		std::cout << "2. Destructor (exit program)" << std::endl;
		std::cout << "3. Add element" << std::endl;
		std::cout << "4. Remove element" << std::endl;
		std::cout << "5. Print tree" << std::endl;
		std::cout << "Select option > ";
		std::cin >> number;
		switch (number) {
		case '1':
			if (root == NULL) {
				root = treelib::constructor(root);
			}
			break;

		case '2':
			if (root != NULL) {
				treelib::destructor(root);
				return 0;
				break;
			} else {
				std::cout << "\nLaunch constructor first\n";
				break;
			}

		case '3':
			if (root != NULL) {
				treelib::add(root);
				break;
			} else {
				std::cout << "\nLaunch constructor first\n";
				break;
			}

		case '4':
			if (root != NULL) {
				treelib::del(root);
				break;
			} else {
				std::cout << "\nLaunch constructor first\n";
				break;
			}

		case '5':
			if (root != NULL) {
				treelib::print_Tree(root, 0);
				break;
			} else {
				std::cout << "\nLaunch constructor first\n";
				break;
			}

		case '0':
			break;

		default:
			std::cout << std::endl << "Command undefined\n\n";
			break;
		}
	} while (1);
}
