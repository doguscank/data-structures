#ifndef DYNARRAYINT_H
#define DYNARRAYINT_H

#include <iostream>
#include <stdlib.h>

class DynamicArrayInt{
	private:
		int capacity;
		int size;
		void expand(void);
	public:
		int * arr;
		
		void append(int value);
		int indexOf(int value);
		bool remove(int value);
		bool remove(void);
		bool removeAtIndex(int index);
		bool isEmpty(void);
		bool contains(int value);
		int getCapacity(void);
		int getSize(void);
		void printList(void);
		int get(int index);
		void set(int index, int newValue);
		
		DynamicArrayInt(int capacity);
};

#endif
