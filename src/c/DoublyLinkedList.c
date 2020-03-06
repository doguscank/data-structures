#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

struct Node{
	int data;
	struct Node * previous;
	struct Node * next;
};

typedef struct Node Node;
typedef struct Node * NodePtr;

NodePtr head;

void add(int data);
int delete(int data);
void printList();
int getSize();
int isEmpty();
int contains(int data);

void add(int data){
	NodePtr newNode = malloc(sizeof(Node));
	newNode->previous = NULL;
	newNode->next = NULL;
	newNode->data = data;
	
	if(head == NULL){
		head = newNode;
	}
	
	else{
		NodePtr current = head;
		
		while(current->next != NULL){
			current = current->next;
		}
		
		newNode->previous = current;
		current->next = newNode;
	}
}

int delete(int data){
	NodePtr current = head;
	
	while(current != NULL){
		if(current->data == data){
			current->previous->next = current->next;
			current->next->previous = current->previous;
			free(current);
			
			printf("Deleted the node with data value %d.\n\n", data);
			
			return TRUE;
		}
		
		current = current->next;
	}
	
	printf("No node found with data value %d.\n\n", data);
	
	return FALSE;
}

void printList(){
	NodePtr current = head;
	NodePtr last;
	
	if(head == NULL){
		printf("The list is empty!");
		return;
	}
	
	printf("Printing nodes from left to right: \n\n");
	
	while(current != NULL){
		printf("%d -> ", current->data);
		last = current;
		current = current->next;
	}
	
	printf("NULL");
	
	printf("\n\nPrinting nodes from right to left: \n\n");
	
	printf("NULL");
	
	while(last != NULL){
		printf(" -> %d", last->data);
		last = last->previous;
	}
	
	printf("\n\n");
}

int getSize(){
	NodePtr current = head;
	int size = 0;
	
	while(current != NULL){
		size++;
		current = current->next;
	}
	
	return size;
}

int isEmpty(){
	if(getSize() == 0) return TRUE;
	else return FALSE;
}

int contains(int data){
	NodePtr current = head;
	
	while(current != NULL){
		if(current->data == data) return TRUE;
		
		current = current->next;
	}
	
	return FALSE;
}

void main(){
	head = NULL;
	
	add(31);
	add(46);
	add(53);
	
	printList();
	
	return 1;
}
