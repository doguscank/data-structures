#ifndef STACKINT_H
#define STACKINT_H

#include <iostream>
#include <stdlib.h>
#include "./include/LinkedListInt.hpp"

class StackInt : public LinkedListInt{
	private:
		int size;
	public:
		void push(int value);
		void pop(void);
		void printList(void);
		
		StackInt();
};

#endif
