#include <iostream>
#include <stdlib.h>

#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H

template <typename T>
class Node {
	public:
		T value;
		Node * previous;
		Node * next;
};

template <typename T>
class DoublyLinkedList{
	private:
		int size;
	public:
		typedef Node<T> Node;
		typedef Node * NodePtr;
		
		NodePtr head = NULL;
		
		void addNode(T value);
		bool deleteNode(T value);
		bool deleteNode(void);
		int indexOf(T value);
		int getSize(void);
		bool contains(T value);
		bool isEmpty(void);
		int peek(int index);
		void printList(void);
		
		DoublyLinkedList(void);
};

#endif

