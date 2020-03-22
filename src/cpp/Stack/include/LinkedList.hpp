#include <iostream>
#include <stdlib.h>

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <typename T>
class Node {
	public:
		T value;
		Node * next;
};

template <typename T>
class LinkedList {
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
		T peek(int index);
		void printList(void);

		LinkedList(void);
};

#endif
