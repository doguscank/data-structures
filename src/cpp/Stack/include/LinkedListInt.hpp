#ifndef LINKEDLISTINT_H
#define LINKEDLISTINT_H

#include <iostream>
#include <stdlib.h>

class LLNode {
	public:
		int value;
		LLNode * next;
};

typedef LLNode LLNode;
typedef LLNode * LLNodePtr;

class LinkedListInt {
	private:
		int size;
	public:
		LLNodePtr head = NULL;
		
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
