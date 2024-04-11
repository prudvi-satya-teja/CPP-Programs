#include<bits/stdc++.h>
#include<queue>

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

//height of tree
int height(Node* root) {
    if(root == NULL) {
        return 0;
    }
    
    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh, rh) + 1;
}

// diameter of a tree - Approach 1  // O(n^2)
int diameter2(Node* root) {
    if(root == NULL) {
        return 0;
    }
    
    int leftdiam = diameter2(root->left);
    int leftht = height(root->left);
    int rightdiam = diameter2(root->right);
    int rightht = height(root->right);
    
    int selfdiam = leftht + rightht + 1;
    
    return max(selfdiam, max(leftdiam, rightdiam));
}

class Info {
public:
    int diam;
    int ht;
    
    Info(int diam, int ht) {
        this->diam = diam;
        this->ht = ht;
    }
};

// diameter of a tree - Approach 2 // O(n)
Info diameter(Node* root) {
    if(root == NULL) {
        return Info(0, 0);
    }
    
    Info leftInfo = diameter(root->left);
    Info rightInfo = diameter(root->right);
    
    int diam = max(max(leftInfo.diam, rightInfo.diam), leftInfo.ht + rightInfo.ht + 1);
    int ht = max(leftInfo.ht, rightInfo.ht) + 1;
    
    return Info(diam, ht);
}


//sum of nodes
int sumOfNodes(Node* root) {
    if(root == NULL) {
        return 0;
    }
    
    int leftSum = sumOfNodes(root->left);
    int rightSum = sumOfNodes(root->right);
    
    return leftSum + rightSum + root->data;
}

//count of nodes
int count(Node* root) {
    if(root == NULL) {
        return 0;
    }
    
    int leftcount = count(root->left);
    int rightcount = count(root->right);
    
    return leftcount + rightcount + 1;
}

int main() {
    Node* root = new Node(1);
    root->right = new Node(2);
    root->left = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    cout << "Height of the tree: " << height(root) << endl;
    cout << "Diameter of the tree (Approach 2): " << diameter2(root) << endl;
    Info info = diameter(root);
    cout << "Diameter of the tree (Approach 3): " << info.diam << endl;
    cout << "Sum of all nodes: " << sumOfNodes(root) << endl;
    cout << "Count of all nodes: " << count(root) << endl;
    
    return 0;
}
