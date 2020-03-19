#include <iostream>
#include <stdlib.h>
#include "../LinkedList/LinkedListInt.hpp"

using namespace std;

#ifndef STACKINT_H
#define STACKINT_H

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
