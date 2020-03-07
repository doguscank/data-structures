#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

struct Node {
	int value;
	struct Node * next;
};

typedef struct Node Node;
typedef struct Node * NodePtr;

class LinkedList {	
	public:
		NodePtr head = NULL;
		
		void addNode(int value);
		bool deleteNode(int value);
		int getSize(void);
		bool contains(int value);
		bool isEmpty(void);
		void printList(void);

		LinkedList(){
			size = 0;
		}
		
	private:
		int size;
};

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
			
			size--;
			
			return true;
		}
		
		previous = current;
		current = current->next;
	}
	
	return false;
}

int LinkedList::getSize(void){
	return size;
}

bool LinkedList::contains(int value){
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

bool LinkedList::isEmpty(void){
	return LinkedList::getSize() == 0 ? true : false;
}

void LinkedList::printList(void){
	NodePtr current = this->head;
		
	if(this->isEmpty()){
		printf("The list is empty");
		return;
	}
	
	while(current != NULL){
		printf("%d -> ", current->value);
		current = current->next;
	}
	
	printf("NULL\n\n");
}

int main(){
	LinkedList ll = LinkedList();
	ll.addNode(3);
	ll.addNode(5);
	ll.addNode(4);
	ll.addNode(0);
	ll.addNode(6);
	ll.addNode(7);
	
	ll.printList();
	
	ll.deleteNode(4);
	ll.deleteNode(6);
	
	ll.printList();
	
	return 0;
}
