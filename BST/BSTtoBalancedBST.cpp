#include<iostream>
#include<vector>
using namespace std;

class Node {
  public: 
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void preOrder(Node * root) {
  if(root == NULL) {
    return;
  }

  cout<<root->data<< " ";
  preOrder(root->left);
  preOrder(root->right);
}

void getInOrder(Node* root, vector<int>& inorder) {
    if(root == NULL) {
        return;
    }

    getInOrder(root->left, inorder);
    inorder.push_back(root->data);
    getInOrder(root->right, inorder);

}

Node* createBST(vector<int> inorder, int st, int end) {
    if(st > end) {
        return NULL;
    }
    int mid = (st+end) /2;
    Node* root= new Node(inorder[mid]);
    root->left = createBST(inorder,st, mid-1);
    root->right = createBST(inorder,mid+1, end);
    return root;

}

Node*  balanceBST(Node* root) {
    //inorder seq
    vector<int> inorder ;
    getInOrder(root, inorder);

    //sorted inorder to balanced BST
    root = createBST(inorder,0, inorder.size()-1);
    return root;

}

int main() {
    
    /*              8
//                /    \
//               6      10
//             /         \
//            5           11
            /               \
           3                 12
//            */
   
 
    Node* root = new Node(8);
    root->left = new Node(6);
    root->left->left = new Node(5);
    root->left->left->left = new Node(3);

    root->right = new Node(10);
    root->right->right = new Node(11);
    root->right->right->right = new Node(12);

    /*                8
//                /    \
//               5     11
//             /  \   /  \
//            3    6  10    12
//            */
   
     root = balanceBST(root);
     preOrder(root);
  
}
