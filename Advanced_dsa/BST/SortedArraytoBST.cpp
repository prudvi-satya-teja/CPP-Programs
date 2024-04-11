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


Node* createBST(int arr[], int st, int end) {
    if(st > end) {
        return NULL;
    }
    int mid = (st+end) /2;
    Node* root= new Node(arr[mid]);
    root->left = createBST(arr,st, mid-1);
    root->right = createBST(arr,mid+1, end);
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
  /*                8
//                /    \
//               5     11
//             /  \   /  \
//            3    6  10    12
//            */
   
   int arr[] = {3, 5, 6, 8, 10, 11, 12};
   Node * root = createBST(arr, 0, 6);
   preOrder(root);
   
  
}
