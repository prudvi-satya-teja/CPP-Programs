#include <iostream>

using namespace std;

// Definition of a Node in a binary tree
struct Node {
    int data;


    Node* left;
    Node* right;

    Node(int val) {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to check if two binary trees rooted at node1 and node2 are identical
bool isIdentical(Node* node1, Node* node2) {
    if (node1 == NULL && node2 == NULL)
        return true;

    if (node1 == NULL || node2 == NULL || node1->data != node2->data)
        return false;

    return isIdentical(node1->left, node2->left) && isIdentical(node1->right, node2->right);
}

// Function to check if node2 is a subtree of node1
bool isSubTree(Node* node1, Node* node2) {
    if (node2 == NULL)
        return true;

    if (node1 == NULL)
        return false;

    if (isIdentical(node1, node2))
        return true;

    return isSubTree(node1->left, node2) || isSubTree(node1->right, node2);
}

int main() {
    // Root node creation
    Node* root = new Node(1);
    root->right = new Node(3);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    max(5,6);

    // Subroot node creation
    Node* subroot = new Node(2);
    subroot->right = new Node(5);
    subroot->left = new Node(4);

    // Check if subroot is a subtree of root
    if (isSubTree(root, subroot))
        cout << "Subroot is a subtree of root." << endl;
    else
        cout << "Subroot is not a subtree of root." << endl;

    

    return 0;
}

