#include "../include/BST_Linkedlist.h"
#include <iostream>
using namespace std;
int main(){
	LinkedlistBst l;
	l.addBST(45);
	l.addBST(34);
	l.addBST(55);
	l.addBST(42);
	l.removeBST(42);
	std::cout<<l.searchBST(45);
	cout<<l.isEmpty();
	return 0;
}
