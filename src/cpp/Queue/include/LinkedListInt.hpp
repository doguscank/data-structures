#include <iostream>
#include <stdlib.h>

#ifndef LINKEDLISTINT_H
#define LINKEDLISTINT_H

class Node {
	public:
		int value;
		Node * next;
};

typedef Node Node;
typedef Node * NodePtr;

class LinkedListInt {
	private:
		int size;
	public:
		NodePtr head = NULL;
		
		void addNode(int value);
		bool deleteNode(int value);
		bool deleteNode();
		int indexOf(int value);
		int getSize(void);
		bool contains(int value);
		bool isEmpty(void);
		int peek(int index);
		void printList(void);

		LinkedListInt(void);
};

#endif
