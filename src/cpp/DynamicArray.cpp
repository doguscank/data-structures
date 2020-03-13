#include <iostream>
#include <stdlib.h>
#include "DynamicArray.h"

using namespace std;

DynamicArray::DynamicArray(int capacity){
	if(capacity < 0) throw "Invalid array capacity!";
	
	this->capacity = capacity;
	this->size = 0;
}

void DynamicArray::expand(void){
	if(this->capacity == 0) this->capacity = 1;
	else this->capacity *= 2;
	
	realloc(this->arr, sizeof(int) * this->capacity);
}

void DynamicArray::append(int value){
	if(this->size == 0){
		this->arr = (int *)malloc(sizeof(int) * this->capacity);
	}
	
	if(this->size + 1 >= this->capacity) this->expand();
	
	this->arr[this->size] = value;
	this->size++;
}

int DynamicArray::indexOf(int value){
	int i;
	
	for(i = 0; i < this->size; i++){
		if(this->arr[i] == value) return i;
	}
	
	return -1;
}

bool DynamicArray::remove(int value){
	int i;
	int limit = this->indexOf(value);
	
	if(limit == -1){
		cout << "No elements found with given value.";
		return false;
	}
	
	for(i = limit; i < this->size; i++){
		this->arr[i] = this->arr[i + 1];
	}
	
	this->arr[i] = NULL;
	this->size--;
	return true;
}

bool DynamicArray::remove(void){
	if(this->isEmpty()){
		cout << "The list is empty!" << endl;
		return false;
	}
	
	this->arr[this->size - 1] = NULL;
	this->size--;
	return true;
}

bool DynamicArray::isEmpty(void){
	return this->size == 0;
}

bool DynamicArray::contains(int value){
	return this->indexOf(value) != -1;	
}

int DynamicArray::getCapacity(void){
	return this->capacity;
}

int DynamicArray::getLength(void){
	return this->size;
}

void DynamicArray::printList(void){
	int i;
	
	for(i = 0; i < this->size; i++){
		cout << this->arr[i] << " ";
	}
	
	cout << endl << endl;
}

int DynamicArray::get(int index){
	if(index < 0 || index >= this->size){
		cout << "Invalid index!";
		return NULL;
	}
	
	return this->arr[index];
}

void DynamicArray::set(int index, int newValue){
	if(index < 0 || index >= this->size){
		cout << "Invalid index!";
		return;
	}

	this->arr[index] = newValue;
}
