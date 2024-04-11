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

void getInorder(Node* root, vector<int>& arr) {
    if(root == NULL) {
        return;
    }

    getInorder(root->left,arr);
    arr.push_back(root->data);
    getInorder(root->right,arr);
}

Node* createBST(vector<int>& arr, int st, int end) {
    if(st > end) {
        return NULL;
    }

    int mid = (st+end) /2;
    Node* root  = new Node(arr[mid]);
    root->left = createBST(arr,st,mid-1);
    root->right = createBST(arr,mid+1, end);
    return root;

}

Node* mergeBSTs(Node* root1, Node* root2) {
    // step1
    vector<int> arr1;
    getInorder(root1, arr1);

    //step2
    vector<int> arr2;
    getInorder(root2, arr2);

    //step3 merge
    int i=0, j=0;
    vector<int> finalarr;
    while(i<arr1.size() && j<arr2.size()) {
        if(arr1[i] <= arr2[j]) {
            finalarr.push_back(arr1[i]);
            i++;
        } else {
            finalarr.push_back(arr2[j]);
            j++;
        }
    }

    while(i<arr1.size()) {
        finalarr.push_back(arr1[i]);
        i++;
    }
    while(j<arr2.size()) {
        finalarr.push_back(arr2[j]);
        j++;
    }


    //step : 4
    return createBST(finalarr,0, finalarr.size()-1);
    

}

void preorder(Node* root) {
    if(root == NULL){
           return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    
}

int main() {
    
    /*              2
//                /    \
//               1      4
//                BST 2
//            
//            */
   
 
    Node* root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(4);


     /*                  9
                        / \
                      3    12
                      BST 1: 
                       
                        */
    Node* root2 = new Node(9);
    root2->left = new Node(3);
    root2->right = new Node(12);

 /*                      3
                        /  \
                      1     9
                       \   / \
                        2 4  12
                          final BST
                        */

    Node* root = mergeBSTs(root1, root2);
    preorder(root);
   
  
}
