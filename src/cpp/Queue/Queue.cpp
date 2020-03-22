#include <iostream>
#include <stdlib.h>
#include "Queue.hpp"
#include "./include/LinkedList.hpp"

using namespace std;

template <typename T>
Queue<T>::Queue(void){
	this->size = 0;
}

//Add node to end of the QueueInt
template <typename T>
void Queue<T>::offer(T value){
	this->addNode(value);
}

//Delete first node in the QueueInt
template <typename T>
bool Queue<T>::poll(void){
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