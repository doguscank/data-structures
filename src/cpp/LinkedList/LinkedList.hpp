#include <iostream>
#include <stdlib.h>

using namespace std;

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
		int peek(int index);
		void printList(void);

		LinkedList();
};

#endif
