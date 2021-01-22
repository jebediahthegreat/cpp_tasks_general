//============================================================================
// Name        : cpp_task_8.cpp
// Author      : John Doe
// Version     :
// Copyright   : Your copyright notice
//============================================================================
#include <iostream>
#include "liblist.h"

int main() {

	liblist::list *head = NULL, *tail = NULL, *p = NULL;
	char number, number1;
	int ctd, index;

	std::cout << "Input initial value:";

	ctd = 1;
	head = liblist::addelem(tail, ctd);
	tail = head;
	do {
		std::cout << "\n1. Add element" << std::endl;
		std::cout << "2. Print elements" << std::endl;
		std::cout << "3. Destroy cyclic list (end execution of program)"
				<< std::endl;
		std::cout << "4. Print list size" << std::endl;
		std::cout << "5. Eject element from list" << std::endl;
		std::cout << "6. Print value by index" << std::endl;
		std::cout << "7. Find first equal to initial" << std::endl;
		std::cout << "Select option > ";
		std::cin >> number;
		switch (number) {
		case '1':
			std::cout << "Pick element" << std::endl;
			std::cin >> ctd;
			std::cout << "1. Add an element to the beginning" << std::endl;
			std::cout << "2. Add an element to the end" << std::endl;
			std::cout << "3. Add an element by index" << std::endl;
			std::cout << "4. Add an element by pointer" << std::endl;
			std::cin >> number1;
			switch (number1) {
			case '1':
				head = liblist::addelem(tail, ctd);
				std::cout << "\nElement added to beginning\n";
				break;
			case '2':
				tail = liblist::addelem(tail, ctd);
				std::cout << "\nElement added to end\n";
				break;
			case '3':
				std::cout << "\nInput index:\n";
				std::cin >> index;
				p = liblist::getByIndex(head, index);
				liblist::addelem(p, ctd);
				std::cout << "\nElement added by index\n";
				break;
			case '4':
				index = 1;
				std::cout
						<< "\nAdding after pointer\n";
				liblist::addelem(head, ctd);
				std::cout << "\nElement added after pointer on beginning\n";
				break;
			default:
				std::cout << std::endl << "Command undefined\n\n";
				break;
			}
			break;

		case '2':
			if (liblist::isEmpty(head))
				std::cout << std::endl << "List is empty\n\n";
			else
				liblist::listprint(head);
			break;

		case '3':
			if (liblist::isEmpty(head))
				std::cout << std::endl << "List is empty\n\n";
			else {
				head = liblist::destructor(tail);
				std::cout << "List has been deleted\n\n";
			}
			break;

		case '4':
			if (liblist::isEmpty(head))
				std::cout << std::endl << "List is empty\n\n";
			else
				std::cout << "\nList size: " << liblist::length(head) << "\n\n";
			break;

		case '5':
			if (liblist::isEmpty(head))
				std::cout << std::endl << "List is empty\n\n";
			else
				std::cout << "1. Eject element from the beginning" << std::endl;
			std::cout << "2. Eject element from the end" << std::endl;
			std::cout << "3. Eject element by index" << std::endl;
			std::cout << "4. Eject element by pointer" << std::endl;
			std::cin >> number1;
			switch (number1) {
			case '1':
				head = liblist::deletelem(head);
				std::cout << "\nElement ejected from beginning\n";
				break;
			case '2':
				tail = liblist::deletelem(tail);
				std::cout << "\nElement ejected from end\n";
				break;
			case '3':
				std::cout << "\nInput index:\n";
				std::cin >> index;
				p = liblist::getByIndex(head, index);
				liblist::deletelem(p);
				std::cout << "\nElement ejected by index\n";
				break;
			case '4':
				index = 1;
				std::cout
						<< "\nEjecting after pointer\n";
				liblist::deletelem(head);
				std::cout << "\nEjected after pointer to begining\n";
				break;
			default:
				std::cout << std::endl << "Command undefined\n\n";
				break;
			}
			break;

		case '6':
			if (liblist::isEmpty(head))
				std::cout << std::endl << "List is empty\n\n";
			else {
				std::cout << "\nInput index:";
				std::cin >> index;
				if (index + 1 > liblist::length(head)) {
					std::cout << "\nValue is higher than the length of the list\n";
					break;
				}
				p = liblist::getByIndex(head, index);
				if (p) {
					std::cout << "\nValue:" << p->field << "\n";
				} else {
					std::cout << "\nSomething went wrong, try again\n";
					break;
				}
			}
			break;

		case '7':
			p = head;
			std::cout << "\nInput initial value:\n";
			std::cin >> ctd;
			index = -1;
			do {

				if (p->field == ctd) {
					index = liblist::length(head) - liblist::length(p);
				}
			} while (p != tail->next);
			if (index == -1) {
				std::cout << "\nNo such value\n";
			} else {
				std::cout << "\n" << index << "\n";
			}
			break;

		case '0':
			break;

		default:
			std::cout << std::endl << "Command undefined\n\n";
			break;
		}
	} while (number != '3');

}
