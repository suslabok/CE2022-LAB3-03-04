 #pragma once

class Node {
public:
    Node(int key) : key(key), left(nullptr), right(nullptr), value(0) {}

    int key;
    Node* left;
    Node* right;
    int value; 
};

class BST {
public:
    virtual bool isEmpty() = 0;
    virtual void addBST(int key) = 0;
    virtual void removeBST(int keyToDelete) = 0;
    virtual bool searchBST(int targetKey) = 0;
    Node* head;
};