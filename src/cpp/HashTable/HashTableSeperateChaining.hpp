#ifndef HASHTABLE_SC_H
#define HASHTABLE_SC_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include "./include/LinkedList.hpp"

using namespace std;

template <typename K, typename V>
class Entry{
	private:
		K key;
		V value;
	public:
		//Getters
		K getKey(void);
		V getValue(void);
		
		//Setters
		bool setValue(V value);
		
		//Functions
		bool equals(Entry<K, V> * other);
		
		//Constructors
		Entry(const K key, V value);
};

template <typename K, typename V>
class HashTableSeperateChaining{
	private:
		LinkedList< Entry<K, V> * > ** map; //Hash map created with linked list array
		
		//Hash table size control variables
		int capacity;
		int size;
		int threshold; //Size threshold to expand hash map
		float loadFactor; //Multiplier to obtain threshold value		
		
		//Functions
		int hash(int value);
		int hash(string value);		
		int calculateThreshold(void);
		void expand(void);
		Entry<K, V> * getEntry(K key);
	public:		
		//Getters
		int getCapacity(void);
		int getSize(void);
		int getThreshold(void);
		
		//Setters
		
		//Functions
		void add(K key, V value);
		bool remove(K key);
		bool contains(K key);
		bool isEmpty(void);
		void printTable(void);
		
		//Constructors
		HashTableSeperateChaining(void) : HashTableSeperateChaining(8){};
		HashTableSeperateChaining(int capacity);
};

//Entry class
//Constructors
template <typename K, typename V>
Entry<K, V>::Entry(const K key, V value){
	this->key = key;
	this->value = value;
}

//Getters
template <typename K, typename V>
K Entry<K, V>::getKey(void){
	return this->key;
}

template <typename K, typename V>
V Entry<K, V>::getValue(void){
	return this->value;
}

//Setters
template <typename K, typename V>
bool Entry<K, V>::setValue(V value){
	this->value = value;
}

//Functions
template <typename K, typename V>
bool Entry<K, V>::equals(Entry<K, V> * other){
	return this->key == other->getKey() && this->value == other->getValue();
}

//Hash Table class
//Constructors
template <typename K, typename V>
HashTableSeperateChaining<K, V>::HashTableSeperateChaining(int capacity){
	if(capacity <= 0) throw "Capacity mush be a positive integer!";
	this->capacity = capacity;
	this->size = 0;
	this->loadFactor = 0.75;
	this->calculateThreshold();
	
	//Initialize pointer of linked list pointer to create a linked list array
	this->map = (LinkedList< Entry<K, V> * > **)malloc(sizeof(LinkedList< Entry<K, V> * > *) * this->capacity);
	for(int i = 0; i < this->capacity; i++){
		this->map[i] = (LinkedList< Entry<K, V> * > *)malloc(sizeof(LinkedList< Entry<K, V> * > ) * this->capacity);
		this->map[i] = new LinkedList< Entry<K, V> * >();
	} 
}

//Getters
template <typename K, typename V>
int HashTableSeperateChaining<K, V>::getCapacity(void){
	return this->capacity;
}

template <typename K, typename V>
int HashTableSeperateChaining<K, V>::getSize(void){
	return this->size;
}

template <typename K, typename V>
int HashTableSeperateChaining<K, V>::getThreshold(void){
	return this->threshold;
}

//Setters

//Private functions
template <typename K, typename V>
int HashTableSeperateChaining<K, V>::hash(int value){
	return value % this->capacity;
}

template <typename K, typename V>
int HashTableSeperateChaining<K, V>::hash(string value){
	int hashSum = 0;
	int i = 0;
	
	for(; i < value.length(); i++) hashSum += (int)value[i];
	
	return hash(hashSum);
}

template <typename K, typename V>
int HashTableSeperateChaining<K, V>::calculateThreshold(void){
	int threshold = (int)(this->loadFactor * this->capacity);
	if(threshold == 0) this->threshold = 1;
	else this->threshold = threshold;
	return this->threshold;
}

template <typename K, typename V>
void HashTableSeperateChaining<K, V>::expand(void){
	if(this->size + 1 < this->threshold) return; //Return if expanding is not needed
	
	//Create new hash table with double capacity
	HashTableSeperateChaining<int, int> * h = (HashTableSeperateChaining<int, int> *)malloc(sizeof(HashTableSeperateChaining<int, int>));
	h = new HashTableSeperateChaining<int, int>(this->capacity * 2);
	
	for(int i = 0; i < this->capacity; i++){
		for(int j = 0; j < this->map[i]->getSize(); j++){
			if(this->map[i]->peek(j) != NULL) h->add(this->map[i]->peek(j)->getKey(), this->map[i]->peek(j)->getValue());
		}
	}
	
	for(int i = 0; i < this->capacity; i++) free(this->map[i]);
	free(this->map);
	
	this->map = h->map;
	this->capacity = h->getCapacity();
	this->size = h->getSize();
	this->calculateThreshold();
}

template <typename K, typename V>
Entry<K, V> * HashTableSeperateChaining<K, V>::getEntry(K key){
	if(key == NULL) return NULL;
	
	int hash = this->hash(key);
	V * value = (V *)malloc(sizeof(V));
	
	for(int i = 0; i < this->map[hash]->getSize(); i++){
		if(this->map[hash]->peek(i)->getKey() == key){
			*value = this->map[hash]->peek(i)->getValue();
			Entry<K, V> * e = (Entry<K, V> *)malloc(sizeof(Entry<K, V>));
			*e = Entry<K, V>(key, *value);
			return e;
		}
	}
	
	free(value);
	return NULL;
}

//Public functions
template <typename K, typename V>
void HashTableSeperateChaining<K, V>::add(K key, V value){
	Entry<K, V> * e = (Entry<K, V> *)malloc(sizeof(Entry<K, V>));
	*e = Entry<K, V>(key, value);
	int hash = this->hash(key);
	this->map[hash]->addNode(e);
	this->size++;
	this->expand();
}

template <typename K, typename V>
bool HashTableSeperateChaining<K, V>::remove(K key){
	if(key == NULL) return false;
	
	int hash = this->hash(key);
	Entry<K, V> * e = (Entry<K, V> *)malloc(sizeof(Entry<K, V>));
	e = this->getEntry(key);
	
	if(e == NULL) return false;
		
	for(int i = 0; i < this->map[hash]->getSize(); i++){
		if(this->map[hash]->peek(i)->equals(e)){
			this->size--;
			return this->map[hash]->deleteAtIndex(i);
		}
	}
	
	return false;
}

template <typename K, typename V>
bool HashTableSeperateChaining<K, V>::contains(K key){
	return this->getEntry(key) != NULL;
}

template <typename K, typename V>
bool HashTableSeperateChaining<K, V>::isEmpty(void){
	return this->size == 0;
}

template <typename K, typename V>
void HashTableSeperateChaining<K, V>::printTable(void){
	for(int i = 0; i < this->capacity; i++){
		cout << "Line" << i << ": ";
		for(int j = 0; j < this->map[i]->getSize(); j++){
			if(!this->map[i]->isEmpty()) cout << this->map[i]->peek(j)->getKey() << " ";
			else cout << "NULL ";
		}
		cout << endl;
	}
	cout << endl << endl;
}

#endif
