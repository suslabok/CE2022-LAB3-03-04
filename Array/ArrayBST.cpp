#include <iostream>
#include "ArrayBST.h"

Array::Array(int size) : size(size) {
    tree = new int[size];
    for (int i = 0; i < size; ++i) {
        tree[i] = INT_MAX;   
    }
}

Array::~Array() {
    delete[] tree;
}

bool Array::isEmpty() {
    return this->tree[1] == INT_MAX;   
}

void Array::addBST(int key) {
    int i = 1;
    while (i < size && this->tree[i] != INT_MAX) {  // Use INT_MAX instead of _INT_MAX_
        if (key < this->tree[i]) {
            i = 2 * i;
        } else {
            i = 2 * i + 1;
        }
    }
    if (i < size) {
        this->tree[i] = key;
    } else {
        std::cerr << "Error: Array is full or index out of bounds" << std::endl;
    }
}

void Array::removeBST(int valueToDelete) {
    int i = 1;
    while (i < size && this->tree[i] != valueToDelete) {
        if (valueToDelete < this->tree[i]) {
            i = 2 * i;
        } else {
            i = 2 * i + 1;
        }
    }
    if (i < size && this->tree[i] == valueToDelete) {
        if (this->tree[2 * i] == INT_MAX && this->tree[2 * i + 1] == INT_MAX) {
            this->tree[i] = INT_MAX;
        } else if (this->tree[2 * i] == INT_MAX) {
            this->tree[i] = this->tree[2 * i + 1];
            this->tree[2 * i + 1] = INT_MAX;
        } else if (this->tree[2 * i + 1] == INT_MAX) {
            this->tree[i] = this->tree[2 * i];
            this->tree[2 * i] = INT_MAX;
        } else {
            int j = 2 * i + 1;
            while (this->tree[2 * j] != INT_MAX) {
                j = 2 * j;
            }
            this->tree[i] = this->tree[j];
            this->tree[j] = INT_MAX;
        }
    }
}

bool Array::searchBST(int targetValue) {
    int i = 1;
    while (i < size && this->tree[i] != targetValue) {
        if (targetValue < this->tree[i]) {
            i = 2 * i;
        } else {
            i = 2 * i + 1;
        }
    }
    return i < size && this->tree[i] == targetValue;
}
