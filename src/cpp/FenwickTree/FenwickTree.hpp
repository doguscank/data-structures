#ifndef FENWICKTREE_H
#define FENWICKTREE_H

#include <iostream>
#include <stdlib.h>

using namespace std;

class FenwickTree{
	private:
		//Variables
		long * tree;
		int size;
		
		//Functions
		int lsb(int i); //Least significant bit
		long prefixSum(int i);		
	public:
		//Getters
		long get(int index);
		
		//Setters
		void set(int index, long value);
		
		//Functions
		void add(int index, long value);
		long sum(int left, int right);
		void printList(void);
		
		//Constructors
		FenwickTree(int size);
		FenwickTree(long * values, int len);
};

#endif
