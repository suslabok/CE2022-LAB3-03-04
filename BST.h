#pragma once
class BST{
public:
virtual bool isEmpty()=0;
virtual void addBST(int data)=0;
virtual void removeBST(int data)=0;
virtual bool searchBST(int targetkey)=0;
};