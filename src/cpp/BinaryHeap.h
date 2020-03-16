#include <iostream>
#include <stdlib.h>
#include "DynamicArray.h"

#ifndef BINARYHEAP_H
#define BINARYHEAP_H

class BinaryHeap{
	private:
		int heapCapacity; //Capacity of heap
		int heapSize; //Number of elements in heap
		DynamicArray * heap = NULL;
		
		bool less(int index1, int index2);
	public:
		BinaryHeap(void);
		BinaryHeap(int size);
		BinaryHeap(DynamicArray * arr);
		
		void add(int value);
		bool swap(int index1, int index2); //Swaps two nodes at given indexes
		void swim(int index);
		void sink(int index);
		bool isEmpty(void);
		bool contains(int value);
		int getCapacity(void);
		int getSize(void);
		bool remove(int index);
		bool poll(void); //Removes first element
		void clear(void);
		void printList(void);		
};

#endif
