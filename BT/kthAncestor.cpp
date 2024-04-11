#include <iostream>
#include <vector>
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

// kth ancestor of a node 
int kAncestor(Node* root, int n, int k) {
    if (root == NULL) {
        return -1;
    }

    if(root->data == n) {
        return 0;
    }

    int leftDist = kAncestor(root->left, n,  k);
    int rightDist = kAncestor(root->right, n, k);

    if(leftDist == -1 && rightDist == -1) {
        return -1;
    }

    int mx = max(leftDist, rightDist);

    if(mx+1 == k) {
        cout<< root->data << endl;
    }

    return mx+1;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

   
    // kth ancestor of a node
    int n = 4, k= 2;
    kAncestor(root, n, k);

    return 0;
}
