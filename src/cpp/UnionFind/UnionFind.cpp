#include <iostream>
#include <stdlib.h>
#include "UnionFind.hpp"

UnionFind::UnionFind(int size){
	if(size <= 0) throw "Size can not be <= 0";
	
	this->size_ = size;
	this->numComp = size;
	this->compSize = (int *)malloc(sizeof(int) * size);
	this->id = (int *)malloc(sizeof(int) * size);
	
	int i = 0;
	
	for(i; i < size; i++){
		this->compSize[i] = 1; //Size of each component is one
		this->id[i] = i; //Link every component to itself
	}
}

int UnionFind::find(int p){
	if(p < 0 || p >= this->size) throw "Index out of bounds.";
	
	int root = p;
	int next;
	
	//Find root of element 'p' by checking IDs
	while(root != id[root]) root = id[root];
	
	//Path compression
	while(p != root){
		next = id[p];
		id[p] = root;
		p = next;
	}
	
	return root;
}

bool UnionFind::connected(int p, int q){
	return this->find(p) == this->find(q);
}

int UnionFind::componentSize(int p){
	return this->compSize[this->find(p)];
}

int UnionFind::size(void){
	return this->size_;
}

int UnionFind::components(void){
	return this->numComp;
}

void UnionFind::unify(int p, int q){
	int root_p = this->find(p);
	int root_q = this->find(q);
	
	if(root_p == root_q) return; //Roots are already same
	
	if(this->compSize[root_p] < this->compSize[root_q]){
		this->id[root_p] = root_q;
		this->compSize[root_q] += this->compSize[root_p];
	}
	else{
		this->id[root_q] = root_p;
		this->compSize[root_p] += this->compSize[root_q];
	}
	
	this->numComp--;
}
