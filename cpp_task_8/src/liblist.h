/*
 * liblist.h
 *
 *      Author: user
 */

#ifndef LIBLIST_H_
#define LIBLIST_H_

#include <iostream>

namespace liblist {

struct list {
	int field;
	struct list *next;
	struct list *prev;
};

struct list* init(int a) {
	struct list *lst;

	lst = (struct list*) malloc(sizeof(struct list));
	lst->field = a;
	lst->next = lst;
	lst->prev = lst;
	return (lst);
}

bool isEmpty(list *lst) {
	if (lst == NULL) {
		return true;
	} else {
		return false;
	}
}

struct list* addelem(list *lst, int number) {
	if (isEmpty(lst)) {

		lst = init(number);
		return lst;
	} else {
		struct list *temp, *p;
		temp = (struct list*) malloc(sizeof(list));
		p = lst->next;
		lst->next = temp;
		temp->field = number;
		temp->next = p;
		temp->prev = lst;
		p->prev = temp;
		return (temp);
	}
}

struct list* deletelem(list *lst) {
	struct list *prev, *next;
	prev = lst->prev;
	next = lst->next;
	prev->next = lst->next;
	next->prev = lst->prev;
	free(lst);
	return (prev);
}

void listprint(list *lst) {
	struct list *p;
	p = lst;
	if (lst)
		do {
			std::cout << p->field << " ";
			p = p->next;
		} while (p != lst);
}
void listprintr(list *lst) {
	struct list *p;
	p = lst;
	do {
		p = p->prev;
		std::cout << p->field << " ";
	} while (p != lst);
}
struct list* swap(struct list *lst1, struct list *lst2, struct list *head) {

	struct list *prev1, *prev2, *next1, *next2;
	prev1 = lst1->prev;
	prev2 = lst2->prev;
	next1 = lst1->next;
	next2 = lst2->next;
	if (lst2 == next1) {
		lst2->next = lst1;
		lst2->prev = prev1;
		lst1->next = next2;
		lst1->prev = lst2;
		next2->prev = lst1;
		prev1->next = lst2;
	} else if (lst1 == next2) {
		lst1->next = lst2;
		lst1->prev = prev2;
		lst2->next = next1;
		lst2->prev = lst1;
		next1->prev = lst2;
		prev2->next = lst1;
	} else {
		prev1->next = lst2;
		lst2->next = next1;
		prev2->next = lst1;
		lst1->next = next2;
		lst2->prev = prev1;
		next2->prev = lst1;
		lst1->prev = prev2;
		next1->prev = lst2;
	}
	if (lst1 == head)
		return (lst2);
	if (lst2 == head)
		return (lst1);
	return (head);
}

int length(list *lst) {
	struct list *p;
	p = lst;
	int ctd = 0;
	do {
		ctd++;
		p = p->next;
	} while (p != lst);
	return ctd;
}

struct list* destructor(list *lst) {
	int size = length(lst);
	size = size; // @suppress("Assignment to itself")
	do {
		lst = deletelem(lst);
	} while (lst->next != lst);
	lst = NULL;
	return lst;
}

struct list* getByIndex(list *lst, int index) {
	int size = length(lst);
	int tmp = 0;
	if (index > size) {
		std::cout << "\nError (size < index)\n Size is:" << size
				<< "\n";
		return NULL;
	} else if (index < 0) {
		std::cout << "\nError (index < 0)\n Size is:" << size
				<< "\n";
		return NULL;
	}

	list *p = lst;
	while (tmp < index) {
		p = p->next;
		tmp++;
	}
	return p;
}

}

#endif /* LIBLIST_H_ */
