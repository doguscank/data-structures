#include <iostream>
#include <stdlib.h>

using namespace std;

#ifndef DLINKEDLIST_H
#define DLINKLIST_H

struct Node {
	int value;
	struct Node * previous;
	struct Node * next;
};

typedef struct Node Node;
typedef struct Node * NodePtr;

class DoublyLinkedList{
	public:
		NodePtr head = NULL;
		
		void addNode(int value);
		bool deleteNode(int value);
		int indexOf(int value);
		int getSize(void);
		bool contains(int value);
		bool isEmpty(void);
		int peek(int index);
		void printList(void);
		
		DoublyLinkedList(){
			size = 0;
		}
		
	private:
		int size;
};

#endif
