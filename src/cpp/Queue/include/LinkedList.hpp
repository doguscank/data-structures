#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <stdlib.h>

using namespace std;

template <typename T>
class Node {
	public:
		T value;
		Node * next;
};

template <typename T>
class LinkedList {
	private:
		int size;
	public:
		typedef Node<T> Node;
		typedef Node * NodePtr;
		
		NodePtr head = NULL;
		
		void addNode(T value);
		bool deleteNode(T value);
		bool deleteNode(void);
		int indexOf(T value);
		int getSize(void);
		bool contains(T value);
		bool isEmpty(void);
		T peek(int index);
		void printList(void);

		LinkedList(void);
};

template <typename T>
LinkedList<T>::LinkedList(void){
	this->size = 0;
}

//Add node to end of the list
template <typename T>
void LinkedList<T>::addNode(T value){
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
template <typename T>
bool LinkedList<T>::deleteNode(T value){
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
template <typename T>
bool LinkedList<T>::deleteNode(void){
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
template <typename T>
int LinkedList<T>::indexOf(T value){
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
template <typename T>
int LinkedList<T>::getSize(void){
	return size;
}

//Check if the list contains given value
template <typename T>
bool LinkedList<T>::contains(T value){
	return this->indexOf(value) != -1;
}

//Check if the list contains any node
template <typename T>
bool LinkedList<T>::isEmpty(void){
	return LinkedList::getSize() == 0;
}

//Return element in given index if exists
template <typename T>
T LinkedList<T>::peek(int index){
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

template <typename T>
void LinkedList<T>::printList(void){
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

#endif
