#include <iostream>
#include <stdlib.h>
#include "Stack.h"
#include "LinkedList.h"

using namespace std;

void Stack::push(int value){
	this->addNode(value);
}

void Stack::pop(){
	NodePtr current = this->head;
	
	if(current == NULL){
		cout << "No nodes found!" << endl << endl;
		return;
	}
	
	NodePtr previous;
	
	while(current->next != NULL){
		previous = current;
		current = current->next;
	}
	
	previous->next = current->next;
	free(current);
}

void Stack::printList(void){
	NodePtr current = this->head;
	
	if(this->isEmpty()){
		cout << "The list is empty.";
		return;
	}
	
	while(current->next != NULL){
		cout << current->value << " -> ";
		current = current->next;
	}
	
	cout << current->value << endl << endl;
}
