#include <iostream>
#include <stdlib.h>
#include "StackInt.hpp"
#include "./include/LinkedListInt.hpp"

using namespace std;

StackInt::StackInt(void){
	this->size = 0;
}

//Adds an element to the top of stack
void StackInt::push(int value){
	this->addNode(value);
	this->size++;
}

//Removes the element on the top of stack
void StackInt::pop(){	
	bool result = this->deleteNode();
	if(result) this->size--;
}

void StackInt::printList(void){
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
