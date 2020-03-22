#include <iostream>
#include <stdlib.h>

#ifndef BINARYTREE_H
#define BINARYTREE_H

template <typename T>
class Node{
	private:
		//Variables
		T value;
		Node * parent;
		Node * left;
		Node * right;
	public:
		//Getters
		T getValue(void);
		Node * getParent(void);
		Node * getLeft(void);
		Node * getRight(void);
		
		//Setters
		void setValue(T value);
		void setParent(Node * parent);
		void setLeft(Node * left);
		void setRight(Node * right);
		
		//Constructors
		Node(T value);
		Node(T value, Node * parent);
		Node(T value, Node * parent, Node * left);
		Node(T value, Node * parent, Node * left, Node * right);
};

template <typename T>
class BinaryTree{
	private:
		//Variables
		int size;
		Node<T> * root;
		void swap(Node<T> * n1, Node<T> * n2);
		void swap(int index1, int index2);
	public:
		//Getters
		int getSize(void);
		Node<T> * getRoot(void);
		
		//Functions
		Node<T> * search(Node<T> * root, int startIndex, int targetIndex);
		Node<T> * search(Node<T> * root, T key);
		Node<T> * getNode(int index);
		Node<T> * findNode(T value);
		void addNode(T value);
		void addNode(Node<T> * node);
		bool removeNode(T value);
		bool removeNode(Node<T> * node);
		bool removeNode(void);
		bool contains(T value);
		void printTree(void);
		
		//Constructors
		BinaryTree(void);
		BinaryTree(Node<T> * root);
};

#endif
