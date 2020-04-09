#ifndef HASHTABLE_OA_H
#define HASHTABLE_OA_H

#include <iostream>
#include <stdlib.h>
#include <tr1/functional>
#include "./include/DynamicArray.hpp"

#define DEFAULT_CAPACITY 7
#define DEFAULT_LOAD_FACTOR 0.6
#define CONST_MULTIPLIER 17

using namespace std;

template <typename K, typename V>
class HashTableOpenAddressing{
	private:
		//Variables
		int capacity;
		int size;
		int usedBuckets;
		int threshold;
		float loadFactor;
		
		K * TOMBSTONE;
		
		//Key and value arrays
		DynamicArray<K *> * keys;
		DynamicArray<V *> * values;
		
		//Functions
		int normalizeIndex(int keyHash);
		void resize(void);
		int adjustCapacity(void);
		int recalculateThreshold(void);
		int gcd(int a, int b);
		int probe(int x);
	public:
		//Setters
		
		//Getters
		V * getValue(K * key); //Asserting given key references to a non-NULL valued element
		V * get(K * key);
		int getCapacity(void);
		int getSize(void);
		int getUsedBuckets(void);
		int getThreshold(void);
		float getLoadFactor(void);
		
		//Functions
		tr1::hash<K *> getHash;
		
		void add(K * key, V * value);
		void append(K * key, V * value);
		void put(K * key, V * value);
		void insert(K * key, V * value);
		bool remove(K * key);
		bool deleteItem(K * key);
		bool isEmpty(void);
		bool contains(K * key);
		void printTable(void);
		
		//Constructors
		HashTableOpenAddressing(int capacity, float loadFactor);
		HashTableOpenAddressing(int capacity) : HashTableOpenAddressing(capacity, DEFAULT_LOAD_FACTOR){};
		HashTableOpenAddressing(void) : HashTableOpenAddressing(DEFAULT_CAPACITY, DEFAULT_LOAD_FACTOR){};
};

//Constructors
template <typename K, typename V>
HashTableOpenAddressing<K, V>::HashTableOpenAddressing(int capacity, float loadFactor){
	if(capacity < DEFAULT_CAPACITY) capacity = DEFAULT_CAPACITY;
	this->capacity = capacity;
	this->size = this->usedBuckets = 0;
	this->loadFactor = loadFactor;
	this->threshold = this->recalculateThreshold();
	
	this->keys = new DynamicArray<K *>(this->capacity);	
	this->values = new DynamicArray<V *>(this->capacity);
	
	this->TOMBSTONE = (K *)malloc(sizeof(K));
}

//Setters

//Getters
template <typename K, typename V>
V * HashTableOpenAddressing<K, V>::getValue(K * key){
	const int offset = this->normalizeIndex(getHash(key));
	
	for(int i = offset, x = 1, j = -1; ; i = this->normalizeIndex(offset + this->probe(x++))){
		if(this->keys->get(i) == NULL) return NULL;
		else if(this->keys->get(i) == this->TOMBSTONE) continue;
		else if(this->keys->get(i) == key) return this->values->get(i);
	}
}

template <typename K, typename V>
V * HashTableOpenAddressing<K, V>::get(K * key){
	return this->getValue(key);
}

template <typename K, typename V>
int HashTableOpenAddressing<K, V>::getCapacity(void){
	return this->capacity;
}

template <typename K, typename V>
int HashTableOpenAddressing<K, V>::getSize(void){
	return this->size;
}

template <typename K, typename V>
int HashTableOpenAddressing<K, V>::getUsedBuckets(void){
	return this->usedBuckets;
}

template <typename K, typename V>
int HashTableOpenAddressing<K, V>::getThreshold(void){
	return this->threshold;
}

template <typename K, typename V>
float HashTableOpenAddressing<K, V>::getLoadFactor(void){
	return this->loadFactor;
}

//Private functions
template <typename K, typename V>
int HashTableOpenAddressing<K, V>::normalizeIndex(int keyHash){
	return keyHash % this->capacity;
}

template <typename K, typename V>
void HashTableOpenAddressing<K, V>::resize(void){		
	DynamicArray<K *> * oldKeys = new DynamicArray<K *>(this->capacity);
	*oldKeys = *this->keys;
	DynamicArray<V *> * oldValues = new DynamicArray<V *>(this->capacity);
	*oldValues = *this->values;
	
	this->capacity *= 2;
	this->recalculateThreshold();
	
	this->keys = new DynamicArray<K *>(this->capacity);
	this->values = new DynamicArray<V *>(this->capacity);
	
	for(int i = 0; i < oldValues->getCapacity(); i++){
		this->add(oldKeys->get(i), oldValues->get(i));
	}
}

