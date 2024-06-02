#include <iostream>
#include "../include/BST_Linkedlist.h"


LinkedlistBst::LinkedlistBst(){
	this->Root=nullptr;
}
LinkedlistBst::~LinkedlistBst(){
	delete Root;
}

bool LinkedlistBst::isEmpty(){
	if(this->Root==nullptr){
		return true;
	}
	return false;
}

void LinkedlistBst::addBST(int data){
	if(this->isEmpty()){
		Node *temp = new Node(data);
		this->Root=temp;
		return ;
	}
	else{
		Node *parent=this->Root;
		Node *toadd;
		if(data>this->Root->data){
			toadd=this->Root->right;
		}
		else{
			toadd=this->Root->left;
		}
		while(toadd!=nullptr){

				parent=toadd;
				if(data>toadd->data){
					toadd=toadd->right;
				}
				else{
					toadd=toadd->left;
				}
			}

		Node *temp = new Node(data,nullptr,nullptr,parent);
		if(data>parent->data){
			parent->right=temp;
		}
		else{
			parent->left=temp;
		}

	}

	return ;
}
void LinkedlistBst::checker(){
	std::cout<<this->Root->left->data;
}
void LinkedlistBst::removeBST(int dataToDelete) {
    Node* temp = Root;
    Node* parent = nullptr;

    // Find the node to delete
    while (temp != nullptr && temp->data != dataToDelete) {
        parent = temp;
        if (dataToDelete < temp->data) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }

    // If the node is not found
    if (temp == nullptr) {
        return; // Data not found, nothing to delete
    }

    // Case 1: Node has no children (leaf node)
    if (temp->left == nullptr && temp->right == nullptr) {
        if (parent == nullptr) {
            Root = nullptr; // Tree only had one node
        } else if (parent->left == temp) {
            parent->left = nullptr;
        } else {
            parent->right = nullptr;
        }
        delete temp;
    }
    // Case 2: Node has one child
    else if (temp->left == nullptr) { // Node has only right child
        if (parent == nullptr) {
            Root = temp->right;
        } else if (parent->left == temp) {
            parent->left = temp->right;
        } else {
            parent->right = temp->right;
        }
        delete temp;
    } else if (temp->right == nullptr) { // Node has only left child
        if (parent == nullptr) {
            Root = temp->left;
        } else if (parent->left == temp) {
            parent->left = temp->left;
        } else {
            parent->right = temp->left;
        }
        delete temp;
    }
    // Case 3: Node has two children
    else {
        Node* successor = temp->right;
        Node* successorParent = temp;

        // Find the in-order successor (leftmost child of right subtree)
        while (successor->left != nullptr) {
            successorParent = successor;
            successor = successor->left;
        }

        // Replace temp's data with successor's data
        temp->data = successor->data;

        // Fix the successor's parent
        if (successorParent != temp) {
            successorParent->left = successor->right;
        } else {
            successorParent->right = successor->right;
        }

        delete successor;
    }
}

bool LinkedlistBst::searchBST(int data){
	 Node* temp = Root;
    while (temp != nullptr) {
        if (data == temp->data) {
            return true;
        } else if (data < temp->data) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }
    return false;
}	
