#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdlib.h>
#include "LinkedList.hpp"

using namespace std;

template <class T>
class Queue : public LinkedList<T>{
	private:
		int size;
	public:
		typedef typename LinkedList<T>::LLNode LLNode;
		typedef typename LinkedList<T>::LLNodePtr LLNodePtr;
		
		void offer(T value); //Add element to tail of QueueInt
		bool poll(void); //Remove first element of QueueInt
		
		Queue(void);
};

template <typename T>
Queue<T>::Queue(void){
	this->size = 0;
}

//Add node to end of the QueueInt
template <typename T>
void Queue<T>::offer(T value){
	this->addNode(value);
	this->size++;
}

//Delete first node in the QueueInt
template <typename T>
bool Queue<T>::poll(void){
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

#endif
