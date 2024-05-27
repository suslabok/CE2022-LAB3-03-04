#include "../include/BST.h"
#include <iostream>
#include "ArrayBST.h"

int main() {
    BST* bst = new Array(31);
    std::cout << bst->isEmpty() << std::endl;

    bst->addBST(10);
    bst->addBST(5);
    bst->addBST(15);
    bst->addBST(2);
    bst->addBST(7);
    bst->addBST(12);
    bst->addBST(20);
    bst->addBST(1);
    bst->addBST(3);
    bst->addBST(6);

    bst->removeBST(5);
    bst->removeBST(15);

    std::cout << bst->isEmpty() << std::endl;

    std::cout << bst->searchBST(10) << std::endl;
    std::cout << bst->searchBST(5) << std::endl;

    delete bst;
    return 0;
}
