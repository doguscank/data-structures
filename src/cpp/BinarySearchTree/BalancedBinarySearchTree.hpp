#ifndef BALANCEDBST_H
#define BALANCEDBST_H

#include <iostream>
#include <stdlib.h>
#include "BinarySearchTree.hpp"

template <typename T>
class BBSTNode{
	private:
		//Variables
		T value;
		BBSTNode * left;
		BBSTNode * right;
		
		int bf; //Balance factor
		int height;
	public:
		//Getters
		T getValue(void);
		BBSTNode * getLeft(void);
		BBSTNode * getRight(void);
		int getBf(void);
		int getHeight(void);
		
		//Setters
		void setValue(T value);
		void setLeft(BBSTNode * node);
		void setRight(BBSTNode * node);
		void setBf(int bf);
		void setHeight(int height);
		
		//Constructors
		BBSTNode(T value) : BBSTNode(value, NULL, NULL){};
		BBSTNode(T value, BBSTNode * left, BBSTNode * right);
};

template <typename T>
class BalancedBinarySearchTree{
	private:
		//Variables
		BBSTNode<T> * root;
		int nodeCount;
		
		//Functions
		BBSTNode<T> * findMin(BBSTNode<T> * node);
		BBSTNode<T> * findMax(BBSTNode<T> * node);
		
		BBSTNode<T> * getNode(T value);
		BBSTNode<T> * addNode(BBSTNode<T> * node, T value);
		BBSTNode<T> * removeNode(BBSTNode<T> * node, T value);
		void swap(BBSTNode<T> * n1, BBSTNode<T> * n2);
		void preorderTraversal(BBSTNode<T> * root);
		void inorderTraversal(BBSTNode<T> * root);
		void postorderTraversal(BBSTNode<T> * root);
		void levelOrderTraversal(Queue< BBSTNode<T> * > * q, BBSTNode<T> * root);
		
		BBSTNode<T> * balance(BBSTNode<T> * node);
		
		BBSTNode<T> * leftLeftCase(BBSTNode<T> * node);
		BBSTNode<T> * leftRightCase(BBSTNode<T> * node);
		BBSTNode<T> * rightLeftCase(BBSTNode<T> * node);
		BBSTNode<T> * rightRightCase(BBSTNode<T> * node);
		
		BBSTNode<T> * leftRotation(BBSTNode<T> * node);
		BBSTNode<T> * rightRotation(BBSTNode<T> * node);
		void update(BBSTNode<T> * node);			
	public:
		//Variables
		
		//Getters
		BBSTNode<T> * getRoot(void);
		
		//Setters
		
		//Functions
		void addNode(T value);
		void addNode(BBSTNode<T> * node);
		bool removeNode(T value);
		bool removeNode(void);
		bool isEmpty(void);
		bool contains(T value);
		int size(void);
		int height(BBSTNode<T> * node);
		int height(void);
		void preorderTraversal(void);
		void inorderTraversal(void);
		void postorderTraversal(void);
		void levelOrderTraversal(void);
		void printTree(void);
		
		//Constructors		
		BalancedBinarySearchTree(T value);
		BalancedBinarySearchTree(BBSTNode<T> * node);
};

//Balanced BST Node
//Constructors
template <typename T>
BBSTNode<T>::BBSTNode(T value, BBSTNode<T> * left, BBSTNode<T> * right){
	this->value = value;
	this->left = left;
	this->right = right;
	this->bf = 0;
	this->height = 0;
}

//Getters
template <typename T>
T BBSTNode<T>::getValue(void){
	return this->value;
}
	
template <typename T>
BBSTNode<T> * BBSTNode<T>::getLeft(void){
	return this->left;
}
	
template <typename T>
BBSTNode<T> * BBSTNode<T>::getRight(void){
	return this->right;
}

template <typename T>
int BBSTNode<T>::getBf(void){
	return this->bf;
}

template <typename T>
int BBSTNode<T>::getHeight(void){
	return this->height;
}

//Setters
template <typename T>
void BBSTNode<T>::setValue(T value){
	this->value = value;
}
	
template <typename T>
void BBSTNode<T>::setLeft(BBSTNode<T> * node){
	this->left = node;
}
	
template <typename T>
void BBSTNode<T>::setRight(BBSTNode<T> * node){
	this->right = node;
}

template <typename T>
void BBSTNode<T>::setBf(int bf){
	this->bf = bf;
}

template <typename T>
void BBSTNode<T>::setHeight(int height){
	this->height = height;
}

