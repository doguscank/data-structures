#include <iostream>
#include <stdlib.h>
#include "FenwickTree.hpp"

//Constructors
FenwickTree::FenwickTree(int size){
	this->tree = (long *)malloc(sizeof(long) * (size + 1));
	this->tree[0] = 0;
	this->size = size;
}

FenwickTree::FenwickTree(long * values, int len){
	this->tree = values;
	this->tree[0] = 0;
	this->size = len;
	
	int parent;
	
	for(int i = 1; i <= len; i++){
		parent = i + this->lsb(i);
		if(parent <= len) tree[parent] += tree[i];
	}
}

//Private functions
int FenwickTree::lsb(int i){
	return i & -i;
}

long FenwickTree::prefixSum(int i){
	long sum = 0;
	
	while(i != 0){
		sum += this->tree[i];
		i &= ~this->lsb(i);
	}
	
	return sum;
}

//Setters
void FenwickTree::set(int index, long value){
	this->add(index, value - this->sum(index - 1, index));
}

//Public functions
void FenwickTree::add(int index, long value){
	while(index <= this->size){
		this->tree[index] += value;
		index += this->lsb(index);
	}
}

long FenwickTree::sum(int left, int right){
	if(right < left) throw "Invalid index given!";
	return (this->prefixSum(right) - this->prefixSum(left));
}

void FenwickTree::printList(void){
	for(int i = 1; i <= this->size; i++){
		cout << "Element " << i << ": " << this->prefixSum(i) << endl;
	}
}
