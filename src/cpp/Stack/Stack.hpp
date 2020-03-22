#include <iostream>
#include <stdlib.h>
#include "./include/LinkedList.hpp"

#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack : public LinkedList<T>{
	private:
		int size;
	public:
		typedef typename LinkedList<T>::Node Node;
		typedef typename LinkedList<T>::NodePtr NodePtr;
		
		void push(T value);
		void pop(void);
		void printList(void);
		
		Stack(void);
};

#endif
