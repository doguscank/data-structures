#ifndef QUEUEINT_H
#define QUEUEINT_H

#include <iostream>
#include <stdlib.h>
#include "./include/LinkedListInt.hpp"

class QueueInt : public LinkedListInt{
	private:
		int size;
	public:
		void offer(int value); //Add element to tail of QueueInt
		bool poll(); //Remove first element of QueueInt
		
		QueueInt();
};

#endif
