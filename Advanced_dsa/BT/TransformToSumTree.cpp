#include<bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};




int  transform(Node* root) {

    if(root == NULL) {
        return 0;
    }

    int leftChild = transform(root->left);
    int rightChild = transform(root->right);

    int data = root->data;

     int newLeft = 0, newRight = 0;

    if(root->left != NULL) {
      newLeft = root->left->data;
    } 

    if(root->right != NULL) {
        newRight = root->right->data;
    }   
    

    root->data = newLeft + newRight + leftChild + rightChild;

    return data;

}

void preorder (Node * root) {
    if(root == NULL) {
        return;
    }

    cout<<root->data<< endl;
    preorder(root->left);
    preorder(root->right);

}


int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    transform(root);

    preorder(root);
}