#include <iostream>
#include <stdlib.h>
#include "DynamicArrayInt.hpp"

using namespace std;

DynamicArrayInt::DynamicArrayInt(int capacity){
	if(capacity < 0) throw "Invalid array capacity!";
	
	this->capacity = capacity;
	this->size = 0;
}

void DynamicArrayInt::expand(void){
	if(this->capacity == 0) this->capacity = 1;
	else this->capacity *= 2;
	
	realloc(this->arr, sizeof(int) * this->capacity);
}

void DynamicArrayInt::append(int value){
	if(this->size == 0){
		this->arr = (int *)malloc(sizeof(int) * this->capacity);
	}
	
	if(this->size + 1 >= this->capacity) this->expand();
	
	this->arr[this->size] = value;
	this->size++;
}

int DynamicArrayInt::indexOf(int value){
	int i;
	
	for(i = 0; i < this->size; i++){
		if(this->arr[i] == value) return i;
	}
	
	return -1;
}

bool DynamicArrayInt::remove(int value){
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

bool DynamicArrayInt::remove(void){
	if(this->isEmpty()){
		cout << "The list is empty!" << endl;
		return false;
	}
	
	this->arr[this->size - 1] = NULL;
	this->size--;
	return true;
}

bool DynamicArrayInt::removeAtIndex(int index){
	if(index >= this->size) return false;
	
	int i;
	
	for(i = index; i < this->size; i++) this->arr[i] = this->arr[i + 1];
	
	this->arr[i] = NULL;
	this->size--;
	return true;
}

bool DynamicArrayInt::isEmpty(void){
	return this->size == 0;
}

bool DynamicArrayInt::contains(int value){
	return this->indexOf(value) != -1;	
}

int DynamicArrayInt::getCapacity(void){
	return this->capacity;
}

int DynamicArrayInt::getSize(void){
	return this->size;
}

void DynamicArrayInt::printList(void){
	int i;
	
	for(i = 0; i < this->size; i++){
		cout << this->arr[i] << " ";
	}
	
	cout << endl << endl;
}

int DynamicArrayInt::get(int index){
	if(index < 0 || index >= this->size){
		cout << "Invalid index!";
		return NULL;
	}
	
	return this->arr[index];
}

void DynamicArrayInt::set(int index, int newValue){
	if(index < 0 || index >= this->size){
		cout << "Invalid index!";
		return;
	}

	this->arr[index] = newValue;
}
