#include <iostream>
#include <stdlib.h>

using namespace std;

#ifndef DYNARRAY_H
#define DYNARRAY_H

template <class T>
class DynamicArrayTemplate{
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
		bool isEmpty(void);
		bool contains(T value);
		int getCapacity(void);
		int getLength(void);
		void printList(void);
		T get(int index);
		void set(int index, T newValue);
		
		DynamicArrayTemplate(int capacity){
			if(capacity < 0) throw "Invalid array capacity!";
			
			this->capacity = capacity;
			this->size = 0;
		}	
};

#endif