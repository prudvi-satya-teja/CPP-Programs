#include <iostream>

using namespace std;

// Definition of a Node in a binary tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Print nodes at k-th level of the tree
void KthLevel(Node* root, int k, int level) {
    if (root == nullptr) {
        return;
    }

    if (level == k) {
        cout << root->data << " ";
        return;
    }

    KthLevel(root->left, k, level + 1);
    KthLevel(root->right, k, level + 1);
}

int main() {
    /*
                1
               / \
              2   3
             / \ / \
            4  5 6  7  
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    KthLevel(root, 2, 1);

    return 0;
}
