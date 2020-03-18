#include <iostream>
#include <stdlib.h>
#include "Queue.h"
#include "../LinkedList/LinkedList.h"

using namespace std;

Queue::Queue(){
	this->size = 0;
}

//Add node to end of the queue
void Queue::offer(int value){
	this->addNode(value);
}

//Delete first node in the queue
bool Queue::poll(){
	NodePtr current = this->head;
	
	if(current == NULL){
		cout << "The queue is empty!" << endl << endl;
		return false;
	}
	
	NodePtr newHead = current->next;
	this->head = newHead;
	
	free(current);
	
	return true;
}
