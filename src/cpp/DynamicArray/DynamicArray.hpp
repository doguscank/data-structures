#ifndef DYNARRAY_H
#define DYNARRAY_H

#include <iostream>
#include <stdlib.h>

using namespace std;

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

template <typename T>
DynamicArray<T>::DynamicArray(int capacity){
	if(capacity < 0) throw "Invalid array capacity!";
	
	this->capacity = capacity;
	this->size = 0;
}	

template <typename T>
void DynamicArray<T>::expand(void){
	if(this->capacity == 0) this->capacity = 1;
	else this->capacity *= 2;
	
	realloc(this->arr, sizeof(T) * this->capacity);
}

template <typename T>
void DynamicArray<T>::append(T value){
	if(this->size == 0){
		this->arr = (T *)malloc(sizeof(T) * this->capacity);
	}
	
	if(this->size + 1 >= this->capacity) this->expand();
	
	this->arr[this->size] = value;
	this->size++;
}

template <typename T>
int DynamicArray<T>::indexOf(T value){
	int i;
	
	for(i = 0; i < this->size; i++){
		if(this->arr[i] == value) return i;
	}
	
	return -1;
}

template <typename T>
bool DynamicArray<T>::remove(T value){
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

template <typename T>
bool DynamicArray<T>::remove(void){
	if(this->isEmpty()){
		cout << "The list is empty!" << endl;
		return false;
	}
	
	this->arr[this->size - 1] = NULL;
	this->size--;
	return true;
}

template <typename T>
bool DynamicArray<T>::removeAtIndex(int index){
	if(index >= this->size) return false;
	
	int i;
	
	for(i = index; i < this->size; i++) this->arr[i] = this->arr[i + 1];
	
	this->arr[i] = NULL;
	this->size--;
	return true;
}

template <typename T>
bool DynamicArray<T>::isEmpty(void){
	return this->size == 0;
}

template <typename T>
bool DynamicArray<T>::contains(T value){
	return this->indexOf(value) != -1;	
}

template <typename T>
int DynamicArray<T>::getCapacity(void){
	return this->capacity;
}

template <typename T>
int DynamicArray<T>::getLength(void){
	return this->size;
}

template <typename T>
void DynamicArray<T>::printList(void){
	int i;
	
	for(i = 0; i < this->size; i++){
		cout << this->arr[i] << " ";
	}
	
	cout << endl << endl;
}

template <typename T>
T DynamicArray<T>::get(int index){
	if(index < 0 || index >= this->size){
		cout << "Invalid index!";
		return NULL;
	}
	
	return this->arr[index];
}

template <typename T>
void DynamicArray<T>::set(int index, T newValue){
	if(index < 0 || index >= this->size){
		cout << "Invalid index!";
		return;
	}

	this->arr[index] = newValue;
}

#endif