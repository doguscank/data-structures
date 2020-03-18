#include <iostream>
#include <stdlib.h>
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList(){
	this->size = 0;
}

//Add node to end of the list
void LinkedList::addNode(int value){
	NodePtr newNode = (NodePtr)malloc(sizeof(Node));
	newNode->value = value;
	newNode->next = NULL;
	
	size++;
	
	if(this->head == NULL){
		this->head = newNode;
		return;
	}
		
	NodePtr current = this->head;
	
	while(current->next != NULL){
		current = current->next;
	}
	
	current->next = newNode;
}

//Delete node with given value
bool LinkedList::deleteNode(int value){
	NodePtr current = this->head;
	NodePtr previous;
	
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
bool LinkedList::deleteNode(){
	NodePtr current = this->head;
	
	if(current == NULL){
		cout << "The list is empty!";
		return false;
	}
	
	NodePtr previous;
	
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
int LinkedList::indexOf(int value){
	NodePtr current = this->head;
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
int LinkedList::getSize(void){
	return size;
}

//Check if the list contains given value
bool LinkedList::contains(int value){
	return this->indexOf(value) != -1;
}

//Check if the list contains any node
bool LinkedList::isEmpty(void){
	return LinkedList::getSize() == 0;
}

//Return element in given index if exists
int LinkedList::peek(int index){
	NodePtr current = this->head;
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

void LinkedList::printList(void){
	NodePtr current = this->head;
		
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
