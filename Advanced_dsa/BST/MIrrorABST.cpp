#include<iostream>
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

Node* createMirror(Node*& root) {
  if(root == NULL) {
    return NULL;
  }

  Node* leftMirror = createMirror(root->left);
  Node* rightMirror = createMirror(root->right);

  root->left = rightMirror;
  root->right = leftMirror;

  return root;
}

void preOrder(Node * root) {
  if(root == NULL) {
    return;
  }

  cout<<root->data<< " ";
  preOrder(root->left);
  preOrder(root->right);
}

int main() {
  /*          8
//                / \
//               5   10
//             /  \    \
//            3    6    11
//            */
    
    Node* root = new Node(8);

    root->left = new Node(5);
    root->right = new Node(10);

    root->left->left = new Node(3);
    root->left->right = new Node(6);

    root->right->right = new Node(11);

    root->left->left->left = new Node(1);
    root->left->left->right = new Node(4);

    root->right->right->right = new Node(14);

     cout << "Original Tree (Preorder traversal):" << endl;
    preOrder(root);
    cout << endl;

    Node* root1 = createMirror(root);
    
    cout << "Mirror Tree (Preorder traversal):" << endl;
    preOrder(root1);
    cout << endl;

    return 0;
       /*        8
//                / \
//               10  5
//             /    / \
//            11   6   3
//            */ 

    
}
