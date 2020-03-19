#include <iostream>
#include <stdlib.h>
#include "StackInt.hpp"
#include "../LinkedList/LinkedListInt.hpp"

using namespace std;

StackInt::StackInt(){
	this->size = 0;
}

//Adds an element to the top of stack
void StackInt::push(int value){
	this->addNode(value);
}

//Removes the element on the top of stack
void StackInt::pop(){
	
	this->deleteNode();
}

void StackInt::printList(void){
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
}
