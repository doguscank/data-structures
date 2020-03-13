#include <iostream>
#include <stdlib.h>
#include "Stack.h"
#include "LinkedList.h"

using namespace std;

Stack::Stack(){
	this->size = 0;
}

//Adds an element to the top of stack
void Stack::push(int value){
	this->addNode(value);
}

//Removes the element on the top of stack
void Stack::pop(){
	
	this->deleteNode();
}

void Stack::printList(void){
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
