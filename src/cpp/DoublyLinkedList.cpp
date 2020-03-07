#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node {
	int value;
	struct Node * previous;
	struct Node * next;
};

typedef struct Node Node;
typedef struct Node * NodePtr;

class DoublyLinkedList{
	public:
		NodePtr head = NULL;
		
		void addNode(int value);
		bool deleteNode(int value);
		int getSize(void);
		bool contains(int value);
		bool isEmpty(void);
		void printList(void);
		
		DoublyLinkedList(){
			size = 0;
		}
		
	private:
		int size;
};

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

int DoublyLinkedList::getSize(void){
	return size;
}

bool DoublyLinkedList::contains(int value){
	NodePtr current = this->head;
	
	if(! this->isEmpty()){
		while(current != NULL){
			if(current->value == value){
				return true;
			}
			current = current->next;
		}
	}
	
	return false;
}

bool DoublyLinkedList::isEmpty(void){
	return this->getSize() == 0 ? true : false;
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

int main(){
	DoublyLinkedList dll = DoublyLinkedList();
	dll.addNode(1);
	dll.addNode(7);
	dll.addNode(3);
	dll.addNode(4);
	dll.addNode(3);	
	dll.addNode(3);
	
	dll.printList();
	
	dll.deleteNode(7);
	
	dll.printList();
	
	return 1;
}
