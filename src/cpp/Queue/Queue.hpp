#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdlib.h>
#include "./include/LinkedList.hpp"

using namespace std;

template <typename T>
class Queue : public LinkedList<T>{
	private:
		int size;
	public:
		typedef typename LinkedList<T>::Node Node;
		typedef typename LinkedList<T>::NodePtr NodePtr;
		
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

#endif