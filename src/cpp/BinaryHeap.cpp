#include <iostream>
#include <stdlib.h>
#include "BinaryHeap.h"
#include "DynamicArray.h"

#define MAX(i, j) i > j ? i : j

BinaryHeap::BinaryHeap(void){
	this->heapCapacity = 1;
	this->heapSize = 0;
	DynamicArray d = DynamicArray(this->heapCapacity);
	this->heap = &d;
}

BinaryHeap::BinaryHeap(int size){
	this->heapCapacity = size;
	this->heapSize = 0;
	DynamicArray d = DynamicArray(this->heapCapacity);
	this->heap = &d;
}

BinaryHeap::BinaryHeap(DynamicArray * arr){
	this->heapCapacity = arr->getCapacity();
	this->heapSize = arr->getSize();
	heap = arr;
	
	int i;
	
	for(i = MAX(0, (this->heapSize / 2) - 1); i >= 0; i--) this->sink(i);
}

bool BinaryHeap::less(int index1, int index2){
	return this->heap->arr[index1] < this->heap->arr[index2];
}

void BinaryHeap::add(int value){
	this->heap->append(value);
	this->heapSize++;
	
	if(this->heapSize > 1){
		int current = this->heapSize - 1;
		int parent = (current * 2) + 1;
		
		if(this->less(current, parent)){
			this->swim(current);
		}
	}
}

bool BinaryHeap::swap(int index1, int index2){
	if(index1 == index2) return false;
	if(index1 >= this->heapSize || index2 >= this->heapSize) return false;
	
	int temp = this->heap->arr[index2];
	this->heap->arr[index2] = this->heap->arr[index1];
	this->heap->arr[index1] = temp;
		
	return true;
}

void BinaryHeap::swim(int index){
	if(this->isEmpty()) return;
	if(index < 0 || index > this->heapSize) return;
	
	int current = index;
	int parent = (current - 1) / 2;
		
	while(current > 0 && this->less(current, parent)){
		this->swap(parent, current);
		current = parent;
		parent = (current - 1) / 2;
	}
}

void BinaryHeap::sink(int index){
	int current = index;
	int left;
	int right;
	int smallest;
	
	while(true){
		left = (current * 2) + 1;		
		right = (current * 2) + 2;
		smallest = left;
		
		if(right < this->heapSize && this->less(right, left)) smallest = right;
		if(left >= this->heapSize || this->less(current, smallest)) return;
		
		this->swap(smallest, current);
		current = smallest;
	}
}

bool BinaryHeap::isEmpty(void){
	return this->heapSize == 0;
}

bool BinaryHeap::contains(int value){
	return this->heap->indexOf(value) != -1;
}

int BinaryHeap::getCapacity(void){
	return this->heapCapacity;
}

int BinaryHeap::getSize(void){
	return this->heapSize;
}

bool BinaryHeap::remove(int index){
	this->heap->removeAtIndex(index);
}

bool BinaryHeap::poll(void){
	if(this->isEmpty()) return false;
	
	this->swap(0, this->heapSize - 1);
	this->remove(this->heapSize - 1);
	this->sink(0);
	this->heapSize--;
	
	return true;
}

void BinaryHeap::clear(void){
	free(this->heap);
	
	DynamicArray d = DynamicArray(1);
	
	this->heap = &d;
	this->heapCapacity = 1;
	this->heapSize = 0;
}

void BinaryHeap::printList(void){
	this->heap->printList();
}
