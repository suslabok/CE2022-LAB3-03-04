#include "BST.h"
struct ArrayNode{
    int key;
    int value;
    ArrayNode(int key,int value):key(key),value(value){}
};

class ArrayBST:public BST{
    private:
    ArrayNode* nodes [MAX_NUM_NODES];
    public:
    ArrayBST();
    ~ArrayBST();
    bool isEmpty();
    void addBST();
    void removeBST();
};