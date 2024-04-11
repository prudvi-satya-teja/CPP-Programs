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

bool isIdentical(Node* node, Node* subroot) {
    if (node == NULL && subroot == NULL) {
        return true;
    }
    else if (node == NULL || subroot == NULL || node->data != subroot->data) {
        return false;
    }
    
    if (!isIdentical(node->left, subroot->left)) {
        return false;
    }
    if (!isIdentical(node->right, subroot->right)) {
        return false;
    }
    return true;
}

bool isSubtree(Node* root, Node* subroot) {
    if (root == NULL) {
        return false;
    }
    
    if (root->data == subroot->data) {
        if (isIdentical(root, subroot)) {
            return true;
        }
    }
    return (isSubtree(root->left, subroot) || isSubtree(root->right, subroot));
}

int main() {
    Node* root = new Node(1);
    root->right = new Node(2);
    root->left = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    Node* subroot = new Node(3);
    subroot->left = new Node(4);
    subroot->right = new Node(5);
    
    cout << "Is subtree: " << (isSubtree(root, subroot) ? "true" : "false") << endl;
    
    return 0;
}