//Balanced BST
//Constructors
template <typename T>
BalancedBinarySearchTree<T>::BalancedBinarySearchTree(T value){
	BBSTNode<T> * node = this->addNode(NULL, value);
	this->root = node;
	this->nodeCount = 0;
}

template <typename T>
BalancedBinarySearchTree<T>::BalancedBinarySearchTree(BBSTNode<T> * node){
	this->update(node);
	this->root = node;
	this->nodeCount = 1;
}

//Getters
template <typename T>
BBSTNode<T> * BalancedBinarySearchTree<T>::getRoot(void){
	return this->root;
}

//Private functions

template <typename T>
BBSTNode<T> * BalancedBinarySearchTree<T>::findMin(BBSTNode<T> * node){
	while(node->getLeft() != NULL) node = node->getLeft();
	return node;
}

template <typename T>
BBSTNode<T> * BalancedBinarySearchTree<T>::findMax(BBSTNode<T> * node){
	while(node->getRight() != NULL) node = node->getRight();
	return node;
}

template <typename T>
BBSTNode<T> * BalancedBinarySearchTree<T>::getNode(T value){
	BBSTNode<T> * current = this->root;
	
	while(current != NULL){
		if(current->getValue() == value) return current;
		
		if(current->getValue() > value) current = current->getRight();
		else current = current->getLeft();
	}
	
	return NULL;
}

template <typename T>
BBSTNode<T> * BalancedBinarySearchTree<T>::addNode(BBSTNode<T> * node, T value){
	if(node == NULL) return new BBSTNode<T>(value);
	
	int diff = value - node->getValue();
	
	if(diff < 0){
		node->setLeft(this->addNode(node->getLeft(), value));
	}
	else{
		node->setRight(this->addNode(node->getRight(), value));
	}
	
	update(node);
	return this->balance(node);
}

template <typename T>
BBSTNode<T> * BalancedBinarySearchTree<T>::removeNode(BBSTNode<T> * node, T value){
	if(node == NULL) return NULL;
	
	BBSTNode<T> * newNode;
	
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
			if(node->getLeft()->getHeight() > node->getRight()->getHeight()){
				newNode = this->findMax(node->getLeft());
				node->setValue(newNode->getValue());
				node->setLeft(this->removeNode(node->getLeft(), newNode->getValue()));
			}
			else{
				newNode = this->findMin(node->getRight());
				node->setValue(newNode->getValue());
				node->setRight(this->removeNode(node->getRight(), newNode->getValue()));
			}			
		}
	}
	
	this->update(node);
	return this->balance(node);
}

template <typename T>
void BalancedBinarySearchTree<T>::swap(BBSTNode<T> * n1, BBSTNode<T> * n2){
	T temp = n1->getValue();
	n1->setValue(n2->getValue());
	n2->setValue(temp);
}

template <typename T>
void BalancedBinarySearchTree<T>::preorderTraversal(BBSTNode<T> * root){
	if(root == NULL) return;
	
	cout << root->getValue() << " ";
	this->preorderTraversal(root->getLeft());
	this->preorderTraversal(root->getRight());
}

template <typename T>
void BalancedBinarySearchTree<T>::inorderTraversal(BBSTNode<T> * root){
	if(root == NULL) return;
	
	this->inorderTraversal(root->getLeft());
	cout << root->getValue() << " ";
	this->inorderTraversal(root->getRight());
}

template <typename T>
void BalancedBinarySearchTree<T>::postorderTraversal(BBSTNode<T> * root){
	if(root == NULL) return;
	
	this->postorderTraversal(root->getLeft());
	this->postorderTraversal(root->getRight());	
	cout << root->getValue() << " ";
	
}

template <typename T>
void BalancedBinarySearchTree<T>::levelOrderTraversal(Queue< BBSTNode<T> * > * q, BBSTNode<T> * root){
	if(root->getLeft() != NULL) q->offer(root->getLeft());
	if(root->getRight() != NULL) q->offer(root->getRight());
		
	cout << q->head->value->getValue() << " ";
	q->poll();
	
	if(q->head == NULL) return;
	this->levelOrderTraversal(q, q->head->value);
}

template <typename T>
BBSTNode<T> * BalancedBinarySearchTree<T>::balance(BBSTNode<T> * node){
	if(node->getBf() == -2){
		if(node->getLeft()->getBf() <= 0) return this->leftLeftCase(node);
		else return this->leftRightCase(node);
	}
	
	else if(node->getBf() == 2){
		if(node->getRight()->getBf() >= 0) return this->rightRightCase(node);
		else return this->rightLeftCase(node);
	}
	
	return node;
}

