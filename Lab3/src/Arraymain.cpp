#include "../include/BST.h"
#include <iostream>
#include "../include/ArrayBST.h"

int main() {
    BST* bst = new Array(31);

    std::cout << "Is the tree empty? " << (bst->isEmpty() ? "Yes" : "No") << std::endl;

    bst->addBST(2);
    bst->addBST(7);
    bst->addBST(12);
    bst->addBST(20);
    bst->addBST(1);
    bst->addBST(3);
    bst->addBST(6);

    std::cout << "Is the tree empty? " << (bst->isEmpty() ? "Yes" : "No") << std::endl;
    bst->removeBST(2);
    bst->removeBST(7);

    std::cout << "Is the tree empty? " << (bst->isEmpty() ? "Yes" : "No") << std::endl;

    std::cout << "Searching for 1: " << (bst->searchBST(1) ? "Found" : "Not Found") << std::endl;
    std::cout << "Searching for 7: " << (bst->searchBST(7) ? "Found" : "Not Found") << std::endl;

    // Clean up memory
    delete bst;
    return 0;
}
