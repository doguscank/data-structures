#include <iostream>
#include <stdlib.h>
#include "Queue.h"
#include "LinkedList.h"

using namespace std;

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
