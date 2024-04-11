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

class Info {
    
    public:
    bool isBST;
    int size;
    int mn;
    int mx;

    Info(bool isBST, int size, int mn,int mx) {
        this->isBST = isBST;
        this->size = size;
        this->mn = mn;
        this->mx  = mx;
        
    }
};
static int maxBST = 0;

Info* largestBST(Node* root) {

    if(root == NULL) {
        return new Info(true, 0, 1000, -1000);
    }

    Info* leftInfo = largestBST(root->left);
    Info* rightInfo = largestBST(root->right);
    int size = leftInfo->size + rightInfo->size + 1;
    int mn = min(root->data, min(leftInfo->mn, rightInfo->mn));
    int mx = max(root->data, max(leftInfo->mx, rightInfo->mx));

    if(root->data <= leftInfo->mx || root->data >= rightInfo->mn) {
        return new Info(false, size, mn, mx);
    }

    if(leftInfo->isBST && rightInfo->isBST) {
        maxBST = max(maxBST, size);
        return new Info(true,size,mn, mx);
    }
    
    return new Info(false, size, mn, mx);
}

int main() {
    
    /*              50
//                /    \
//               30      60
//             /   \     / \
//            5     20  45  70
                            / \
                          65   80
//            */
   
 
    Node* root = new Node(50);

    root->left = new Node(30);
    root->right = new Node(60);

    root->left->left = new Node(5);
    root->left->right = new Node(20);

    root->right->left = new Node(45);
    root->right->right = new Node(70);
    root->right->right->left = new Node(65);
    root->right->right->right = new Node(80);

     /*                  60
                        / \
                      45  70
                         / \
                        65   80
                          Expected BST size = 5
                        */
    Info* info = largestBST(root);
    cout<<"largest BST size " << maxBST<<endl;
  
}
