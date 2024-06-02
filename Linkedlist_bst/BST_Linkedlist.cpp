#include <iostream>
#include "BST_Linkedlist.h"


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
bool LinkedlistBst::removeBST(int dataToDelete)
{
    Node* temp = Root;
    Node* parent = nullptr;
    while (temp != nullptr && temp->data != dataToDelete) {
        parent = temp;
        if (dataToDelete < temp->data) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }

    if (temp == nullptr) {
        return false; // data not found
    }

    if (temp->left == nullptr && temp->right == nullptr) {
        if (parent == nullptr) {
            Root = nullptr;
        } else if (parent->left == temp) {
            parent->left = nullptr;
        } else {
            parent->right = nullptr;
        }
        delete temp;
    }
    // Case 2: Node has one child
    else if (temp->left == nullptr) {
        if (parent == nullptr) {
            Root = temp->right;
        } else if (parent->left == temp) {
            parent->left = temp->right;
        } else {
            parent->right = temp->right;
        }
        delete temp;
    } else if (temp->right == nullptr) {
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
        while (successor->left != nullptr) {
            successorParent = successor;
            successor = successor->left;
        }

        if (successorParent != temp) {
            successorParent->left = successor->right;
        } else {
            successorParent->right = successor->right;
        }

        temp->data = successor->data;
        delete successor;
    }

    return true;
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
