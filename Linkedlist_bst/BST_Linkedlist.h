#ifndef BSt_linkedlist_h
#define BSt_linkedlist_h 

#include "../include/BST.h"
class Node
{
    public:
        int data;
        Node *left;
        Node *right;
        Node *parent;

        Node(){}
	~Node(){
	};
        Node(int d): data(d),left(nullptr),right(nullptr),parent(nullptr) {}
        Node(int d,Node *left,Node *right,Node *parent): data(d),left(left),right(right),parent(parent) {}
};
class LinkedlistBst : public BST{
  public:
    LinkedlistBst();
    ~LinkedlistBst();

    bool isEmpty();
    void addBST(int data);
    void checker();
    bool removeBST(int data);
    bool searchBST(int targetkey);
  private:
    Node *Root;
};

#endif

