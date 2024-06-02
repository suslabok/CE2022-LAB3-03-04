 #pragma once

class BST {
public:
    virtual bool isEmpty() = 0;
    virtual void addBST(int key) = 0;
    virtual bool removeBST(int keyToDelete) = 0;
    virtual bool searchBST(int targetKey) = 0;
};
