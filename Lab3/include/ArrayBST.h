#ifndef ARRAY_BST_H
#define ARRAY_BST_H

#include <climits>
#include "../include/BST.h"

class Array : public BST {
private:
    int size;
    int* tree;

public:
    Array(int size);
    ~Array();

    virtual bool isEmpty();
    virtual void addBST(int key);
    virtual void removeBST(int keyToDelete);
    virtual bool searchBST(int targetKey);
};

#endif // ARRAY_BST_H
