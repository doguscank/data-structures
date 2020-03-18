#include <iostream>
#include <stdlib.h>
#include "../LinkedList/LinkedList.h"

using namespace std;

#ifndef QUEUE_H
#define QUEUE_H

class Queue : public LinkedList{
	public:
		void offer(int value); //Add element to tail of queue
		bool poll(); //Remove first element of queue
		
		Queue();	
	private:
		int size;
};

#endif
