#include <iostream>
#include <stdlib.h>
#include "DoublyLinkedList.h"

using namespace std;

//Add node to end of the list
void DoublyLinkedList::addNode(int value){
	NodePtr newNode = (NodePtr)malloc(sizeof(Node));
	newNode->value = value;
	newNode->previous = NULL;
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
	
	newNode->previous = current;
	current->next = newNode;
}

//Delete node with given value
bool DoublyLinkedList::deleteNode(int value){
	NodePtr current = this->head;
	NodePtr previous;
	
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
bool DoublyLinkedList::deleteNode(){
	NodePtr current = this->head;
	NodePtr previous;
	
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
int DoublyLinkedList::indexOf(int value){
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
int DoublyLinkedList::getSize(void){
	return size;
}

//Check if the list contains given value
bool DoublyLinkedList::contains(int value){
	return this->indexOf(value) == -1 ? false : true;
}

//Check if the list contains any node
bool DoublyLinkedList::isEmpty(void){
	return this->getSize() == 0 ? true : false;
}

//Return element in given index if exists
int DoublyLinkedList::peek(int index){
	NodePtr current = this->head;
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

void DoublyLinkedList::printList(void){
	NodePtr current = this->head;
	NodePtr last;
		
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
