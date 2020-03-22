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
		typedef typename LinkedList<T>::Node Node;
		typedef typename LinkedList<T>::NodePtr NodePtr;
		
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
}

//Removes the element on the top of stack
template <typename T>
void Stack<T>::pop(){
	
	this->deleteNode();
}

template <typename T>
void Stack<T>::printList(void){
	NodePtr current = this->head;
	
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