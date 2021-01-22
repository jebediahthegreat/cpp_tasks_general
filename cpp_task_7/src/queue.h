/*
 * queue.h
 *
 *      Author: user
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>

namespace queue {

struct NodeQueue
{
	int data;
	NodeQueue *next;
};

struct Queue
{
	int size;
	NodeQueue *first;
	NodeQueue *last;
};

void print(Queue *Q)
		{
	NodeQueue *NodeQueue = Q->first->next;
	std::cout << "\n";
	while (NodeQueue) {
		std::cout << NodeQueue->data << " ";
		NodeQueue = NodeQueue->next;
	}
	std::cout << "\n";
}

void constructorQ(Queue *Q)
		{
	Q->first = new NodeQueue;
	Q->first->next = NULL;
	Q->last = Q->first;
	Q->size = 0;
}

bool isEmpty(Queue *Q)
		{
	if (Q->first == Q->last)
		return true;
	else
		return false;
}

void destructorQ(Queue *Q)
		{
	while (!isEmpty(Q)) {
		Q->first = Q->first->next;
		Q->size--;
	}
	std::cout << "\nQueue is deleted\n";
}

int pop(Queue *Q)
		{
	if (isEmpty(Q)) {
		std::cout << "Queue is empty";
		return 0;
	} else {
		int data = Q->first->next->data;
		Q->first = Q->first->next;
		Q->size--;
		return data;
	}
}

void push(Queue *Q)
		{
	int value;
	std::cout << "\nValue > ";
	std::cin >> value;
	Q->last->next = new NodeQueue;
	Q->last = Q->last->next;
	Q->last->data = value;
	Q->last->next = NULL;
	Q->size++;
	std::cout << "\nElement added\n\n";
}

int Size(Queue *Q)
		{
	return Q->size;
}

}

#endif /* QUEUE_H_ */
