#include <iostream>
#include <stdlib.h>

class UnionFind{
	private:
		int size_;
		int numComp;
		int * compSize; //Sizes of each component
		int * id; //Parent IDs of each component. If parent ID of a component equals to its ID, it is a root node.
	public:
		int find(int p); //Finds root of element 'p'
		bool connected(int p, int q); //Compares roots of elements 'p' and 'q'
		int componentSize(int p); //Size of component/set
		int size(void); //Number of elements in Union Find set
		int components(void); //Number of components/sets in Union Find set
		void unify(int p, int q); //Unify components/sets containing elements 'p' and 'q'
		
		UnionFind(int size);
};