template <typename K, typename V>
int HashTableOpenAddressing<K, V>::adjustCapacity(void){
	int newCapacity = this->capacity;
	while(this->gcd(newCapacity, this->capacity) != 1) newCapacity++;
	return newCapacity;
}

template <typename K, typename V>
int HashTableOpenAddressing<K, V>::recalculateThreshold(void){
	this->threshold = (int)(this->loadFactor * this->capacity);
	return this->threshold;
}

template <typename K, typename V>
int HashTableOpenAddressing<K, V>::gcd(int a, int b){
	if(b == 1) return a;
	return(b, a % b);
}

template <typename K, typename V>
int HashTableOpenAddressing<K, V>::probe(int x){
	return CONST_MULTIPLIER * x;
}

//Public functions
template <typename K, typename V>
void HashTableOpenAddressing<K, V>::add(K * key, V * value){
	if(key == NULL) return;
	if(this->usedBuckets >= this->threshold) this->resize();
	
	const int offset = this->normalizeIndex(getHash(key));
	
	for(int i = offset, x = 1, j = -1; ; i = this->normalizeIndex(offset + this->probe(x++))){		
		if(this->keys->get(i) != NULL){
			if(*key == *this->keys->get(i)){
				if(j == -1){
					this->values->set(i, value);
				}
				else{
					this->keys->set(j, key);
					this->values->set(j, value);
					this->keys->set(i, TOMBSTONE);
					this->values->set(i, NULL);				
				}
				return;
			}			
		}
		else if(this->keys->get(i) == NULL){
			if(j == -1){
				this->keys->set(i, key);
				this->values->set(i, value);
				this->size++;
				this->usedBuckets++;
			}
			else{
				this->keys->set(j, key);
				this->values->set(j, value);
				this->size++;
			}
			return;
		}
		else if(this->keys->get(i) == this->TOMBSTONE) if(j == -1) j = i;
	}
}

template <typename K, typename V>
void HashTableOpenAddressing<K, V>::append(K * key, V * value){
	this->add(key, value);
}

template <typename K, typename V>
void HashTableOpenAddressing<K, V>::put(K * key, V * value){
	this->add(key, value);
}

template <typename K, typename V>
void HashTableOpenAddressing<K, V>::insert(K * key, V * value){
	this->add(key, value);
}

template <typename K, typename V>
bool HashTableOpenAddressing<K, V>::remove(K * key){
	if(key == NULL) return false;
	
	const int offset = this->normalizeIndex(getHash(key));
	
	for(int i = offset, x = 1, j = -1; x < this->capacity; i = this->normalizeIndex(offset + this->probe(x++))){	
		if(this->keys->get(i) == this->TOMBSTONE) continue;	
		else if(this->keys->get(i) == NULL) return false;
		else if(this->keys->get(i) == key){
			this->keys->set(i, this->TOMBSTONE);
			this->values->set(i, NULL);
			this->size--;
			return true;
		}		
	}
	
	return false;
}

template <typename K, typename V>
bool HashTableOpenAddressing<K, V>::deleteItem(K * key){
	return this->remove(key);
}

template <typename K, typename V>
bool HashTableOpenAddressing<K, V>::isEmpty(void){
	return this->size == 0;
}

template <typename K, typename V>
bool HashTableOpenAddressing<K, V>::contains(K * key){
	if(key == NULL) return false;
	
	const int offset = this->normalizeIndex(getHash(key));
	
	for(int i = offset, x = 1, j = -1; x < this->capacity; i = this->normalizeIndex(offset + this->probe(x++))){		
		if(this->keys->get(i) == NULL) return false;
		else if(this->keys->get(i) == key) return true;
	}
	
	return false;
}

template <typename K, typename V>
void HashTableOpenAddressing<K, V>::printTable(void){
	for(int i = 0; i < this->capacity; i++){
		if(this->keys->get(i) != NULL && this->keys->get(i) != this->TOMBSTONE) cout << "Line " << i + 1 << ": " << *this->values->get(i) << endl;
		else cout << "Line " << i + 1 << ": NULL" << endl;
	}
}

#endif
