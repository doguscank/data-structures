#include <iostream>
#include <stdlib.h>

#ifndef DYNARRAY_H
#define DYNARRAY_H

template <class T>
class DynamicArray{
	private:
		int capacity;
		int size;
		void expand(void);
	public:
		T * arr;
		
		void append(T value);
		int indexOf(T value);
		bool remove(T value);
		bool remove(void);
		bool removeAtIndex(int index);
		bool isEmpty(void);
		bool contains(T value);
		int getCapacity(void);
		int getLength(void);
		void printList(void);
		T get(int index);
		void set(int index, T newValue);
		
		DynamicArray(int capacity);
};

#endif
