#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H

#include <iostream>
#include <stdlib.h>

using namespace std;

template <typename T>
class DLLNode {
	public:
		T value;
		DLLNode * previous;
		DLLNode * next;
};

template <typename T>
class DoublyLinkedList{
	private:
		int size;
	public:
		typedef DLLNode<T> DLLNode;
		typedef DLLNode * DLLNodePtr;
		
		DLLNodePtr head = NULL;
		
		void addNode(T value);
		bool deleteNode(T value);
		bool deleteNode(void);
		int indexOf(T value);
		int getSize(void);
		bool contains(T value);
		bool isEmpty(void);
		int peek(int index);
		void printList(void);
		
		DoublyLinkedList(void);
};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(void){
	this->size = 0;
}

//Add node to end of the list
template <typename T>
void DoublyLinkedList<T>::addNode(T value){
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
template <typename T>
bool DoublyLinkedList<T>::deleteNode(T value){
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
template <typename T>
bool DoublyLinkedList<T>::deleteNode(void){
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
template <typename T>
int DoublyLinkedList<T>::indexOf(T value){
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
template <typename T>
int DoublyLinkedList<T>::getSize(void){
	return size;
}

//Check if the list contains given value
template <typename T>
bool DoublyLinkedList<T>::contains(T value){
	return this->indexOf(value) != -1;
}

//Check if the list contains any node
template <typename T>
bool DoublyLinkedList<T>::isEmpty(void){
	return this->getSize() == 0;
}

//Return element in given index if exists
template <typename T>
int DoublyLinkedList<T>::peek(int index){
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

template <typename T>
void DoublyLinkedList<T>::printList(void){
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

#endif