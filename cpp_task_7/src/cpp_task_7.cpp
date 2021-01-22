//============================================================================
// Name        : cpp_task_7.cpp
// Author      : John Doe
// Version     :
// Copyright   : Your copyright notice
//============================================================================

#include <iostream>
#include "queue.h"
#include "stack.h"

int main() {

	queue::Queue Q;
	queue::constructorQ(&Q);
	char numberQueue;
	do {
		std::cout << "1. Add element" << std::endl;
		std::cout << "2. Output elements" << std::endl;
		std::cout << "3. Print top element" << std::endl;
		std::cout << "4. Print size of queue" << std::endl;
		std::cout << "5. Delete queue" << std::endl;
		std::cout << "0. Exit\n\n";
		std::cout << "Select option > ";
		std::cin >> numberQueue;
		switch (numberQueue) {
		case '1':
			queue::push(&Q);
			break;

		case '2':
			if (queue::isEmpty(&Q))
				std::cout << std::endl << "Queue is empty\n\n";
			else
				queue::print(&Q);
			break;

		case '3':
			if (queue::isEmpty(&Q))
				std::cout << std::endl << "Queue is empty\n\n";
			else {
				std::cout << "\nFirst element is: " << queue::pop(&Q) << "\n\n";
			}
			break;

		case '4':
			if (queue::isEmpty(&Q))
				std::cout << std::endl << "Queue is empty\n\n";
			else
				std::cout << "\nSize of queue: " << queue::Size(&Q) << "\n\n";
			break;

		case '5':
			if (queue::isEmpty(&Q))
				std::cout << std::endl << "Queue is empty\n\n";
			else
				queue::destructorQ(&Q);
			break;

		case '0':
			std::cout << std::endl;
			break;
		default:
			std::cout << std::endl << "Undefined command\n\n";
			break;
		}
	} while (numberQueue != '0');



	stack::Stack S;
	stack::constructorS(&S);
	char numberStack;
	do {
		std::cout << "1. Add element" << std::endl;
		std::cout << "2. Output elements" << std::endl;
		std::cout << "3. Print top element" << std::endl;
		std::cout << "4. Print stack size" << std::endl;
		std::cout << "5. Delete stack" << std::endl;
		std::cout << "0. Exit\n\n";
		std::cout << "Select option > ";
		std::cin >> numberStack;
		switch (numberStack) {
		case '1':
			stack::push(&S);
			break;

		case '2':
			if (stack::isEmpty(&S))
				std::cout << std::endl << "Stack is empty\n\n";
			else
				stack::print(&S);
			break;

		case '3':
			if (stack::isEmpty(&S))
				std::cout << std::endl << "Stack is empty\n\n";
			else {
				std::cout << "\nFirst element: " << stack::pop(&S) << "\n\n";
			}
			break;

		case '4':
			if (stack::isEmpty(&S))
				std::cout << std::endl << "Stack is empty\n\n";
			else
				std::cout << "\nSize of stack: " << stack::Size(&S) << "\n\n";
			break;

		case '5':
			if (stack::isEmpty(&S))
				std::cout << std::endl << "Stack is empty\n\n";
			else
				stack::destructorS(&S);
			break;

		case '0':
			std::cout << std::endl;
			break;
		default:
			std::cout << std::endl << "Undefined command\n\n";
			break;
		}
	} while (numberStack != '0');

	return 0;
}
