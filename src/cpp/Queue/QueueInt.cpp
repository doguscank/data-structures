#include <iostream>
#include <stdlib.h>
#include "QueueInt.hpp"
#include "../LinkedList/LinkedListInt.hpp"

using namespace std;

QueueInt::QueueInt(){
	this->size = 0;
}

//Add node to end of the QueueInt
void QueueInt::offer(int value){
	this->addNode(value);
}

//Delete first node in the QueueInt
bool QueueInt::poll(){
	NodePtr current = this->head;
	
	if(current == NULL){
		cout << "The QueueInt is empty!" << endl << endl;
		return false;
	}
	
	NodePtr newHead = current->next;
	this->head = newHead;
	
	free(current);
	
	return true;
}
