#include <iostream>
#include <stdlib.h>
#include "BinarySearchTree.hpp"

using namespace std;

int main(){
	BinarySearchTree<int> b = BinarySearchTree<int>(6);
	
	b.addNode(5);
	b.addNode(10);
	b.addNode(3);
	b.addNode(4);
	b.addNode(7);
	b.addNode(13);
	b.addNode(9);
	b.addNode(12);
	b.addNode(17);
	b.addNode(1);
	b.addNode(2);
	b.addNode(0);
		
	b.printTree();
	
	b.removeNode(13);
	
	cout << "After removal of 13" << endl << endl;
	
	b.printTree();
	
	b.removeNode(6);
	
	cout << "After removal of 6" << endl << endl;
	
	b.printTree();
	
	return 1;
}
