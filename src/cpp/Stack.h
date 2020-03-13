#include <iostream>
#include <stdlib.h>
#include "LinkedList.h"

using namespace std;

#ifndef STACK_H
#define STACK_H

class Stack : public LinkedList{
	public:
		void push(int value);
		void pop(void);
		void printList(void);
		
		Stack();	
	private:
		int size;
};

#endif
