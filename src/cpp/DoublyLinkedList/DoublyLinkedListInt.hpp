#ifndef DLINKEDLISTINT_H
#define DLINKEDLISTINT_H

#include <iostream>
#include <stdlib.h>

class Node {
	public:
		int value;
		Node * previous;
		Node * next;
};

typedef Node Node;
typedef Node * NodePtr;

class DoublyLinkedListInt{
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
		
		DoublyLinkedListInt(void);
};

#endif
