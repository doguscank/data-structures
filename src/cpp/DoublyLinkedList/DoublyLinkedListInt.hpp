#ifndef DLINKEDLISTINT_H
#define DLINKEDLISTINT_H

#include <iostream>
#include <stdlib.h>

class DLLNode {
	public:
		int value;
		DLLNode * previous;
		DLLNode * next;
};

typedef DLLNode * DLLNodePtr;

class DoublyLinkedListInt{
	private:
		int size;
	public:
		DLLNodePtr head = NULL;
		
		void addNode(int value);
		bool deleteNode(int value);
		bool deleteNode(void);
		int indexOf(int value);
		int getSize(void);
		bool contains(int value);
		bool isEmpty(void);
		int peek(int index);
		void printList(void);
		
		DoublyLinkedListInt(void);
};

#endif
