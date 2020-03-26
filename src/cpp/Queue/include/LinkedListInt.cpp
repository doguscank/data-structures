#include <iostream>
#include <stdlib.h>
#include "LinkedListInt.hpp"

using namespace std;

LinkedListInt::LinkedListInt(void){
	this->size = 0;
}

//Add node to end of the list
void LinkedListInt::addNode(int value){
	LLNodePtr newNode = (LLNodePtr)malloc(sizeof(LLNode));
	newNode->value = value;
	newNode->next = NULL;
	
	size++;
	
	if(this->head == NULL){
		this->head = newNode;
		return;
	}
		
	LLNodePtr current = this->head;
	
	while(current->next != NULL){
		current = current->next;
	}
	
	current->next = newNode;
}

//Delete node with given value
bool LinkedListInt::deleteNode(int value){
	LLNodePtr current = this->head;
	LLNodePtr previous;
	
	while(current != NULL){
		if(current->value == value){
			previous->next = current->next;			
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
bool LinkedListInt::deleteNode(){
	LLNodePtr current = this->head;
	
	if(current == NULL){
		cout << "The list is empty!";
		return false;
	}
	
	LLNodePtr previous;
	
	while(current->next != NULL){
		previous = current;
		current = current->next;
	}
	
	previous->next = current->next;
	free(current);
	size--;
	
	return true;
}

//Return index of node with given value
int LinkedListInt::indexOf(int value){
	LLNodePtr current = this->head;
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
int LinkedListInt::getSize(void){
	return size;
}

//Check if the list contains given value
bool LinkedListInt::contains(int value){
	return this->indexOf(value) != -1;
}

//Check if the list contains any node
bool LinkedListInt::isEmpty(void){
	return LinkedListInt::getSize() == 0;
}

//Return element in given index if exists
int LinkedListInt::peek(int index){
	LLNodePtr current = this->head;
	int i = 0;
	
	while(i < index){
		current = current->next;
		
		if(current == NULL){
			throw "Invalid index!";
		}
		
		i++;
	}
	
	return current->value;
}

void LinkedListInt::printList(void){
	LLNodePtr current = this->head;
		
	if(this->isEmpty()){
		cout << "The list is empty.";
		return;
	}
	
	while(current != NULL){
		cout << current->value << " -> ";
		current = current->next;
	}
	
	cout << "NULL" << endl << endl;
}
