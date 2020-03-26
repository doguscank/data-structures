#include <iostream>
#include <stdlib.h>
#include "QueueInt.hpp"
#include "./include/LinkedListInt.hpp"

using namespace std;

QueueInt::QueueInt(){
	this->size = 0;
}

//Add node to end of the QueueInt
void QueueInt::offer(int value){
	this->addNode(value);
	this->size++;
}

//Delete first node in the QueueInt
bool QueueInt::poll(){
	LLNodePtr current = this->head;
	
	if(current == NULL){
		cout << "The QueueInt is empty!" << endl << endl;
		return false;
	}
	
	LLNodePtr newHead = current->next;
	this->head = newHead;
	
	free(current);
	this->size--;
	
	return true;
}