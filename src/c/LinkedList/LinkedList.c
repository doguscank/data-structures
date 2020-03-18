#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

struct Node{
	int data;
	struct Node * nextPtr;
};

typedef struct Node Node;
typedef struct Node * NodePtr;

void add(int data);
int delete(int data);
void printList();
int getSize();
int isEmpty();
int contains(int data);

NodePtr head; //First element of linked list

void add(int data){
	NodePtr previous; //Previous pointer
	NodePtr current; //Current pointer
	NodePtr newNode;
	
	newNode = malloc(sizeof(Node)); //Allocate memory for new node
	newNode->data = data;
	newNode->nextPtr = NULL;
	
	//Initialize pointers
	previous = NULL;
	current = head;
	
	while(current != NULL && data > current->data){ //Find correct space to put new node
		previous = current;
		current = current->nextPtr;
	}
	
	if(previous == NULL){ //The list is empty
		newNode->nextPtr = current;
		head = newNode;
	}
	
	else{
		previous->nextPtr = newNode;
		newNode->nextPtr = current;
	}
}

int delete(int data){
	NodePtr previous; //Previous pointer
	NodePtr current; //Current pointer
	NodePtr tempPtr; //Next pointer
	
	current = head;
	
	if(current == NULL){
		printf("No nodes found!");
		return FALSE;
	}
	
	//Check if wanted value is in head node
	if(current->data == data){
		tempPtr = head;
		head = head->nextPtr;
		free(tempPtr);
		return TRUE;
	}
	
	else{
		previous = head;
		current = head->nextPtr;
		
		while(current != NULL && current->data != data){
			previous = current;
			current = current->nextPtr;
		}
		
		if(current != NULL){
			tempPtr = current;
			previous->nextPtr = current->nextPtr;
			free(tempPtr);
			return TRUE;
		}
		
		printf("Can not find node with data value %d.\n", data);
		return FALSE;
	}
}

void printList(){
	NodePtr current = head;
	
	if(head == NULL){
		printf("No nodes found.");
		return;
	}
	
	printf("The list is: \n\n");
	
	while(current != NULL){
		printf("%d -> ", current->data);
		current = current->nextPtr;
	}
	
	printf("NULL\n"); //Last element is always NULL
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

void instructions(){
	printf("Select one of the options below: \n");
	printf("1- Add a new node\n2- Remove a node\n3- Print node list\n4- Exit\n\n");
	printf("Enter your selection: ");
}

void main(){
	head = NULL;
	int selection = 0;
	int value = 0;
	
	while(selection != 4){
		instructions();
		scanf("%d", &selection);
		
		switch(selection){
			case 1:
				printf("Enter an integer value to add: ");
				scanf("%d", &value);
				add(value);
				break;
			case 2:
				printf("Enter an integer value to remove: ");
				scanf("%d", &value);
				int result = delete(value);
				
				if(result){
					printf("Succesfully removed %d.\n", value);
				}
								
				break;
			case 3:
				printList();
				break;
			default:
				printf("Invalid choice!");
				continue;
		}
		
		printf("\n");		
	}	
	
	return 0;
}
