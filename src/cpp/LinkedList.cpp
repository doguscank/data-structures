#include <iostream>
#include <stdlib.h>
#include "LinkedList.h"

using namespace std;

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

int LinkedList::getSize(void){
	return size;
}

bool LinkedList::contains(int value){
	return this->indexOf(value) == -1 ? false : true;
}

bool LinkedList::isEmpty(void){
	return LinkedList::getSize() == 0 ? true : false;
}

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
