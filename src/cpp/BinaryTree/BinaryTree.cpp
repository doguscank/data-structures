#include <iostream>
#include <stdlib.h>
#include "BinaryTree.hpp"

using namespace std;

//Node class
//Constructors
template <typename T>
Node<T>::Node(T value){
	this->value = value;
	this->parent = NULL;
	this->left = NULL;
	this->right = NULL;
}

template <typename T>
Node<T>::Node(T value, Node * parent){
	this->value = value;
	this->parent = parent;
	this->left = NULL;
	this->right = NULL;
}

template <typename T>
Node<T>::Node(T value, Node * parent, Node * left){
	this->value = value;
	this->parent = parent;
	this->left = left;
	this->right = NULL;
}

template <typename T>
Node<T>::Node(T value, Node * parent, Node * left, Node * right){
	this->value = value;
	this->parent = parent;
	this->left = left;
	this->right = right;
}

//Getters
template <typename T>
T Node<T>::getValue(void){
	return this->value;
}

template <typename T>
Node<T> * Node<T>::getParent(void){
	return this->parent;
}

template <typename T>
Node<T> * Node<T>::getLeft(void){
	return this->left;
}

template <typename T>
Node<T> * Node<T>::getRight(void){
	return this->right;
}

//Setters
template <typename T>
void Node<T>::setValue(T value){
	this->value = value;
}

template <typename T>
void Node<T>::setParent(Node * parent){
	this->parent = parent;
}

template <typename T>
void Node<T>::setLeft(Node * left){
	this->left = left;
}

template <typename T>
void Node<T>::setRight(Node * right){
	this->right = right;
}

//BinaryTree class
//Constructors
template <typename T>
BinaryTree<T>::BinaryTree(void){
	this->size = 0;
	this->root = NULL;
}

template <typename T>
BinaryTree<T>::BinaryTree(Node<T> * root){
	this->size = 1;
	this->root = root;
}

//Getters
template <typename T>
BinaryTree<T>::getSize(void){
	return this->size;
}

template <typename T>
Node<T> * BinaryTree<T>::getRoot(void){
	return this->root;
}

//Functions
template <typename T>
void BinaryTree<T>::swap(Node<T> * n1, Node<T> * n2){
	if(n1 == NULL || n2 == NULL) return;
	
	T temp = n1->getValue();
	n1->setValue(n2->getValue());
	n2->setValue(temp);	
}

template <typename T>
void BinaryTree<T>::swap(int index1, int index2){
	this->swap(this->getNode(index1), this->getNode(index2));
}

template <typename T>
Node<T> * BinaryTree<T>::search(Node<T> * root, int startIndex, int targetIndex){
	if(root == NULL || targetIndex >= this->getSize()) return NULL;
	if(startIndex * 2 + 1 == targetIndex) return root->getLeft();
	else if(startIndex * 2 + 2 == targetIndex) return root->getRight();
	
	Node<T> * left = this->search(root->getLeft(), startIndex * 2 + 1, targetIndex);
	Node<T> * right = this->search(root->getRight(), startIndex * 2 + 2, targetIndex);
	
	if(right == NULL) return left;
	else return right;
}

template <typename T>
Node<T> * BinaryTree<T>::search(Node<T> * root, T key){
	if(root == NULL) return NULL;
	if(root->getLeft() != NULL)	if(root->getLeft()->getValue() == key) return root->getLeft();
	else if(root->getRight() != NULL) if(root->getRight()->getValue() == key) return root->getRight();
	
	Node<T> * left = this->search(root->getLeft(), key);
	Node<T> * right = this->search(root->getRight(), key);
	
	if(left != NULL) return left;
	else if(right != NULL) return right;
	else return NULL;
}

template <typename T>
Node<T> * BinaryTree<T>::getNode(int index){
	if(index >= this->getSize()) return NULL;
	if(index == 0) return this->root;
	
	return this->search(this->root, 0, index);
}

template <typename T>
Node<T> * BinaryTree<T>::findNode(T value){
	return this->search(this->root, value);
}

template <typename T>
void BinaryTree<T>::addNode(T value){
	Node<T> * node = (Node<T> *)malloc(sizeof(Node<T>));
	*node = Node<T>(value);
	
	this->addNode(node);
}

template <typename T>
void BinaryTree<T>::addNode(Node<T> * node){
	if(this->getSize() == 0){
		node->setParent(node);
		this->root = node;
		this->size++;
		return;
	}
	
	int parentIndex = (this->size - 1) / 2;
	Node<T> * parent = this->getNode(parentIndex);
	node->setParent(parent);
	if(this->size % 2 == 0) parent->setRight(node);
	else parent->setLeft(node);
	this->size++;
}

template <typename T>
bool BinaryTree<T>::removeNode(T value){
	if(!this->contains(value)) return false;
	
	return this->removeNode(this->findNode(value));
}

template <typename T>
bool BinaryTree<T>::removeNode(Node<T> * node){	
	if(node == NULL) return false;
		
	if(this->size - 1 == 0){
		delete(this->root);
		this->root = NULL;
	}
	else{
		Node<T> * toSwap = this->getNode(this->size - 1);
		this->swap(node, toSwap);
		
		if(toSwap == toSwap->getParent()->getLeft()) toSwap->getParent()->setLeft(NULL);
		else toSwap->getParent()->setRight(NULL);
		
		delete(toSwap);
	}
	
	this->size--;
	
	return true;
}

template <typename T>
bool BinaryTree<T>::removeNode(void){
	if(this->getSize() == 0) return false;
	
	return this->removeNode(this->getNode(this->size - 1));
}

template <typename T>
bool BinaryTree<T>::contains(T value){
	return this->findNode(value) != NULL;
}

template <typename T>
void BinaryTree<T>::printTree(void){
	if(this->size == 0){
		cout << "No nodes found in the tree!" << endl << endl;
		return;
	}
	
	int i = 0;
	Node<T> * node = (Node<T> *)malloc(sizeof(Node<T>));
	
	for(i = 0; i < this->size; i++){
		node = this->getNode(i);
		cout << "Index: " << i << " Value: " << node->getValue() << endl;
		cout << "Self: " << node << " Left: " << node->getLeft() << " Right: " << node->getRight() << endl << endl;
	}
	
	delete(node);
}

int main(){
	
	BinaryTree<int> b = BinaryTree<int>();
	b.addNode(0);
	b.addNode(1);
	b.addNode(2);
	b.addNode(3);
	b.addNode(4);
	b.addNode(5);
	b.addNode(6);
	b.addNode(7);
	b.addNode(8);
	b.addNode(9);
	
	b.printTree();
	
	cout << "After removal" << endl << endl;
	
	bool result = b.removeNode(1);
	
	cout << "result: " << result << endl << endl;
	
	b.printTree();
	
	return 1;
}
