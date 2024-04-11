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

Node* insert(Node*& root , int val) {
    if(root == NULL) {
        root = new Node(val);
        return root;
    }

    if(root->data > val) {
        //left Subtree
        root->left = insert(root->left, val);
    } else {
        // right Subtree
        root->right = insert(root->right,val);
    }
    return root;
}

void inorder(Node* root) {
    if(root == NULL) {
        return;
    }

    inorder(root->left);
    cout<<(root->data)<<" ";
    inorder(root->right);
}




int main() {
    int values[] = {5, 1, 3, 4, 2, 7};
    Node* root = NULL;

    for(int i=0; i<6; i++) {
        root = insert(root,values[i]);
    }
    inorder(root);
    
}