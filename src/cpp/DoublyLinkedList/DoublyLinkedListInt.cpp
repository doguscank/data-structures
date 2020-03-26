#include <iostream>
#include <stdlib.h>
#include "DoublyLinkedListInt.hpp"

using namespace std;

DoublyLinkedListInt::DoublyLinkedListInt(void){
	this->size = 0;
}

//Add node to end of the list
void DoublyLinkedListInt::addNode(int value){
	DLLNodePtr newNode = (DLLNodePtr)malloc(sizeof(DLLNode));
	newNode->value = value;
	newNode->previous = NULL;
	newNode->next = NULL;
	
	size++;
	
	if(this->head == NULL){
		this->head = newNode;
		return;
	}
		
	DLLNodePtr current = this->head;
	
	while(current->next != NULL){
		current = current->next;
	}
	
	newNode->previous = current;
	current->next = newNode;
}

//Delete node with given value
bool DoublyLinkedListInt::deleteNode(int value){
	DLLNodePtr current = this->head;
	DLLNodePtr previous;
	
	while(current != NULL){
		if(current->value == value){
			previous->next = current->next;
			
			if(current->next != NULL){
				current->next->previous = previous;
			}
					
			free(current);
			
			size--;
			
			return true;
		}
		
		previous = current;
		current = current->next;
	}
	
	return false;
}

//Delete last node in the list
bool DoublyLinkedListInt::deleteNode(void){
	DLLNodePtr current = this->head;
	DLLNodePtr previous;
	
	if(current == NULL){
		cout << "The list is empty!";
		return false;
	}
	
	while(current->next != NULL){
		previous = current;
		current = current->next;
	}
	
	previous->next = current->next;
	free(current);
	
	return true;
}

//Return index of node with given value
int DoublyLinkedListInt::indexOf(int value){
	DLLNodePtr current = this->head;
	int i = 0;
	
	while(current != NULL){
		if(current->value == value){
			return i;
		}
		
		i++;
		current = current->next;
	}
	
	return -1;
}

//Return size of the list
int DoublyLinkedListInt::getSize(void){
	return size;
}

//Check if the list contains given value
bool DoublyLinkedListInt::contains(int value){
	return this->indexOf(value) != -1;
}

//Check if the list contains any node
bool DoublyLinkedListInt::isEmpty(void){
	return this->getSize() == 0;
}

//Return element in given index if exists
int DoublyLinkedListInt::peek(int index){
	DLLNodePtr current = this->head;
	int i = 0;
	
	while(i < index){
		current = current->next;
		
		if(current == NULL){
			cout << "Invalid index!";
			return NULL;
		}
		
		i++;
	}
	
	return current->value;
}

void DoublyLinkedListInt::printList(void){
	DLLNodePtr current = this->head;
	DLLNodePtr last;
		
	if(this->isEmpty()){
		cout << "The list is empty.";
		return;
	}
	
	cout << "Printing list from left to right:" << endl << endl;
	
	while(current != NULL){
		cout << current->value << " -> ";
		last = current;
		current = current->next;
	}
	
	cout << "NULL" << endl << endl;
	
	cout << "Printing list from right to left:" << endl << endl;
	cout << "NULL";
	
	while(last != NULL){
		cout << " -> " << last->value;
		last = last->previous;
	}	
	
	cout << endl << endl;
}