template <typename T>	
BBSTNode<T> * BalancedBinarySearchTree<T>::leftLeftCase(BBSTNode<T> * node){
	return this->rightRotation(node);
}

template <typename T>
BBSTNode<T> * BalancedBinarySearchTree<T>::leftRightCase(BBSTNode<T> * node){
	node->setLeft(this->leftRotation(node->getLeft()));
	return this->leftLeftCase(node);
}

template <typename T>
BBSTNode<T> * BalancedBinarySearchTree<T>::rightLeftCase(BBSTNode<T> * node){
	node->setRight(this->rightRotation(node->getRight()));
	return this->rightRightCase(node);
}

template <typename T>
BBSTNode<T> * BalancedBinarySearchTree<T>::rightRightCase(BBSTNode<T> * node){
	return this->leftRotation(node);
}

template <typename T>
BBSTNode<T> * BalancedBinarySearchTree<T>::leftRotation(BBSTNode<T> * node){
	BBSTNode<T> * newParent = node->getRight();
	node->setRight(newParent->getLeft());
	newParent->setLeft(node);
	this->update(node);
	this->update(newParent);
	
	return newParent;
}

template <typename T>
BBSTNode<T> * BalancedBinarySearchTree<T>::rightRotation(BBSTNode<T> * node){
	BBSTNode<T> * newParent = node->getLeft();
	node->setLeft(newParent->getRight());
	newParent->setRight(node);
	this->update(node);
	this->update(newParent);
	
	return newParent;
}

template <typename T>
void BalancedBinarySearchTree<T>::update(BBSTNode<T> * node){
	int leftH = (node->getLeft() == NULL) ? -1 : this->height(node->getLeft());
	int rightH = (node->getRight() == NULL) ? -1 : this->height(node->getRight());
	
	node->setBf(rightH - leftH);
	
	node->setHeight(MAX(leftH, rightH) + 1);
}

//Public functions
template <typename T>
void BalancedBinarySearchTree<T>::addNode(T value){
	if(this->contains(value)) return;
	
	if(value != NULL){
		this->root = this->addNode(this->root, value);
		this->nodeCount++;
	} 
}

template <typename T>
void BalancedBinarySearchTree<T>::addNode(BBSTNode<T> * node){
	if(this->contains(node->getValue())) return;
	
	if(node != NULL){
		this->root = this->addNode(this->root, node->getValue());
		this->nodeCount++;
	}
	
	free(node);
}

template <typename T>
bool BalancedBinarySearchTree<T>::removeNode(T value){
	this->root = this->removeNode(this->root, value);
	return this->root != NULL;
}

template <typename T>
bool BalancedBinarySearchTree<T>::removeNode(void){
	BBSTNode<T> * b = this->findMax(this->root);
	this->root = this->removeNode(this->root, b->getValue());
	return this->root != NULL;
}

template <typename T>
bool BalancedBinarySearchTree<T>::isEmpty(void){
	return this->root == NULL;
}

template <typename T>
bool BalancedBinarySearchTree<T>::contains(T value){
	return this->getNode(value) != NULL;
}

template <typename T>
int BalancedBinarySearchTree<T>::size(void){
	return this->nodeCount;
}

template <typename T>
int BalancedBinarySearchTree<T>::height(BBSTNode<T> * node){
	if(node == NULL) return 0;
	else return MAX(this->height(node->getLeft()), this->height(node->getRight())) + 1;
}

template <typename T>
int BalancedBinarySearchTree<T>::height(void){
	return this->height(this->root);
}

template <typename T>
void BalancedBinarySearchTree<T>::preorderTraversal(void){
	this->preorderTraversal(this->root);
	cout << endl << endl;
}

template <typename T>
void BalancedBinarySearchTree<T>::inorderTraversal(void){	
	this->inorderTraversal(this->root);
	cout << endl << endl;
}

template <typename T>
void BalancedBinarySearchTree<T>::postorderTraversal(void){
	this->postorderTraversal(this->root);
	cout << endl << endl;
}

template <typename T>
void BalancedBinarySearchTree<T>::levelOrderTraversal(void){
	Queue< BBSTNode<T> * > * q = (Queue< BBSTNode<T> * > *)malloc(sizeof(BBSTNode<T> *) * this->nodeCount);
	*q = Queue< BBSTNode<T> * >();
	q->offer(this->root);
	this->levelOrderTraversal(q, this->root);
	free(q);
	cout << endl << endl;
}

template <typename T>
void BalancedBinarySearchTree<T>::printTree(void){
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
