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

// loweest commmon ancestor (approach - 2)
Node* lca2(Node* root, int n1, int n2) {
    if(root == NULL || root->data == n1 || root->data == n2 ) {
        return root;
    }

    Node* leftLca = lca2(root->left, n1, n2);
    Node* rightLca = lca2(root->right, n1, n2);

    // leftLCA = val rightlca = null
    if(rightLca == NULL) {
        return leftLca;
    }

    if(leftLca == NULL) {
        return rightLca;
    }

    return root;
}


// minimum distance between nodes
int lcaDist(Node* root, int n) {
    if(root == NULL) {
        return -1;
    }

    if(root->data == n) {
        return 0;
    }

    int leftDist = lcaDist(root->left,n);
    int rightDist = lcaDist(root->right, n);

    if(leftDist == -1 && rightDist == -1) {
        return -1;
    } 
    else if(leftDist == -1) {
        return rightDist+1;
    } 
    else {
        return leftDist + 1;
    }
}

int minDist(Node* root, int n1, int n2) {
    Node *lca = lca2(root,n1,n2);
    int dist1 = lcaDist(lca, n1);
    int dist2 = lcaDist(lca, n2);
    return dist1 + dist2;
}


int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // min distance between nodes
     int n1 = 4, n2 = 7;
    cout<<minDist(root, n1, n2)<<endl;

    

    return 0;
}
