/*
 * stack.h
 *
 *      Author: user
 */

#ifndef STACK_H_
#define STACK_H_

#include <iostream>

namespace stack {

struct NodeStack
{
	int data;
	NodeStack *next;
};

struct Stack
{
	int size;
	NodeStack *first;
	NodeStack *last;
};

void constructorS(Stack *S)
		{
	S->first = new NodeStack;
	S->first->next = NULL;
	S->last = S->first;
	S->size = 0;
}

void print(Stack *S)
		{
	NodeStack *NodeStack = S->first;
	std::cout << "\n";
	while (NodeStack->next) {
		std::cout << NodeStack->data << " ";
		NodeStack = NodeStack->next;
	}
	std::cout << "\n";
}

bool isEmpty(Stack *S)
		{
	if (S->first == S->last)
		return true;
	else
		return false;
}

void destructorS(Stack *S)
		{
	while (!isEmpty(S)) {
		S->first = S->first->next;
		S->size--;
	}
	std::cout << "\nStack is deleted\n";
}

int pop(Stack *S)
		{
	if (isEmpty(S)) {
		std::cout << "Stack is empty";
		return 0;
	} else {
		int data = S->first->data;
		S->first = S->first->next;
		S->size--;
		return data;
	}
}

void push(Stack *S)
		{
	int value;
	std::cout << "\nValue > ";
	std::cin >> value;
	NodeStack *NodeStack = new stack::NodeStack;
	NodeStack->data = value;
	NodeStack->next = S->first;
	S->first = NodeStack;
	S->size++;
	std::cout << "\nElement added\n\n";
}

int Size(Stack *S)
		{
	return S->size;
}

}

#endif /* STACK_H_ */
