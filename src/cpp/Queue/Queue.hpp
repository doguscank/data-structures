#include <iostream>
#include <stdlib.h>
#include "./include/LinkedList.hpp"

#ifndef QUEUE_H
#define QUEUE_H

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
#endif
