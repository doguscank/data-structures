#include <iostream>
#include <stdlib.h>

using namespace std;

#ifndef DYNARRAY_H
#define DYNARRAY_H

class DynamicArray{
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
		bool isEmpty(void);
		bool contains(int value);
		int getCapacity(void);
		int getLength(void);
		void printList(void);
		int get(int index);
		void set(int index, int newValue);
		
		DynamicArray(int capacity);
};

#endif
