#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
#include <stdlib.h>
#include "./include/Queue.hpp"

#define MAX(x, y) x > y ? x : y

using namespace std;

template <typename T>
class BSTNode{
	private:
		//Variables
		T value;
		BSTNode * left;
		BSTNode * right;
	public:
		//Getters
		T getValue(void);
		BSTNode * getLeft(void);
		BSTNode * getRight(void);
		
		//Setters
		void setValue(T value);
		void setLeft(BSTNode * node);
		void setRight(BSTNode * node);
		
		//Constructors
		BSTNode(T value) : BSTNode(value, NULL, NULL){};
		BSTNode(T value, BSTNode * left, BSTNode * right);
};

template <typename T>
class BinarySearchTree{
	private:
		//Variables
		BSTNode<T> * root;
		int nodeCount;
		
		//Functions
		BSTNode<T> * findMin(BSTNode<T> * node);
		BSTNode<T> * findMax(BSTNode<T> * node);

		BSTNode<T> * getNode(T value);
		BSTNode<T> * removeNode(BSTNode<T> * node, T value);
		void swap(BSTNode<T> * n1, BSTNode<T> * n2);
		void preorderTraversal(BSTNode<T> * root);
		void inorderTraversal(BSTNode<T> * root);
		void postorderTraversal(BSTNode<T> * root);
		void levelOrderTraversal(Queue< BSTNode<T> * > * q, BSTNode<T> * root);
	public:
		//Getters
		BSTNode<T> * getRoot(void);
				
		//Functions
		void addNode(T value);
		void addNode(BSTNode<T> * node);
		bool removeNode(T value);
		bool removeNode(void);
		bool isEmpty(void);
		bool contains(T value);
		int size(void);
		int height(BSTNode<T> * node);
		int height(void);
		void preorderTraversal(void);
		void inorderTraversal(void);
		void postorderTraversal(void);
		void levelOrderTraversal(void);
		void printTree(void);
		
		//Constructors
		BinarySearchTree(T value);
		BinarySearchTree(BSTNode<T> * node);
};

//Node class
//Constructors
template <typename T>
BSTNode<T>::BSTNode(T value, BSTNode<T> * left, BSTNode<T> * right){
	this->value = value;
	this->left = left;
	this->right = right;
}
	
//Getters
template <typename T>
T BSTNode<T>::getValue(void){
	return this->value;
}
	
template <typename T>
BSTNode<T> * BSTNode<T>::getLeft(void){
	return this->left;
}
	
template <typename T>
BSTNode<T> * BSTNode<T>::getRight(void){
	return this->right;
}

//Setters
template <typename T>
void BSTNode<T>::setValue(T value){
	this->value = value;
}
	
template <typename T>
void BSTNode<T>::setLeft(BSTNode<T> * node){
	this->left = node;
}
	
template <typename T>
void BSTNode<T>::setRight(BSTNode<T> * node){
	this->right = node;
}

//Binary Search Tree class
//Constructors
template <typename T>
BinarySearchTree<T>::BinarySearchTree(T value){
	BSTNode<T> * node = (BSTNode<T> *)malloc(sizeof(BSTNode<T>));
	*node = BSTNode<T>(value);
	this->root = node;
	this->nodeCount = 0;
}

template <typename T>
BinarySearchTree<T>::BinarySearchTree(BSTNode<T> * node){
	this->root = node;
	this->nodeCount = 1;
}

//Getters
template <typename T>
BSTNode<T> * BinarySearchTree<T>::getRoot(void){
	return this->root;
}

//Functions
//Private ones
template <typename T>
BSTNode<T> * BinarySearchTree<T>::findMin(BSTNode<T> * node){
	while(node->getLeft() != NULL) node = node->getLeft();
	return node;
}

template <typename T>
BSTNode<T> * BinarySearchTree<T>::findMax(BSTNode<T> * node){
	while(node->getRight() != NULL) node = node->getRight();
	return node;
}

template <typename T>
BSTNode<T> * BinarySearchTree<T>::getNode(T value){
	BSTNode<T> * current = this->root;
	
	while(current != NULL){
		if(current->getValue() == value) return current;
		
		if(current->getValue() > value) current = current->getRight();
		else current = current->getLeft();
	}
	
	return NULL;
}

template <typename T>
BSTNode<T> * BinarySearchTree<T>::removeNode(BSTNode<T> * node, T value){
	BSTNode<T> * newNode;
	
	if(node == NULL) return NULL;
	
	if(node->getValue() < value){
		newNode = this->removeNode(node->getRight(), value);
		node->setRight(newNode);
	}	
	else if(node->getValue() > value){
		newNode = this->removeNode(node->getLeft(), value);
		node->setLeft(newNode);
	}	
	else{
		if(node->getLeft() == NULL){
			newNode = node->getRight();
			free(node);
			return newNode;
		}		
		else if(node->getRight() == NULL){
			newNode = node->getLeft();
			free(node);			
			return newNode;
		}
		else{
			newNode = this->findMin(node->getRight());
			node->setValue(newNode->getValue());
			node->setRight(this->removeNode(node->getRight(), newNode->getValue()));
		}
	}
}

