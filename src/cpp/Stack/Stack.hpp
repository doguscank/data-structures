#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <stdlib.h>
#include "./include/LinkedList.hpp"

using namespace std;

template <typename T>
class Stack : public LinkedList<T>{
	private:
		int size;
	public:
		typedef typename LinkedList<T>::LLNode Node;
		typedef typename LinkedList<T>::LLNodePtr NodePtr;
		
		void push(T value);
		void pop(void);
		void printList(void);
		
		Stack(void);
};

template <typename T>
Stack<T>::Stack(void){
	this->size = 0;
}

//Adds an element to the top of stack
template <typename T>
void Stack<T>::push(T value){
	this->addNode(value);
	this->size++;
}

//Removes the element on the top of stack
template <typename T>
void Stack<T>::pop(void){
	bool result = this->deleteNode();
	if(result) this->size--;
}

template <typename T>
void Stack<T>::printList(void){
	LLNodePtr current = this->head;
	
	if(this->isEmpty()){
		cout << "The list is empty.";
		return;
	}
	
	cout << "NULL";
	
	while(current != NULL){
		cout << " -> " << current->value ;
		current = current->next;
	}
	
	cout << endl << endl;
}

#endif