template <typename T>
void BinarySearchTree<T>::swap(BSTNode<T> * n1, BSTNode<T> * n2){
	T temp = n1->getValue();
	n1->setValue(n2->getValue());
	n2->setValue(temp);
}

template <typename T>
void BinarySearchTree<T>::preorderTraversal(BSTNode<T> * root){
	if(root == NULL) return;
	
	cout << root->getValue() << " ";
	this->preorderTraversal(root->getLeft());
	this->preorderTraversal(root->getRight());
}

template <typename T>
void BinarySearchTree<T>::inorderTraversal(BSTNode<T> * root){
	if(root == NULL) return;
	
	this->inorderTraversal(root->getLeft());
	cout << root->getValue() << " ";
	this->inorderTraversal(root->getRight());
}

template <typename T>
void BinarySearchTree<T>::postorderTraversal(BSTNode<T> * root){
	if(root == NULL) return;
	
	this->postorderTraversal(root->getLeft());
	this->postorderTraversal(root->getRight());	
	cout << root->getValue() << " ";
	
}

template <typename T>
void BinarySearchTree<T>::levelOrderTraversal(Queue< BSTNode<T> * > * q, BSTNode<T> * root){
	if(root->getLeft() != NULL) q->offer(root->getLeft());
	if(root->getRight() != NULL) q->offer(root->getRight());
		
	cout << q->head->value->getValue() << " ";
	q->poll();
	
	if(q->head == NULL) return;
	this->levelOrderTraversal(q, q->head->value);
}

//Public ones
template <typename T>
void BinarySearchTree<T>::addNode(T value){
	BSTNode<T> * current = this->root;
	BSTNode<T> * previous = (BSTNode<T> *)malloc(sizeof(BSTNode<T>));
	
	while(current != NULL){
		previous = current;
		if(value >= current->getValue()) current = current->getRight();
		else current = current->getLeft();
	}
	
	BSTNode<T> * node = (BSTNode<T> *)malloc(sizeof(BSTNode<T>));
	*node = BSTNode<T>(value);
		
	if(value >= previous->getValue()) previous->setRight(node);
	else previous->setLeft(node);
	
	this->nodeCount++;
}

template <typename T>
void BinarySearchTree<T>::addNode(BSTNode<T> * node){
	if(node != NULL) this->addNode(node->getValue());
}

template <typename T>
bool BinarySearchTree<T>::removeNode(T value){
	return this->removeNode(this->root, value) != NULL;
}

template <typename T>
bool BinarySearchTree<T>::removeNode(void){
	return this->removeNode(this->findMax(this->root));
}

template <typename T>
bool BinarySearchTree<T>::isEmpty(void){
	return this->root == NULL;
}

template <typename T>
bool BinarySearchTree<T>::contains(T value){
	return this->getNode(value) != NULL;
}

template <typename T>
int BinarySearchTree<T>::size(void){
	return this->nodeCount;
}

template <typename T>
int BinarySearchTree<T>::height(BSTNode<T> * node){
	if(node == NULL) return 0;
	else return MAX(this->height(node->getLeft()), this->height(node->getRight())) + 1;
}

template <typename T>
int BinarySearchTree<T>::height(void){
	return this->height(this->root);
}

template <typename T>
void BinarySearchTree<T>::preorderTraversal(void){
	this->preorderTraversal(this->root);
	cout << endl << endl;
}

template <typename T>
void BinarySearchTree<T>::inorderTraversal(void){	
	this->inorderTraversal(this->root);
	cout << endl << endl;
}

template <typename T>
void BinarySearchTree<T>::postorderTraversal(void){
	this->postorderTraversal(this->root);
	cout << endl << endl;
}

template <typename T>
void BinarySearchTree<T>::levelOrderTraversal(void){
	Queue< BSTNode<T> * > * q = (Queue< BSTNode<T> * > *)malloc(sizeof(BSTNode<T> *) * this->nodeCount);
	*q = Queue< BSTNode<T> * >();
	q->offer(this->root);
	this->levelOrderTraversal(q, this->root);
	free(q);
	cout << endl << endl;
}

template <typename T>
void BinarySearchTree<T>::printTree(void){
	cout << "Preorder Traversal" << endl;
	this->preorderTraversal();
	cout << "Inorder Traversal" << endl;
	this->inorderTraversal();
	cout << "Postorder Traversal" << endl;
	this->postorderTraversal();
	cout << "Level-order Traversal" << endl;
	this->levelOrderTraversal();
}

#endif
